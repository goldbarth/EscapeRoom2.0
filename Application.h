//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>
//#include <ncurses.h>
//#include <conio.h>
#include "Windows.h"
#include "Game.h"

#ifndef ESCAPEROOM2_0_APPLICATION_H
#define ESCAPEROOM2_0_APPLICATION_H


class Application
{
public:
    void Run();

private:
    enum Screen
    {
        TITLE,
        DEFAULT
    };

    //Game* game;

    void MainMenu();
    void EnterGame();
    void EnterTutorial();

    void DrawTitleOptions();
    void DrawTitleScreen();
    void DrawOutroScreen();
    void DrawGameOptions();
    void DrawTutorial();


    void GameOptions(Application::Screen screen);
    char GetInputOptions(Application::Screen screen);

    static void ExitApplication();
    static void WriteLine(const std::string& text);
};


#endif //ESCAPEROOM2_0_APPLICATION_H
