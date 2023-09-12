//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_APPLICATION_H
#define ESCAPEROOM2_0_APPLICATION_H

#include <iostream>
#include <memory>
#include "Windows.h"
#include "Game.h"
#include "Hlpr.h"

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
    void EnterOutro();
    void SetState(GameState state);

private:
    std::unique_ptr<Game> game;
    GameState gameState;

    [[noreturn]] void GameLoop();

    void MainMenu();
    void EnterGame();
    void EnterTutorial();
    void ExitApplication();
};


#endif //ESCAPEROOM2_0_APPLICATION_H
