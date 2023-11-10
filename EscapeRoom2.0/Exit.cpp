//
// Created by goldbarth on 07.09.2023.
//

#include <cstdlib>
#include <ctime>
#include "csptr.h"
#include "Game.h"
#include "Exit.h"

Exit::Exit(Room& room) : room(&room)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

Exit::~Exit()
= default;

/// <summary>
/// Handles the initialization of the exit.
/// Set the argument to draw the exit open or closed.
/// </summary>
void Exit::Initialize(const bool& open)
{
    SetRandomPosition();
    DrawExit(open);
}

void Exit::DrawExit(const bool& open) const
{
    Game::CharType charType;
    csptr::WriteAt(xPos, yPos, charType.floor,open ? Color::BgReset : Color::BgGray);
}

void Exit::SetRandomPosition()
{
    xPos = room->GetWidth() + 1;
    yPos = rand() % (room->GetHeight() - 1) + 2;
}



