//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

#include <iostream>
#include <conio.h>
#include <memory>
#include <ctime>
#include "Hlpr.h"
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

    void Initialize(char player);
    void UpdatePos(int x, int y, char symbol);
    void Move(char player);

    bool HasKey();

    int GetXPos() const;
    int GetYPos() const;

    void SetKeyIsCollected(bool value);

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
    static bool IsNewPosWall(int x, int y);

    void GetRandomStartPos();
    void SetPos(char symbol) const;

    bool IsThisPosKeyPos();
    bool IsNotAtRightWall(int x, int y);
};

#endif //ESCAPEROOM2_0_PLAYER_H
