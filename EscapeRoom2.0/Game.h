//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_GAME_H
#define ESCAPEROOM2_0_GAME_H

#include <memory>

#include "Application.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Key.h"

struct RoomSize
{
    int width = 0;
    int height = 0;
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
    ~Game();
    

    void Start();

    bool IsPlayerOnExit() const;

    struct CharType
    {
        char wall = '#';
        char floor = ' ';
        char key = '$';
        char exit = '#';
        char player = '@';
    };

private:
    std::unique_ptr<Room> pRoom;
    std::unique_ptr<Key> pKey;
    std::unique_ptr<Exit> pExit;
    std::unique_ptr<Player> pPlayer;

    std::unique_ptr<Application> app;
    //Application* app;
    CharType charType;

    bool gameIsRunning = true;
    bool isExitOpen = false;

    
    void SetGameStartConditions();
    RoomSize CreateRoom();
    RoomSize EvaluateRoomSize();
    void InitializeObjects(const RoomSize& roomSize);
    void GameLoop();
    void OpenExit();
    void DrawWinScreen() const;
    void CheckIfExitOpens();
    void CheckIfPlayerEntersExit();
    void PlayExitAnimation() const;
    void DrawGameEndText() const;

    bool HasPlayerKeyCollected() const;

    static void DrawPromptCommand();
    static int ValidationCheck(const int &min, const int &max);
};


#endif //ESCAPEROOM2_0_GAME_H
