//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_APPLICATION_H
#define ESCAPEROOM2_0_APPLICATION_H

#include <iostream>
#include <memory>
#include "Windows.h"
#include "csptr.h"
#include "Game.h"

class Game;

enum class GameState
{
    MainMenu,
    Game,
    Tutorial,
    Exit,
};

class Application
{
public:
    Application();
    inline ~Application() = default;

    void Run();
    void StartOutro();
    void SetState(const GameState& state);

private:
    std::unique_ptr<Game> game;
    GameState gameState;

    [[noreturn]] void GameLoop();

    void StartMainMenu();
    void StartGame();
    void StartTutorial();
    void ExitApplication();
};


#endif //ESCAPEROOM2_0_APPLICATION_H
