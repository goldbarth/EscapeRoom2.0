//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>
#include "Player.h"
#include "Exit.h"
#include "Room.h"
#include "Key.h"

#ifndef ESCAPEROOM2_0_GAME_H
#define ESCAPEROOM2_0_GAME_H

struct RoomSize
{
    int width;
    int height;
};

struct CharType
{
    char wall = '#';
    char floor = ' ';
    char key = '$';
    char exit = '#';
    char player = '@';
};

class Game
{
public:
    void Start();
    char GetFloorChar();
    bool IsPlayerOnExit();

    char GetWallChar();

    char GetExitChar();

private:
    CharType charType;

    static RoomSize GetRoomSize();
    void InitializeObjects(RoomSize roomSize);

    void GameLoop();

    void OpenExit();

    bool HasPlayerKeyCollected();

    bool gameIsRunning = true;

    void CheckIfExitOpens();

    void CheckIfPlayerEntersExit();
};


#endif //ESCAPEROOM2_0_GAME_H
