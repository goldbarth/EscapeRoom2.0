//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <vector>
#include "Game.h"

#ifndef ESCAPEROOM2_0_ROOM_H
#define ESCAPEROOM2_0_ROOM_H

class Room
{
public:
    int GetWidth();
    int GetHeight();

    void Initialize(int width, int height, char wall, char floor);

private:
    int width;
    int height;

    // Using a 2d vector to represent the room. Instead of a 2d array.
    std::vector<std::vector<int>> room;

    void SetRoomSize(int width, int height);
    void DrawRoom(char wall, char floor);
};

#endif //ESCAPEROOM2_0_ROOM_H
