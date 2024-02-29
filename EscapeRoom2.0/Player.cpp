//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

#include "Defines.h"
#include "Player.h"
#include "cwtr.h"

Player::Player(Game& game, Room& room, Key& key) : pGame(&game), pRoom(&room), pKey(&key), keyIsCollected(false)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Player::Initialize(const char& object)
{
    do
    {
        SetRandomPosition();
        SetPos(object);
    } while (IsThisPosKeyPos());
}

void Player::Move(const char& player)
{
    // Check if a key is pressed
    const auto valid = _kbhit();
    if(valid)
    {
        constexpr Game::CharType charType;
        constexpr int minPos = 1;

        // Clear the previous position
        UpdatePos(xPos, yPos, charType.floor);

        const char inputKey = static_cast<char>(_getch()); // read the key
        switch (inputKey)
        {
            case KEY_CODE_UP:
                if (yPos > minPos) yPos--;
                else PlayStopSound();
                break;
            case KEY_CODE_DOWN:
                if (yPos < pRoom->GetHeight()) yPos++;
                else PlayStopSound();
                break;
            case KEY_CODE_LEFT:
                if (xPos > minPos) xPos--;
                else PlayStopSound();
                break;
            case KEY_CODE_RIGHT:
                if (xPos < pRoom->GetWidth()) xPos++;
                else PlayStopSound();
                break;
        }

        UpdatePos(xPos, yPos, player);
    }
}

void Player::UpdatePos(const int& x, const int& y, const char& symbol) const
{
    if (IsNewPosWall(x, y) || !IsNotAtRightWall(x, y)) return;
    SetPos(symbol);
}

bool Player::IsNotAtRightWall(const int& x, const int& y) const
{
    return (x != pRoom->GetWidth() + 1 || y == 0 || pGame->IsPlayerOnExit());
}

void Player::PlayStopSound()
{
    Beep(120, 200);
}

bool Player::IsNewPosWall(const int& x, const int& y)
{
    return x <= 0 || y <= 0;
}

bool Player::IsThisPosKeyPos() const
{
    return xPos == pKey->GetXPos() && yPos == pKey->GetYPos();
}

bool Player::HasKey()
{
    if (IsThisPosKeyPos() && !keyIsCollected)
        keyIsCollected = true;

    return keyIsCollected;
}

void Player::SetPos(const char& symbol) const
{
    cwtr::WriteAt(xPos, yPos, symbol, Color::LightGreen);
}

void Player::SetRandomPosition()
{
    xPos = std::rand() % (pRoom->GetWidth() - 1) + 1;
    yPos = std::rand() % (pRoom->GetHeight() - 1) + 1;
}


