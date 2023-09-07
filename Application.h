//
// Created by goldbarth on 07.09.2023.
//

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
        TUTORIAL,
        OUTRO,
        DEFAULT
    };

    void MainMenu();
    void DrawTitleScreen();
    void DrawGameOptions();
    void DrawTutorial();
    void GameOptions(Application::Screen screen);
    char GetInputOptions(Application::Screen screen);

    static void WriteLine(const std::string& text);
};


#endif //ESCAPEROOM2_0_APPLICATION_H
