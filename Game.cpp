//
// Created by goldbarth on 07.09.2023.
//

#include <utility>
#include "Player.h"
#include "Game.h"
#include "Room.h"
#include "Exit.h"
#include "Key.h"

Game::Game() : player(), key(), exit(), room()
{
    // Allocate memory for these objects
    this->room = new Room();
    this->exit = new Exit(this->room);
    this->key = new Key(this->room);
    this->player = new Player(this, this->room, this->key);

    gameIsRunning = true;
}

void Game::Start()
{
    ClearScreen();
    RoomSize roomSize = GetRoomSize();

    ClearScreen();
    std::cout << "You woke up in a almost dark room. Try to find the key and escape!" << std::endl;
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
    player->UpdatePos(player->GetXPos() + 1, player->GetYPos(), charType.exit);
}

void Game::ClearScreen()
{
    system("cls");
    Sleep(60);
}

void Game::CheckIfExitOpens()
{
    if (HasPlayerKeyCollected()) OpenExit();
}

void Game::CheckIfPlayerEntersExit()
{
    if (IsPlayerOnExit() && HasPlayerKeyCollected())
    {
        system("cls");
        for (int i = 0; i < 10; i++)
        {
            // Print the text in purple
            std::cout << "\x1B[35m";
            std::cout << "YOU WON!";
            std::cout << "\x1B[0m";
            Sleep(100);
        }

        gameIsRunning = false;
    }
}

bool Game::IsPlayerOnExit()
{
    return (player->GetXPos() + 1 == exit->GetXPos() && player->GetYPos() == exit->GetYPos());
}

bool Game::HasPlayerKeyCollected()
{
    return !player->HasKey() && player->keyIsCollected;
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

char Game::GetWallChar()
{
    return charType.wall;
}

char Game::GetExitChar()
{
    return charType.exit;
}

Game::~Game()
{
    delete player;
    delete room;
    delete exit;
    delete key;
}




