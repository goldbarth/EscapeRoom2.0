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

    void SetXPos(int pos);
    void SetYPos(int pos);

    void DrawPosition(char exit);

private:

    int xPos;
    int yPos;
    Room* room;

    void DrawExit(char exit);
    void SetRandomPosition();
};


#endif //ESCAPEROOM2_0_EXIT_H
