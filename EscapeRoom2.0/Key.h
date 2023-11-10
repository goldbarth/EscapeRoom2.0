//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_KEY_H
#define ESCAPEROOM2_0_KEY_H


#include "Room.h"

class Room;

class Key
{
public:
    explicit Key(Room& room);
    ~Key();

    int GetXPos() const { return xPos; }
    int GetYPos() const { return yPos; }

    void Initialize(const char& key);

private:
    std::unique_ptr<Room> room;

    int xPos = 0;
    int yPos = 0;

    void DrawKey(const char& key) const;
    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_KEY_H
