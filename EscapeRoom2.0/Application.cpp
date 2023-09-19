//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"
#include "Menu.h"

Application::Application() : game(std::make_unique<Game>(*this)),
        gameState(GameState::MainMenu)
{}

void Application::Run()
{
    GameLoop();
}

[[noreturn]] void Application::GameLoop()
{
    while (true)
    {
        switch(gameState)
        {
        case GameState::MainMenu:
            StartMainMenu();
            break;
        case GameState::Game:
            StartGame();
            break;
        case GameState::Tutorial:
            StartTutorial();
            break;
        case GameState::Exit:
            ExitApplication();
            break;
        }
    }
}

void Application::StartMainMenu()
{
    Menu menu(this);
    menu.InitializeMainMenu();
}

void Application::StartTutorial()
{
    Menu menu(this);
    menu.InitializeTutorial();
}

void Application::StartOutro()
{
    Menu menu(this);
    menu.InitializeOutro();
}

void Application::StartGame()
{
    game->Start();
}

void Application::ExitApplication()
{
    Menu menu(this);
    menu.InitializeExit();
}

void Application::SetState(const GameState& state)
{
    gameState = state;
}


