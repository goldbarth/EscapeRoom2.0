//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

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

    int GetXPos();
    int GetYPos();

private:
    Game* game;
    Room* room;
    Key* key;

    int xPos;
    int yPos;

    void SetCursorPos(int x, int y);
    void PlayBeep();
    bool IsNewPosWall(int x, int y);

    void GetRandomStartPos();
    void SetPos(char player);
    void DrawNewPos(int x, int y, char symbol);

    bool IsThisPosKeyPos();
    bool IsNotAtRightWall(int x, int y);
};

#endif //ESCAPEROOM2_0_PLAYER_H
