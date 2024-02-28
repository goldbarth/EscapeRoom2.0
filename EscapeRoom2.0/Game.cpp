//
// Created by goldbarth on 07.09.2023.
//

#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <limits>
#include <conio.h>

#include "cwtr.h"
#include "Game.h"

// Reference to the Application class is important to close the game loop.
Game::Game(Application& app) : pRoom(std::make_unique<Room>()), pKey(std::make_unique<Key>(*pRoom)),
                    pExit(std::make_unique<Exit>(*pRoom)), pPlayer(std::make_unique<Player>(*this, *pRoom, *pKey)), app(&app),
                    charType(CharType())
{
}

Game::~Game()
= default;

void Game::SetGameStartConditions()
{
    gameIsRunning = true;
    isExitOpen = false;
    pPlayer->SetKeyIsCollected(false);
}

RoomSize Game::CreateRoom()
{
    DrawPromptCommand();
    return EvaluateRoomSize();
}

void Game::Start()
{
    SetGameStartConditions();
    InitializeObjects(CreateRoom());
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
    pRoom->Initialize(roomSize.width, roomSize.height);
    pKey->Initialize(charType.key);
    pExit->Initialize(false);
    pPlayer->Initialize(charType.player);

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
        pPlayer->Move(charType.player);
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
    pExit->DrawExit(isExitOpen);
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
    while (true) {
        cwtr::Write("   ");
        cwtr::Read(value);
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
            cwtr::WriteLine("\n   Invalid input. Please enter a value between " + std::to_string(min) + " and " + std::to_string(max) + ".");
        }
        else {
            break; // Valid input, exit the loop
        }
    }
    return value;
}

void Game::PlayExitAnimation() const
{
    // ...@
    const std::string result = "..." + std::string(1, charType.player);
    cwtr::WriteAt(pPlayer->GetXPos(), pPlayer->GetYPos(), result, Color::LightGreen);
}

void Game::DrawGameEndText() const
{
    // Set the text compared to the upRoom size in the middle of the upRoom.
    const double width = pRoom->GetWidth();
    const double height = pRoom->GetHeight();
    
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
    return (pPlayer->GetXPos() + 1 == pExit->GetXPos() && pPlayer->GetYPos() == pExit->GetYPos());
}

bool Game::HasPlayerKeyCollected() const
{
    return pPlayer->HasKey();
}




