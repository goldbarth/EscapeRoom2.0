//
// Created by goldbarth on 07.09.2023.
//

#include "Player.h"
#include "Game.h"
#include "Room.h"
#include "Exit.h"
#include "Key.h"

Game::Game() : player(), key(), exit(), room()
{
    // Allocate memory for these objects
    this->room = new Room();
    this->key = new Key(this->room);
    this->exit = new Exit(this->room);
    this->player = new Player(this, this->room, this->key);

    gameIsRunning = true;
}

void Game::Start()
{
    ClearScreen();
    RoomSize roomSize = GetRoomSize();

    ClearScreen();
    ShowConsoleCursor(false);
    InitializeObjects(roomSize);
}

void Game::InitializeObjects(RoomSize roomSize)
{
    room->Initialize(roomSize.width, roomSize.height, charType.wall, charType.floor);
    key->Initialize(charType.key);
    exit->Initialize(charType.exit);
    player->Initialize(charType.player);

    GameLoop();
}

void Game::GameLoop()
{
    while (gameIsRunning)
    {
        player->Move(charType.player);
        CheckIfExitOpens();
        CheckIfPlayerEntersExit();
    }
}

void Game::OpenExit()
{
    for (int i = 0; i <2; ++i)
        Beep(1000, 100);

    exit->DrawExit(charType.floor);
    isExitOpen = true;
}

void Game::ClearScreen()
{
    system("cls");
    Sleep(60);
}

void Game::CheckIfExitOpens()
{
    if (HasPlayerKeyCollected() && !isExitOpen) OpenExit();
}

void Game::CheckIfPlayerEntersExit()
{
    if (IsPlayerOnExit() && HasPlayerKeyCollected())
    {
        for (int i = 0; i < 3; ++i)
            Beep(50, 100);

        Sleep(300);
        system("cls");
        for (int i = 31; i < 37; i++)
        {
            Beep(i * 5, 100);
            std::cout << "\x1B[" << i << "m";
            std::cout << "You escaped! Congratulations!";
            std::cout << "\x1B[0m";
            Sleep(300);
            ClearScreen();
        }

        std::cout << "\x1B[35m";
        std::cout << "You escaped! Congratulations!";
        std::cout << "\x1B[0m";

        ShowConsoleCursor(true);
        gameIsRunning = false;
    }
}

// https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
void Game::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

bool Game::IsPlayerOnExit()
{
    return (player->GetXPos() + 1 == exit->GetXPos() && player->GetYPos() == exit->GetYPos());
}

bool Game::HasPlayerKeyCollected()
{
    return player->HasKey();
}

RoomSize Game::GetRoomSize()
{
    int width;
    int height;
    std::cout << "Enter room width: ";
    std::cin >> width;
    std::cout << "Enter room height: ";
    std::cin >> height;

    RoomSize roomSize{};
    roomSize.width = width;
    roomSize.height = height;

    return roomSize;
}

char Game::GetFloorChar()
{
    return charType.floor;
}

Game::~Game()
{
    delete player;
    delete room;
    delete exit;
    delete key;
}




