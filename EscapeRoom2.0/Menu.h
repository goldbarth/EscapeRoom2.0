//
// Created by goldbarth on 11.09.2023.
//

#ifndef ESCAPEROOM2_0_MAINMENU_H
#define ESCAPEROOM2_0_MAINMENU_H


#include "Application.h"
#include "cwtr.h"

class Menu
{
public:
    explicit Menu(Application* app) : app(app) {}
    ~Menu() = default;

    void MainMenuOptions() const;
    void InitializeMainMenu() const;
    void InitializeTutorial() const;
    void InitializeOutro() const;
    void DefaultOptions() const;
    void InitializeExit() const;

private:
    enum ScreenType
    {
        TITLE,
        DEFAULT,
        EXIT,
    };

    // A raw pointer is used to avoid circular dependencies.
    Application* app;

    void GameOptions(const ScreenType& screen, const std::vector<std::string>& options, const int& initialLine) const;
    void ExitOptions() const;

    static void DrawTitleBanner();
    static void DrawEscapeBanner();
    static void DisplayRules();
    static void DrawExitOptions();
    static void ExitApplication();

    static char GetInputOptions();
};

#endif //ESCAPEROOM2_0_MAINMENU_H
