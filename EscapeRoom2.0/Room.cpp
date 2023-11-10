//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>

#include "csptr.h"
#include "Room.h"

Room::Room() = default;

void Room::Initialize(const int& roomWidth, const int& roomHeight)
{
    SetRoomSize(roomWidth, roomHeight);
    DrawRoom();
}

void Room::SetRoomSize(const int& roomWidth, const int& roomHeight)
{
    this->width = roomWidth;
    this->height = roomHeight;

    room.resize(roomWidth, std::vector<int>(roomHeight, 0));
}

void Room::DrawRoom() const
{
    for (int y = -1; y < height + 1; y++)
    {
        for (int x = -1; x < width + 1; x++)
        {
            constexpr char floor = ' ';
            if (y == -1 || x == -1 || y == height || x == width)
            {
                csptr::Write(floor, Color::BgDarkGray);
            }
            else
            {
                int current = room[x][y];
                if (current == 0)
                {
                    csptr::Write(floor, Color::BgReset);
                }
            }
        }

        std::cout << std::endl;
    }
}
