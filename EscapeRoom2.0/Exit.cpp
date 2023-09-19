//
// Created by goldbarth on 07.09.2023.
//

#include "Exit.h"

Exit::Exit(Room& room) : room(room), xPos(0), yPos(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

/// <summary>
/// Handles the initialization of the exit.
/// Set the argument to draw the exit open or closed.
/// </summary>
void Exit::Initialize(const bool& open)
{
    SetRandomPosition();
    DrawExit(false);
}

void Exit::DrawExit(const bool& open) const
{
    Game::CharType charType;
    csptr::WriteAt(xPos, yPos, charType.floor,open ? Color::BgReset : Color::BgGray);
}

void Exit::SetRandomPosition()
{
    xPos = room.GetWidth() + 1;
    yPos = rand() % (room.GetHeight() - 1) + 2;
}



