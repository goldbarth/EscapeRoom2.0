//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_KEY_H
#define ESCAPEROOM2_0_KEY_H

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>

class Room;

class Key
{
public:
    explicit Key(Room& room);
    inline ~Key() = default;

    int GetXPos() const;
    int GetYPos() const;

    void Initialize(char key);

private:
    Room& room;

    int xPos;
    int yPos;

    void DrawKey(char key);
    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_KEY_H
