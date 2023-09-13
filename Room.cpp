//
// Created by goldbarth on 07.09.2023.
//

#include "Room.h"

Room::Room() : width(0), height(0) {}

void Room::Initialize(const int& width, const int& height, const char& wall, const char& floor)
{
    SetRoomSize(width, height);
    DrawRoom();
}

void Room::SetRoomSize(const int& width, const int& height)
{
    this->width = width;
    this->height = height;

    room.resize(width, std::vector<int>(height, 0));
}


void Room::DrawRoom()
{
    for (int y = -1; y < height + 1; y++)
    {
        for (int x = -1; x < width + 1; x++)
        {
            // first
            if (y == -1 || x == -1 || y == height || x == width)
            {
                csptr::Write(' ', Color::BgDarkGray);
            }
            else
            {
                int current = room[x][y];
                if (current == 0)
                {
                    csptr::Write(' ', Color::BgReset);
                }
            }
        }

        std::cout << std::endl;
    }
}
