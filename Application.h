//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>
#include "Windows.h"
#include "Hlpr.h"
#include "Game.h"

#ifndef ESCAPEROOM2_0_APPLICATION_H
#define ESCAPEROOM2_0_APPLICATION_H


class Application
{
public:
    void Run();
    void DrawOutro();

private:
    enum Screen
    {
        TITLE,
        DEFAULT
    };

    ConsoleColor color;

    void MainMenu();
    void EnterTutorial();
    void GameOptions(Application::Screen screen);

    static void EnterGame();
    static void DrawTitleOptions();
    static void DrawTitleScreen();
    static void DrawOutroScreen();
    static void DrawGameOptions();
    static void DrawTutorial();
    static void ExitApplication();

    static char GetInputOptions(Application::Screen screen);

};


#endif //ESCAPEROOM2_0_APPLICATION_H
