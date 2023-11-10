//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

#include "Player.h"
#include "csptr.h"

Player::Player(Game& game, Room& room, Key& key) : game(&game), room(&room),
        key(&key), keyIsCollected(false), xPos(0), yPos(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Player::Initialize(const char& player)
{
    do
    {
        GetRandomStartPos();
        SetPos(player);
    } while (IsThisPosKeyPos());
}

void Player::Move(const char& player)
{
    // Check if a key is pressed
    const auto valid = _kbhit();
    if(valid)
    {
        constexpr Game::CharType charType;
        UpdatePos(xPos, yPos, charType.floor);

        const char inputKey = static_cast<char>(_getch()); // read the key
        switch (inputKey)
        {
            case UP:
                if (yPos > 1) yPos--;
                else PlayStopSound();
                break;
            case DOWN:
                if (yPos < room->GetHeight()) yPos++;
                else PlayStopSound();
                break;
            case LEFT:
                if (xPos > 1) xPos--;
                else PlayStopSound();
                break;
            case RIGHT:
                if (xPos < room->GetWidth()) xPos++;
                else PlayStopSound();
                break;
            default:
                // Prevent printing any other letter/symbol next to the player char if pressed
                std::cout << charType.floor;
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
    return (x != room->GetWidth() + 1 || y == 0 || game->IsPlayerOnExit());
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
    return xPos == key->GetXPos() && yPos == key->GetYPos();
}

bool Player::HasKey()
{
    if (IsThisPosKeyPos() && !keyIsCollected)
        keyIsCollected = true;

    return keyIsCollected;
}

void Player::GetRandomStartPos()
{
    xPos = rand() % (room->GetWidth() - 1) + 1;
    yPos = rand() % (room->GetHeight() - 1) + 1;
}

void Player::SetPos(const char& symbol) const
{
    csptr::WriteAt(xPos, yPos, symbol, Color::LightGreen);
}


