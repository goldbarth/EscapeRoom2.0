//
// Created by goldbarth on 11.09.2023.
//

#ifndef ESCAPEROOM2_0_MAINMENU_H
#define ESCAPEROOM2_0_MAINMENU_H

#include <Windows.h>
#include <algorithm>
#include <iostream>
#include "Application.h"
#include "csptr.h"

class Menu
{
public:
    inline explicit Menu(Application* app) : app(app) {}
    inline ~Menu() = default;

    void InitializeMainMenu();
    void InitializeTutorial();
    void InitializeOutro();
    void InitializeExit();

private:
    enum ScreenType
    {
        Title,
        Default,
        Exit,
    };

    Application* app;

    void GameOptions(const ScreenType& screen, const std::vector<std::string>& options, const int& initialLine);
    void ExitOptions(const ScreenType& screen);

    static void DrawTitleScreen();
    static void DrawOutroScreen();
    static void DrawTutorial();
    static void DrawExitOptions();
    static void ExitApplication();

    static char GetInputOptions(const ScreenType& screen);
};

#endif //ESCAPEROOM2_0_MAINMENU_H
