//
// Created by goldbarth on 07.09.2023.
//

#include "Exit.h"

Exit::Exit(Room *room) : room(room), xPos(0), yPos(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Exit::DrawPosition(char exit)
{
    SetRandomPosition();
    DrawExit(exit);
}

void Exit::DrawExit(char exit)
{
    std::cout << "\x1B[31m"; // Set text color to dark red
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             { static_cast<SHORT>(xPos), static_cast<SHORT>(yPos) }); // Set cursor position using SetCursorPos
    std::cout << exit;
    std::cout << "\x1B[0m"; // Reset text color
}

void Exit::SetRandomPosition()
{
    int randomPositionY = rand() % (room->GetHeight() - 1) + 2;

    xPos = room->GetWidth() + 1;
    yPos = randomPositionY;
}

int Exit::GetXPos()
{
    return xPos;
}

int Exit::GetYPos()
{
    return yPos;
}

void Exit::SetXPos(int pos)
{
    this->xPos = pos;
}

void Exit::SetYPos(int pos)
{
    this->yPos = pos;
}



