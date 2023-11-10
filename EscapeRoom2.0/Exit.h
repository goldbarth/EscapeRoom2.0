//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_EXIT_H
#define ESCAPEROOM2_0_EXIT_H


#include "Room.h"

class Room;

class Exit
{
public:
    explicit Exit(Room& room);
    ~Exit();

    
    int GetXPos() const { return xPos; }
    
    int GetYPos() const { return yPos; }

    void Initialize(const bool& open);
    void DrawExit(const bool& open) const;

private:
    std::unique_ptr<Room> room;

    int xPos = 0;
    int yPos = 0;

    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_EXIT_H
