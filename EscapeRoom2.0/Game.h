//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_GAME_H
#define ESCAPEROOM2_0_GAME_H

#include <iostream>
#include <memory>
#include "Application.h"
#include "Player.h"
#include "csptr.h"
#include "Room.h"
#include "Exit.h"
#include "Key.h"


struct RoomSize
{
    int width;
    int height;
};

class Application;
class Player;
class Room;
class Exit;
class Key;

class Game
{
public:
    explicit Game(Application& app);
    inline ~Game() = default;

    void Start();

    bool IsPlayerOnExit();

    struct CharType
    {
        char wall = '#';
        char floor = ' ';
        char key = '$';
        char exit = '#';
        char player = '@';
    };

private:
    std::unique_ptr<Room> room;
    std::unique_ptr<Key> key;
    std::unique_ptr<Exit> exit;
    std::unique_ptr<Player> player;

    Application& app;
    CharType charType;

    bool gameIsRunning = true;
    bool isExitOpen = false;

    void InitializeObjects(const RoomSize& roomSize);

    void GameLoop();
    void OpenExit();
    void DrawWinScreen();
    void CheckIfExitOpens();
    void CheckIfPlayerEntersExit();
    void PlayExitAnimation();
    void DrawGameEndText();

    bool HasPlayerKeyCollected();

    static void DrawPromptCommand();

    static RoomSize EvaluateRoomSize();

    static int ValidationCheck(const int &min, const int &max);
};


#endif //ESCAPEROOM2_0_GAME_H
