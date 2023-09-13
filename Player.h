//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

#include <iostream>
#include <conio.h>
#include <memory>
#include <ctime>
#include "csptr.h"
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

    inline int GetXPos() const { return xPos; }
    inline int GetYPos() const { return yPos; }

    inline void SetKeyIsCollected(const bool& value) { keyIsCollected = value; }

private:
    Game& game;
    Room& room;
    Key& key;

    bool keyIsCollected;

    int xPos;
    int yPos;

    constexpr static const char up = 'w';
    constexpr static const char down = 's';
    constexpr static const char left = 'a';
    constexpr static const char right = 'd';

    static void PlayStopSound();
    static bool IsNewPosWall(const int& x, const int& y);

    void GetRandomStartPos();
    void SetPos(const char& symbol) const;

    bool IsThisPosKeyPos();
    bool IsNotAtRightWall(const int& x, const int& y);
};

#endif //ESCAPEROOM2_0_PLAYER_H
