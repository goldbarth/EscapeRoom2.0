//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Room.h"

#ifndef ESCAPEROOM2_0_EXIT_H
#define ESCAPEROOM2_0_EXIT_H

class Room;

class Exit
{
public:
    explicit Exit(Room* room);

    int GetXPos();
    int GetYPos();

    void Initialize(char exit);
    void DrawExit(char exit);

private:
    Room* room;
    int xPos;
    int yPos;

    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_EXIT_H
