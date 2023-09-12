//
// Created by goldbarth on 11.09.2023.
//

#ifndef ESCAPEROOM2_0_MAINMENU_H
#define ESCAPEROOM2_0_MAINMENU_H

#include <Windows.h>
#include <algorithm>
#include <iostream>
#include "Application.h"
#include "Hlpr.h"

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

    void GameOptions(ScreenType screen);
    void ExitOptions(ScreenType screen);

    static void DrawTitleOptions();
    static void DrawTitleScreen();
    static void DrawOutroScreen();
    static void DrawGameOptions();
    static void DrawTutorial();
    static void DrawExitOptions();
    static void ExitApplication();

    static char GetInputOptions(ScreenType screen);
};

#endif //ESCAPEROOM2_0_MAINMENU_H
