//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_ROOM_H
#define ESCAPEROOM2_0_ROOM_H


#include <vector>

class Room
{
public:
    Room();

    int GetWidth() const { return width;}
    int GetHeight() const { return height;}

    void Initialize(const int& width, const int& height);

private:
    int width = 0;
    int height = 0;

    // Using a 2d vector to represent the room. Instead of a 2d array.
    std::vector<std::vector<int>> room;

    void SetRoomSize(const int& width, const int& height);
    void DrawRoom() const;
};

#endif //ESCAPEROOM2_0_ROOM_H
