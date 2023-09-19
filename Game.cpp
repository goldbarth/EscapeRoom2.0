//
// Created by goldbarth on 07.09.2023.
//

#include "Game.h"


// Reference to the Application class is important to close the game loop.
Game::Game(Application& app) : app(app), room(std::make_unique<Room>()), key(std::make_unique<Key>(*room)),
        exit(std::make_unique<Exit>(*room)), player(std::make_unique<Player>(*this, *room, *key))
{
    charType = CharType();

    gameIsRunning = true;
    isExitOpen = false;
}

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
    csptr::ClearScreen();
    csptr::WriteLine("\n\n        ******** ESCAPE ROOM ********");
    csptr::WriteLine("\n\n\n   Enter the room size you want to play in.");
    csptr::WriteLine("\n       Width: 25 - 35 | Height. 12 - 25");
}

void Game::InitializeObjects(const RoomSize& roomSize)
{
    csptr::ClearScreen();
    room->Initialize(roomSize.width, roomSize.height, charType.wall, charType.floor);
    key->Initialize(charType.key);
    exit->Initialize(false);
    player->Initialize(charType.player);

    GameLoop();
}

RoomSize Game::EvaluateRoomSize()
{
    RoomSize roomSize{};

    csptr::Write("\n   Enter room width: ");
    roomSize.width = ValidationCheck(25, 35);

    csptr::Write("\n   Enter room height: ");
    roomSize.height = ValidationCheck(12, 25);

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
        csptr::Write("\n   Invalid input. Please enter a value between " + std::to_string(min) + " and " + std::to_string(max) + ".");

    return value;
}

void Game::PlayExitAnimation()
{
    // ...@
    std::string result = "..." + std::string(1, charType.player);
    csptr::WriteAt(player->GetXPos(), player->GetYPos(), result, Color::LightGreen);
}

void Game::DrawGameEndText()
{
    // Set the text compared to the room size in the middle of the room.
    SetCursorPos(0, 0);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 6, "     CONGRATULATIONS!", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 5, " YOU ESCAPED THE DARKNESS.", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 4, "  NOW YOU WILL ENTER THE", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 3, "         UNKNOWN.", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 2, "  GOOD LUCK, ADVENTURER.", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 1, "", Color::LightYellow);
    csptr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5), "Press any key to continue.", Color::White);
    (void)_getch(); //Explicitly ignore return value
}

void Game::DrawWinScreen()
{
    app.StartOutro();
}

bool Game::IsPlayerOnExit()
{
    return (player->GetXPos() + 1 == exit->GetXPos() && player->GetYPos() == exit->GetYPos());
}

bool Game::HasPlayerKeyCollected()
{
    return player->HasKey();
}




