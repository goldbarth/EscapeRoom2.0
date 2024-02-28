//
// Created by goldbarth on 07.09.2023.
//

#include <cstdlib>
#include <ctime>
#include "cwtr.h"
#include "Game.h"
#include "Exit.h"

Exit::Exit(Room& room) : pRoom(&room)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Exit::Initialize(const char& object)
{
    SetRandomPosition();
    DrawExit(object);
}

void Exit::DrawExit(const bool& open) const
{
    constexpr Game::CharType charType;
    cwtr::WriteAt(xPos, yPos, charType.floor,open ? Color::BgReset : Color::BgGray);
}

void Exit::SetRandomPosition()
{
    xPos = pRoom->GetWidth() + 1;
    yPos = rand() % (pRoom->GetHeight() - 1) + 2;
}





