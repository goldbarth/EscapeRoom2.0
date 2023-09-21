//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H


#include "Game.h"
#include "Exit.h"
#include "Key.h"

class Game;
class Room;
class Key;

class Player
{
public:
    explicit Player(Game& game, Room& room, Key& key);

    void Initialize(const char& player);
    void UpdatePos(const int& x, const int& y, const char& symbol);
    void Move(const char& player);

    bool HasKey();

    int GetXPos() const { return xPos; }
    int GetYPos() const { return yPos; }

    void SetKeyIsCollected(const bool& value) { keyIsCollected = value; }

private:
    Game& game;
    Room& room;
    Key& key;

    bool keyIsCollected;

    int xPos;
    int yPos;

    constexpr static char up = 'w';
    constexpr static char down = 's';
    constexpr static char left = 'a';
    constexpr static char right = 'd';

    static void PlayStopSound();
    static bool IsNewPosWall(const int& x, const int& y);

    void GetRandomStartPos();
    void SetPos(const char& symbol) const;

    bool IsThisPosKeyPos() const;
    bool IsNotAtRightWall(const int& x, const int& y) const;
};

#endif //ESCAPEROOM2_0_PLAYER_H
