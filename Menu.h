//
// Created by goldbarth on 11.09.2023.
//

#ifndef ESCAPEROOM2_0_MAINMENU_H
#define ESCAPEROOM2_0_MAINMENU_H

#include <Windows.h>
#include <iostream>
#include "Application.h"
#include "Hlpr.h"

class Menu
{
public:
    inline explicit Menu(Application* app) : app(app) {}

    void InitializeMainMenu();
    void InitializeTutorial();
    void InitializeOutro();

private:
    enum Screen
    {
        Title,
        Default
    };

    Application* app{};

    void Options(Menu::Screen screen);

    static void DrawTitleOptions();
    static void DrawTitleScreen();
    static void DrawOutroScreen();
    static void DrawGameOptions();
    static void DrawTutorial();

    static char GetInputOptions(Screen screen);
};

#endif //ESCAPEROOM2_0_MAINMENU_H
