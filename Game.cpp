//
// Created by goldbarth on 07.09.2023.
//

#include "Game.h"
#include "Room.h"

void Game::Start()
{
    system("cls");
    Sleep(60);
    RoomSize roomSize = GetRoomSize();
    InitializeObjects(roomSize);
}

void Game::InitializeObjects(RoomSize roomSize)
{
    Room room(roomSize.width, roomSize.height);
    Key key(&room);
    Exit exit(&room);
    Player player(this, &room, &key);
    room.DrawRoom(charType.wall, charType.floor);
    key.DrawPosition(charType.key);
    exit.DrawPosition(charType.exit);
    player.DrawStartPos(charType.player);

    GameLoop();

    Sleep(6000);
    std::cin.get();
}

void Game::GameLoop()
{
    while (gameIsRunning)
    {
        Player player(this, nullptr, nullptr);
        player.Move(charType.player);
        CheckIfExitOpens();
        CheckIfPlayerEntersExit();
    }
}

void Game::OpenExit()
{
    Player player(this, nullptr, nullptr);
    player.UpdatePos(player.GetXPos() + 1, player.GetYPos(), charType.exit);
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
    Player player(this, nullptr, nullptr);
    Exit exit(nullptr);
    return (player.GetXPos() + 1 == exit.GetXPos() && player.GetYPos() == exit.GetYPos());
}

bool Game::HasPlayerKeyCollected()
{
    Player player(this, nullptr, nullptr);
    return !player.HasKey() && player.keyIsCollected;
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



