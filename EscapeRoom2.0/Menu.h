﻿//
// Created by goldbarth on 11.09.2023.
//

#ifndef ESCAPEROOM2_0_MAINMENU_H
#define ESCAPEROOM2_0_MAINMENU_H


#include "Application.h"
#include "csptr.h"

class Menu
{
public:
    explicit Menu(Application* app) : app(app) {}
    ~Menu();

    void InitializeMainMenu() const;
    void InitializeTutorial() const;
    void InitializeOutro() const;
    void InitializeExit() const;

private:
    enum ScreenType
    {
        Title,
        Default,
        Exit,
    };

    Application* app;

    void GameOptions(const ScreenType& screen, const std::vector<std::string>& options, const int& initialLine) const;
    void ExitOptions() const;

    static void DrawTitleScreen();
    static void DrawOutroScreen();
    static void DrawTutorial();
    static void DrawExitOptions();
    static void ExitApplication();

    static char GetInputOptions();
};

#endif //ESCAPEROOM2_0_MAINMENU_H
