//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Room.h"

#ifndef ESCAPEROOM2_0_KEY_H
#define ESCAPEROOM2_0_KEY_H

class Room;

class Key
{
public:
    explicit Key(Room* room);

    int GetXPos();
    int GetYPos();

    void SetXPos(int pos);
    void SetYPos(int pos);

    void DrawPosition(char key);

private:
    int xPos;
    int yPos;
    Room* room;

    void DrawKey(char key);
    void SetRandomPosition();
};



#endif //ESCAPEROOM2_0_KEY_H
