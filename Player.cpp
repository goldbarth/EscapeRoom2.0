//
// Created by goldbarth on 07.09.2023.
//

#include "Player.h"


Player::Player(Game& game, Room &room, Key &key) : game(game), room(room),
        key(key), xPos(0), yPos(0), keyIsCollected(false)
{
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
        Game::CharType charType;
        UpdatePos(xPos, yPos, charType.floor);

        char inputKey = (char)_getch(); // read the key
        switch (inputKey)
        {
            case up:
                if (yPos > 1) yPos--;
                else PlayStopSound();
                break;
            case down:
                if (yPos < room.GetHeight()) yPos++;
                else PlayStopSound();
                break;
            case left:
                if (xPos > 1) xPos--;
                else PlayStopSound();
                break;
            case right:
                if (xPos < room.GetWidth()) xPos++;
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

void Player::UpdatePos(int x, int y, char symbol)
{
    if (IsNewPosWall(x, y) || !IsNotAtRightWall(x, y)) return;
    SetPos(symbol);
}

bool Player::IsNotAtRightWall(int x, int y)
{
    return (x != room.GetWidth() + 1 || y == 0 || game.IsPlayerOnExit());
}

void Player::PlayStopSound()
{
    Beep(120, 200);
}

bool Player::IsNewPosWall(int x, int y)
{
    return x <= 0 || y <= 0;
}

bool Player::IsThisPosKeyPos()
{
    return xPos == key.GetXPos() && yPos == key.GetYPos();
}

bool Player::HasKey()
{
    if (IsThisPosKeyPos() && !keyIsCollected)
        keyIsCollected = true;

    return keyIsCollected;
}

void Player::GetRandomStartPos()
{
    xPos = rand() % (room.GetWidth() - 1) + 1;
    yPos = rand() % (room.GetHeight() - 1) + 1;
}

void Player::SetPos(char symbol) const
{
    Hlpr::WriteAt(xPos, yPos, symbol, ColorCode::light_green());
}

int Player::GetXPos() const
{
    return xPos;
}

int Player::GetYPos() const
{
    return yPos;
}

void Player::SetKeyIsCollected(bool value)
{
    keyIsCollected = value;
}


