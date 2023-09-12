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
    Hlpr::ClearScreen();
    Hlpr::WriteLine("\n\n        ******** ESCAPE ROOM ********");
    Hlpr::WriteLine("\n\n\n   Enter the room size you want to play in.");
}

void Game::InitializeObjects(const RoomSize& roomSize)
{
    Hlpr::ClearScreen();
    room->Initialize(roomSize.width, roomSize.height, charType.wall, charType.floor);
    key->Initialize(charType.key);
    exit->Initialize(charType.exit);
    player->Initialize(charType.player);

    GameLoop();
}

RoomSize Game::EvaluateRoomSize()
{
    int width;
    int height;

    Hlpr::Write("\n   Enter room width: ");
    std::cin >> width;
    Hlpr::Write("\n   Enter room height: ");
    std::cin >> height;

    RoomSize roomSize{};
    roomSize.width = width;
    roomSize.height = height;

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

    exit->DrawExit(charType.floor);
    isExitOpen = true;
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

void Game::PlayExitAnimation()
{
    // ...@
    std::string result = "..." + std::string(1, charType.player);
    Hlpr::WriteAt(player->GetXPos(), player->GetYPos(), result, ColorCode::light_green());
}

void Game::DrawGameEndText()
{
    // Set the text compared to the room size in the middle of the room.
    SetCursorPos(0, 0);
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 6, "     CONGRATULATIONS!", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 5, " YOU ESCAPED THE DARKNESS.", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 4, "  NOW YOU WILL ENTER THE", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 3, "         UNKNOWN.", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 2, "  GOOD LUCK, ADVENTURER.", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5) - 1, "", ColorCode::light_yellow());
    Hlpr::WriteLineAt((room->GetWidth() * 0.5) - 12, (room->GetHeight() * 0.5), "Press any key to continue.", ColorCode::white());
    (void)_getch(); //Explicitly ignore return value
}

void Game::DrawWinScreen()
{
    app.EnterOutro();
}

bool Game::IsPlayerOnExit()
{
    return (player->GetXPos() + 1 == exit->GetXPos() && player->GetYPos() == exit->GetYPos());
}

bool Game::HasPlayerKeyCollected()
{
    return player->HasKey();
}




