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
#include "Defines.h"

// Reference to the Application class is important to close the game loop.
Game::Game(Application& app) : pRoom(std::make_unique<Room>()), pKey(std::make_unique<Key>(*pRoom)),
                    pExit(std::make_unique<Exit>(*pRoom)), pPlayer(std::make_unique<Player>(*this, *pRoom, *pKey)), app(&app),
                    charType(CharType())
{}

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

    const std::string prompt = "\n   Enter room width: ";

    roomSize.width = ValidationCheck(prompt, MIN_WIDTH, MAX_WIDTH);

    const std::string prompt2 = "\n   Enter room height: ";
    roomSize.height = ValidationCheck(prompt2, MIN_HEIGHT, MAX_HEIGHT);

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
/// Fancy way to validate input. No? Lol.
/// <summary>
int Game::ValidationCheck(const std::string& command, const int& min, const int& max)
{
    int value;
    bool isFirstTry = true;

    while (true)
    {
        cwtr::Write("   " + command);
        cwtr::Read(value);

        if (std::cin.fail() || value < min || value > max)
        {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer

            if (!isFirstTry) {
                // Clear the current line and the previous line
                cwtr::Write("\033[A\033[2K\033[A\033[2K\033[A\033[2K");
            }
            
            cwtr::WriteLine("   Invalid input. Please enter a value between " + std::to_string(min) + " and " + std::to_string(max) + ".");
            isFirstTry = false;
        }
        else
        {
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
    const double width = pRoom->GetWidth();
    const double height = pRoom->GetHeight();
    
    constexpr double half = 0.5;
    constexpr double textIdent = 12;
    const double left = (width * half) - textIdent;

    const std::vector<std::pair<std::string, Color>> lines =
    {
        {"     CONGRATULATIONS!", Color::LightYellow},
        {" YOU ESCAPED THE DARKNESS.", Color::LightYellow},
        {"  NOW YOU WILL ENTER THE", Color::LightYellow},
        {"         UNKNOWN.", Color::LightYellow},
        {"  GOOD LUCK, ADVENTURER.", Color::LightYellow},
        {"", Color::LightYellow},
        {"Press any key to continue.", Color::White}
    };

    SetCursorPos(0, 0);
    for (size_t i = 0; i < lines.size(); ++i) {
        double top = (height * half) - 6 + i;
        cwtr::WriteLineAt(left, top, lines[i].first, lines[i].second);
    }
    
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




