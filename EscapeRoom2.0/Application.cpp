//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"
#include "Menu.h"

Application::Application() : game(std::make_unique<Game>(*this)),
                                gameState(GameState::MAIN_MENU)
{}

Application::~Application()
= default;

[[noreturn]] void Application::Run()
{
    StateLoop();
}

[[noreturn]] void Application::StateLoop()
{
    while (true)
    {
        switch(gameState)
        {
        case GameState::MAIN_MENU:
            InitializeState(MenuType::MAIN_MENU);
            break;
        case GameState::GAME:
            game->Start();
            break;
        case GameState::TUTORIAL:
            InitializeState(MenuType::TUTORIAL);
            break;
        case GameState::EXIT:
            InitializeState(MenuType::EXIT);
            break;
        }
    }
}

void Application::InitializeState(const MenuType menuType)
{
    const Menu menu(this);
    switch (menuType) {
    case MenuType::MAIN_MENU:
        menu.InitializeMainMenu();
        break;
    case MenuType::TUTORIAL:
        menu.InitializeTutorial();
        break;
    case MenuType::OUTRO:
        menu.InitializeOutro();
        break;
    case MenuType::EXIT:
        menu.InitializeExit();
        break;
    }
}

void Application::StartOutro()
{
    InitializeState(MenuType::OUTRO);
}

void Application::SetState(const GameState& state)
{
    gameState = state;
}


