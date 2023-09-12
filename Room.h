//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_ROOM_H
#define ESCAPEROOM2_0_ROOM_H

#include <Windows.h>
#include <iostream>
#include <vector>
#include "Game.h"


class Room
{
public:
    Room();

    inline int GetWidth() const { return width;}
    inline int GetHeight() const { return height;}

    void Initialize(const int& width, const int& height, const char& wall, const char& floor);

private:
    int width;
    int height;

    // Using a 2d vector to represent the room. Instead of a 2d array.
    std::vector<std::vector<int>> room;

    void SetRoomSize(const int& width, const int& height);
    void DrawRoom(const char& wall, const char& floor);
};

#endif //ESCAPEROOM2_0_ROOM_H
