//
// Created by goldbarth on 07.09.2023.
//

#include "Exit.h"

Exit::Exit(Room *room) : room(room), xPos(0), yPos(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Exit::Initialize(char exit)
{
    SetRandomPosition();
    DrawExit(exit);
}

void Exit::DrawExit(char exit) const
{
    std::cout << "\x1B[35m";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             { static_cast<SHORT>(xPos), static_cast<SHORT>(yPos) }); // Set cursor position using SetConsoleCursorPos
    std::cout << exit;
    std::cout << "\x1B[0m";
}

void Exit::SetRandomPosition()
{
    xPos = room->GetWidth() + 1;
    yPos = rand() % (room->GetHeight() - 1) + 2;
}

int Exit::GetXPos() const
{
    return xPos;
}

int Exit::GetYPos() const
{
    return yPos;
}



