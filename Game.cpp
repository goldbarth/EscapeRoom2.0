//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"
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
    Hlpr::ClearScreen();
    RoomSize roomSize = GetRoomSize();

    Hlpr::ClearScreen();
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

        PlayExitAnimation();
        DrawGameEndText();
        DrawWinScreen();

        ShowConsoleCursor(true);
        gameIsRunning = false;
    }
}

void Game::PlayExitAnimation()
{
    std::string result = "..." + std::string(1, charType.player);
    Hlpr::WriteAt(player->GetXPos(), player->GetYPos(), result, color.light_green());
}

void Game::DrawGameEndText()
{
    // Set the text compared to the room size in the middle of the room.
    SetCursorPos(0, 0);
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 6, "     CONGRATULATIONS!", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 5, " YOU ESCAPED THE DARKNESS.", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 4, "  NOW YOU WILL ENTER THE", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 3, "        UNKNOWN.", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 2, "  GOOD LUCK, ADVENTURER.", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2) - 1, "", color.light_yellow());
    Hlpr::WriteLineAt((room->GetWidth()/2) - 12, (room->GetHeight()/2), "Press any key to continue.", color.white());
    (void)_getch(); //Explicitly ignore return value
}

void Game::DrawWinScreen()
{
    auto* app = new Application();
    app->DrawOutro();
    delete app;
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

char Game::GetFloorChar() const
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




