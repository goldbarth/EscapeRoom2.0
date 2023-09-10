//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

#include <conio.h>
#include "Player.h"
#include "Game.h"
#include "Room.h"
#include "Hlpr.h"
#include "Key.h"
#include "Game.h"
#include "Room.h"
#include "Key.h"

struct ArrowKey
{
    char up = 'w';
    char down = 's';
    char left = 'a';
    char right = 'd';
};

class Player
{
public:
    bool keyIsCollected;

    Player(Game* game, Room* room, Key* key);

    void Initialize(char player);
    void UpdatePos(int x, int y, char symbol);
    void Move(char player);

    bool HasKey();

    int GetXPos() const;
    int GetYPos() const;

private:
    ConsoleColor color;
    Game* game;
    Room* room;
    Key* key;

    int xPos;
    int yPos;

    static void PlayBeep();
    static bool IsNewPosWall(int x, int y);

    void GetRandomStartPos();
    void SetPos(char player);

    bool IsThisPosKeyPos();
    bool IsNotAtRightWall(int x, int y);
};

#endif //ESCAPEROOM2_0_PLAYER_H
