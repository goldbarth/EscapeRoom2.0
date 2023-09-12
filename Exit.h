//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_EXIT_H
#define ESCAPEROOM2_0_EXIT_H

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>
#include "Room.h"


class Room;

class Exit
{
public:
    explicit Exit(Room& room);
    inline ~Exit() = default;

    [[nodiscard]] inline int GetXPos() const { return xPos; }
    [[nodiscard]] inline int GetYPos() const { return yPos; }

    void Initialize(const char& exit);
    void DrawExit(const char& exit) const;

private:
    Room& room;

    int xPos;
    int yPos;

    void SetRandomPosition();
};

#endif //ESCAPEROOM2_0_EXIT_H
