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

struct ArrowKey
{
    char up = 'w';
    char down = 's';
    char left = 'a';
    char right = 'd';
};

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

    ConsoleColor color;

    bool keyIsCollected;

    int xPos;
    int yPos;

    static void PlayBeep();
    static bool IsNewPosWall(int x, int y);

    void GetRandomStartPos();
    void SetPos(char symbol) const;

    bool IsThisPosKeyPos();
    bool IsNotAtRightWall(int x, int y);
};

#endif //ESCAPEROOM2_0_PLAYER_H
