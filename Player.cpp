//
// Created by goldbarth on 07.09.2023.
//

#include <conio.h>
#include "Game.h"
#include "Room.h"
#include "Key.h"
#include "Player.h"

Player::Player(Game *game, Room *room, Key *key) :game(game), room(room), key(key), xPos(0), yPos(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Player::Initialize(char player)
{
    do
    {
        GetRandomStartPos();
        SetPos(player);
    } while (ThisPosIsKeyPos());
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
            case 'w':
                if (yPos > 2) yPos--;
                else PlayBeep();
                break;
            case 's':
                if (yPos < room->GetHeight() + 1) yPos++;
                else PlayBeep();
                break;
            case 'a':
                if (xPos > 1) xPos--;
                else PlayBeep();
                break;
            case 'd':
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
    xPos = rand() % (room->GetWidth() - 1) + 1;   // Generates a random number between 1 and Width - 1
    yPos = rand() % (room->GetHeight() - 1) + 1; // Generates a random number between 1 and Height - 1
}

void Player::SetPos(char player)
{
    std::cout << "\x1B[32m"; // Set text color to dark green
    SetCursorPos(xPos, yPos); // Set cursor position using SetCursorPos (see below
    std::cout << player;
    std::cout << "\x1B[0m"; // Reset text color
}

void Player::UpdatePos(int x, int y, char symbol)
{
    if(IsNewPosWall(x, y)) return;

    RepaintEnvironment(x, y);
    DrawNewPos(x, y, symbol);
}

void Player::DrawNewPos(int x, int y, char symbol)
{
    if (symbol == game->GetWallChar())
    {
        // Print the text in black
        std::cout << "\x1B[30m";
        SetCursorPos(x, y);
        std::cout << symbol;
        std::cout << "\x1B[0m";
    }
    else
    {
        std::cout << "\x1B[32m";
        SetCursorPos(x, y);
        std::cout << symbol;
        std::cout << "\x1B[0m";
    }
}

void Player::RepaintEnvironment(int x, int y)
{
    RepaintWall(x, y);
    //RepaintExit(x, y);
}

void Player::RepaintWall(int x, int y)
{
    if (x != room->GetWidth() || y == 0 || game->IsPlayerOnExit()) return;

    SetCursorPos(x, y);
    std::cout << game->GetWallChar();
}

void Player::RepaintExit(int x, int y)
{
    if(x != room->GetWidth() || y == 0 || !game->IsPlayerOnExit() || keyIsCollected) return;

    std::cout << "\x1B[31m";
    SetCursorPos(x, y);
    std::cout << game->GetExitChar();
    std::cout << "\x1B[0m";
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

bool Player::ThisPosIsKeyPos()
{
    return xPos == key->GetXPos() && yPos == key->GetYPos();
}

bool Player::HasKey()
{
    if (ThisPosIsKeyPos() && !keyIsCollected)
    {
        keyIsCollected = true;
        return true;
    }

    return false;
}

void Player::SetXPos(int pos)
{
    xPos = pos;
}

void Player::SetYPos(int pos)
{
    yPos = pos;
}

int Player::GetXPos()
{
    return xPos;
}

int Player::GetYPos()
{
    return yPos;
}
