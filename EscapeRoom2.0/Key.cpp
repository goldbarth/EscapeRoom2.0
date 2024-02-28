//
// Created by goldbarth on 07.09.2023.
//

#include <cstdlib>
#include <ctime>
#include "Key.h"

#include "cwtr.h"

Key::Key(Room& room) : pRoom(&room)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Key::Initialize(const char& object)
{
    SetRandomPosition();
    DrawKey(object);
}

void Key::DrawKey(const char& key) const
{
    cwtr::WriteAt(xPos, yPos, key, Color::Yellow);
}

void Key::SetRandomPosition()
{
    xPos = std::rand() % (pRoom->GetWidth() - 1) + 1;
    yPos = std::rand() % (pRoom->GetHeight() - 1) + 1;
}

