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
    MainMenu,
    Game,
    Tutorial,
    Exit,
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

    [[noreturn]] void GameLoop();

    void StartMainMenu();
    void StartGame() const;
    void StartTutorial();
    void ExitApplication();
};


#endif //ESCAPEROOM2_0_APPLICATION_H
