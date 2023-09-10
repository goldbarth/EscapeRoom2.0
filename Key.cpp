//
// Created by goldbarth on 07.09.2023.
//

#include "Key.h"

Key::Key(Room* room) : room(room), xPos(0), yPos(0)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Key::Initialize(char key)
{
    SetRandomPosition();
    DrawKey(key);
}

void Key::DrawKey(char key)
{
    std::cout << "\x1B[33m"; // Set text color to dark yellow
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             { static_cast<SHORT>(xPos), static_cast<SHORT>(yPos) }); // Set cursor position using SetCursorPos
    std::cout << key;
    std::cout << "\x1B[0m"; // Reset text color
}

void Key::SetRandomPosition()
{
    xPos = std::rand() % (room->GetWidth() - 1) + 1;
    yPos = std::rand() % (room->GetHeight() - 1) + 1;
}

int Key::GetXPos()
{
    return xPos;
}

int Key::GetYPos()
{
    return yPos;
}

