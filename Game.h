//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>

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

class Player;
class Room;
class Exit;
class Key;

class Game
{
public:
    explicit Game();
    // Default destructor
    ~Game();

    void Start();
    bool IsPlayerOnExit();

    char GetFloorChar();
    char GetWallChar();
    char GetExitChar();

private:
    CharType charType;

    bool gameIsRunning = true;

    Player* player;
    Room* room;
    Exit* exit;
    Key* key;

    void InitializeObjects(RoomSize roomSize);

    void GameLoop();
    void OpenExit();
    void CheckIfExitOpens();
    void CheckIfPlayerEntersExit();

    bool HasPlayerKeyCollected();

    RoomSize GetRoomSize();

    static void ClearScreen();
};


#endif //ESCAPEROOM2_0_GAME_H
