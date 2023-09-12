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
#include "Room.h"


class Room;

class Key
{
public:
    explicit Key(Room& room);
    inline ~Key() = default;

    inline int GetXPos() const { return xPos; }
    inline int GetYPos() const { return xPos; }

    void Initialize(const char& key);

private:
    Room& room;

    int xPos;
    int yPos;

    void DrawKey(const char& key) const;
    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_KEY_H
