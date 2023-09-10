//
// Created by goldbarth on 07.09.2023.
//

#include <conio.h>
#include "Game.h"
#include "Room.h"
#include "Key.h"
#include "Player.h"

Player::Player(Game* game, Room* room, Key* key) :game(game), room(room), key(key), xPos(0), yPos(0)
{
    keyIsCollected = false;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Player::Initialize(char player)
{
    do
    {
        GetRandomStartPos();
        SetPos(player);
    } while (IsThisPosKeyPos());
}

void Player::Move(char player)
{
    // Check if a key is pressed
    auto valid = _kbhit();
    if(valid)
    {
        UpdatePos(xPos, yPos, game->GetFloorChar());

        char inputKey = (char)_getch(); // read the key
        switch (inputKey)
        {
            case ArrowKey().up:
                if (yPos > 1) yPos--;
                else PlayBeep();
                break;
            case ArrowKey().down:
                if (yPos < room->GetHeight()) yPos++;
                else PlayBeep();
                break;
            case ArrowKey().left:
                if (xPos > 1) xPos--;
                else PlayBeep();
                break;
            case ArrowKey().right:
                if (xPos < room->GetWidth()) xPos++;
                else PlayBeep();
                break;
            default:
                // Prevent printing any other letter/symbol next to the player char if pressed
                std::cout << game->GetFloorChar();
                break;
        }

        UpdatePos(xPos, yPos, player);
    }
}


void Player::GetRandomStartPos()
{
    xPos = rand() % (room->GetWidth() - 1) + 1;
    yPos = rand() % (room->GetHeight() - 1) + 1;
}

void Player::SetPos(char player)
{
    std::cout << "\x1B[32m"; // Set text color to dark green
    SetCursorPos(xPos, yPos); // Set cursor position using SetCursorPos
    std::cout << player;
    std::cout << "\x1B[0m"; // Reset text color
}

void Player::UpdatePos(int x, int y, char symbol)
{
    if (IsNewPosWall(x, y) || !IsNotAtRightWall(x, y)) return;
    SetPos(symbol);
}

bool Player::IsNotAtRightWall(int x, int y)
{
    return (x != room->GetWidth() + 1 || y == 0 || game->IsPlayerOnExit());
}

void Player::SetCursorPos(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             { static_cast<SHORT>(x), static_cast<SHORT>(y) });
}

void Player::PlayBeep()
{
    Beep(120, 200);
}

bool Player::IsNewPosWall(int x, int y)
{
    return x <= 0 || y <= 0;
}

bool Player::IsThisPosKeyPos()
{
    return xPos == key->GetXPos() && yPos == key->GetYPos();
}

bool Player::HasKey()
{
    if(keyIsCollected) return keyIsCollected;

    if (IsThisPosKeyPos() && !keyIsCollected)
        keyIsCollected = true;

    return false;
}

int Player::GetXPos()
{
    return xPos;
}

int Player::GetYPos()
{
    return yPos;
}
