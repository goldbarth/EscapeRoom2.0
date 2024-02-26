//
// Created by goldbarth on 07.09.2023.
//

#include <Windows.h>
#include <iostream>
#include <conio.h>

#include "cwtr.h"
#include "Game.h"

// Reference to the Application class is important to close the game loop.
Game::Game(Application& app) : room(std::make_unique<Room>()), key(std::make_unique<Key>(*room)),
                    exit(std::make_unique<Exit>(*room)), player(std::make_unique<Player>(*this, *room, *key)), app(&app),
                    charType(CharType())    
{ }

Game::~Game()
= default;

void Game::Start()
{
    gameIsRunning = true;
    isExitOpen = false;
    player->SetKeyIsCollected(false);

    DrawPromptCommand();
    auto roomSize = EvaluateRoomSize();
    InitializeObjects(roomSize);
}

void Game::DrawPromptCommand()
{
    cwtr::ClearScreen();
    cwtr::WriteLine("\n\n        ******** ESCAPE ROOM ********");
    cwtr::WriteLine("\n\n\n   Enter the room size you want to play in.");
    cwtr::WriteLine("\n       Width: 25 - 35 | Height. 12 - 25");
}

void Game::InitializeObjects(const RoomSize& roomSize)
{
    cwtr::ClearScreen();
    room->Initialize(roomSize.width, roomSize.height);
    key->Initialize(charType.key);
    exit->Initialize(false);
    player->Initialize(charType.player);

    GameLoop();
}

RoomSize Game::EvaluateRoomSize()
{
    RoomSize roomSize;
    constexpr int minWidth = 25;
    constexpr int maxWidth = 35;
    constexpr int minHeight = 12;
    constexpr int maxHeight = 25;

    cwtr::Write("\n   Enter room width: ");
    roomSize.width = ValidationCheck(minWidth, maxWidth);

    cwtr::Write("\n   Enter room height: ");
    roomSize.height = ValidationCheck(minHeight, maxHeight);

    return roomSize;
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

void Game::CheckIfExitOpens()
{
    if (HasPlayerKeyCollected() && !isExitOpen) OpenExit();
}

void Game::OpenExit()
{
    for (int i = 0; i < 2; ++i)
        Beep(1000, 100);

    isExitOpen = true;
    exit->DrawExit(isExitOpen);
}

void Game::CheckIfPlayerEntersExit()
{
    if (IsPlayerOnExit() && HasPlayerKeyCollected())
    {
        // Multiply with i to get a different pitch for each beep.
        for (int i = 0; i < 4; ++i)
            Beep(300 * i, 100);

        PlayExitAnimation();
        DrawGameEndText();
        DrawWinScreen();

        gameIsRunning = false;
    }
}

/// <summary>
/// Insert a value between min and max.
/// </summary>
int Game::ValidationCheck(const int& min, const int& max)
{
    int value;
    while(!(std::cin >> value) || value < min || value > max)
        cwtr::Write("\n   Invalid input. Please enter a value between " + std::to_string(min) + " and " + std::to_string(max) + ".");

    return value;
}

void Game::PlayExitAnimation() const
{
    // ...@
    std::string result = "..." + std::string(1, charType.player);
    cwtr::WriteAt(player->GetXPos(), player->GetYPos(), result, Color::LightGreen);
}

void Game::DrawGameEndText() const
{
    // Set the text compared to the room size in the middle of the room.
    const double width = room->GetWidth();
    const double height = room->GetHeight();
    
    constexpr int startPos = 0;
    constexpr double half = 0.5;
    constexpr double textIdent = 12;
    
    const double left = (width * half) - textIdent;
    const double top1 = (height * half) - 6;
    const double top2 = (height * half) - 5;
    const double top3 = (height * half) - 4;
    const double top4 = (height * half) - 3;
    const double top5 = (height * half) - 2;
    const double top6 = (height * half) - 1;
    const double top7 = (height * half);
    
    SetCursorPos(startPos, startPos);
    cwtr::WriteLineAt(left, top1, "     CONGRATULATIONS!", Color::LightYellow);
    cwtr::WriteLineAt(left, top2, " YOU ESCAPED THE DARKNESS.", Color::LightYellow);
    cwtr::WriteLineAt(left, top3, "  NOW YOU WILL ENTER THE", Color::LightYellow);
    cwtr::WriteLineAt(left, top4, "         UNKNOWN.", Color::LightYellow);
    cwtr::WriteLineAt(left, top5, "  GOOD LUCK, ADVENTURER.", Color::LightYellow);
    cwtr::WriteLineAt(left, top6, "", Color::LightYellow);
    cwtr::WriteLineAt(left, top7, "Press any key to continue.", Color::White);
    
    (void)_getch(); //Explicitly ignore return value
}

void Game::DrawWinScreen() const
{
    app->StartOutro();
}

bool Game::IsPlayerOnExit() const
{
    return (player->GetXPos() + 1 == exit->GetXPos() && player->GetYPos() == exit->GetYPos());
}

bool Game::HasPlayerKeyCollected() const
{
    return player->HasKey();
}




