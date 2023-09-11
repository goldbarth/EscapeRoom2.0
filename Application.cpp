//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"
#include "Menu.h"

Application::Application() : game(std::make_unique<Game>(*this))
{
    gameState = GameState::MainMenu;
}

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
                MainMenu();
                break;
            case GameState::Game:
                EnterGame();
                break;
            case GameState::Tutorial:
                EnterTutorial();
                break;
            case GameState::Exit:
                ExitApplication();
                break;
        }
    }
}

void Application::MainMenu()
{
    Menu menu(this);
    menu.InitializeMainMenu();
}

void Application::EnterTutorial()
{
    Menu menu(this);
    menu.InitializeTutorial();
}

void Application::EnterOutro()
{
    Menu menu(this);
    menu.InitializeOutro();
}

void Application::EnterGame()
{
    game->Start();
}

void Application::ExitApplication()
{
    exit(0);
}

void Application::SetState(GameState state)
{
    gameState = state;
}


