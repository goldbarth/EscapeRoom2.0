//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_APPLICATION_H
#define ESCAPEROOM2_0_APPLICATION_H

#include <memory>
#include "Game.h"

class Game;

enum class GameState
{
    MAIN_MENU,
    GAME,
    TUTORIAL,
    EXIT,
};

enum class MenuType
{
    MAIN_MENU,
    TUTORIAL,
    OUTRO,
    EXIT
};

class Application
{
public:
    Application();
    ~Application();

    void Run();
    void StartOutro();
    void SetState(const GameState& state);

private:
    std::unique_ptr<Game> game;
    GameState gameState;

    [[noreturn]] void StateLoop();
    void InitializeState(MenuType menuType);
};

#endif //ESCAPEROOM2_0_APPLICATION_H
