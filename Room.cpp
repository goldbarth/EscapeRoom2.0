//
// Created by goldbarth on 07.09.2023.
//

#include "Room.h"

void Room::Initialize(int width, int height, char wall, char floor)
{
    SetRoomSize(width, height);
    DrawRoom(wall, floor);
}

void Room::SetRoomSize(int width, int height)
{
    this->width = width;
    this->height = height;

    room.resize(width, std::vector<int>(height, 0));
}

void Room::DrawRoom(char wall, char floor)
{
    for (int y = -1; y < height + 1; y++)
    {
        for (int x = -1; x < width + 1; x++)
        {
            // first
            if (y == -1 || x == -1 || y == height || x == width)
            {
                std::cout << wall;
            }
            else
            {
                int current = room[x][y];
                if (current == 0) {
                    std::cout << floor;
                }
            }
        }

        std::cout << std::endl;
    }
}


int Room::GetWidth() const
{
    return width;
}

int Room::GetHeight() const
{
    return height;
}

Room::Room() : width(0), height(0) {}
