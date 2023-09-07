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
    };

    void MainMenu();
    void DrawTitleScreen();
    void DrawGameOptions();
    void GameOptions(enum Screen);
};


#endif //ESCAPEROOM2_0_APPLICATION_H
