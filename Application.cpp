//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"

void Application::Run()
{
     MainMenu();
}

void Application::MainMenu()
{
    DrawTitleScreen();
    DrawTitleOptions();
    GameOptions(TITLE);
}

void Application::DrawTitleScreen()
{
    Hlpr::WriteLine("");
    Hlpr::WriteLine("   ###### ************************** * *  ");
    Hlpr::WriteLine("   ######                           *     ");
    Hlpr::WriteLine("   ##     #### #### #### #### ####     *  ");
    Hlpr::WriteLine("   ####   #    #    ## # ## # #           ");
    Hlpr::WriteLine("   ##     #### #    #### #### ###    *  * ");
    Hlpr::WriteLine("   ######    # #    ## # ##   #           ");
    Hlpr::WriteLine("   ###### #### #### ## # ##   ####     *  ");
    Hlpr::WriteLine("                                    *     ");
    Hlpr::WriteLine("   ############  =======================  ");
    Hlpr::WriteLine("   #          #   ######                  ");
    Hlpr::WriteLine("   #  @       ?   ##   # #### #### ##   # ");
    Hlpr::WriteLine("   #          #   #####  #  # #  # ### ## ");
    Hlpr::WriteLine("   #     $    #   ##   # #  # #  # ## # # ");
    Hlpr::WriteLine("   #          #   ##   # #  # #  # ##   # ");
    Hlpr::WriteLine("   ############   ##   # #### #### ##   # ");
    Hlpr::WriteLine("");
    Hlpr::WriteLine("");
}

void Application::DrawOutroScreen()
{
    Hlpr::ClearScreen();
    Hlpr::WriteLine("");
    Hlpr::WriteLine("   ###### ******YOU ESCAPED THE***** * *  ");
    Hlpr::WriteLine("   ######                           *     ");
    Hlpr::WriteLine("   ##     #### #### #### #### ####     *  ");
    Hlpr::WriteLine("   ####   #    #    ## # ## # #           ");
    Hlpr::WriteLine("   ##     #### #    #### #### ###    *  * ");
    Hlpr::WriteLine("   ######    # #    ## # ##   #           ");
    Hlpr::WriteLine("   ###### #### #### ## # ##   ####     *  ");
    Hlpr::WriteLine("                                    *     ");
    Hlpr::WriteLine("   ############  =======================  ");
    Hlpr::WriteLine("   #          #   ######                  ");
    Hlpr::WriteLine("   #         ...@ ##   # #### #### ##   # ");
    Hlpr::WriteLine("   #          #   #####  #  # #  # ### ## ");
    Hlpr::WriteLine("   #          #   ##   # #  # #  # ## # # ");
    Hlpr::WriteLine("   #          #   ##   # #  # #  # ##   # ");
    Hlpr::WriteLine("   ############   ##   # #### #### ##   # ");
    Hlpr::WriteLine("");
    Hlpr::WriteLine("");
}

void Application::DrawTitleOptions()
{
    Hlpr::WriteLine("1. Start Game");
    Hlpr::WriteLine("2. Exit");
    Hlpr::WriteLine("3. Tutorial");
}

void Application::DrawGameOptions()
{
    Hlpr::WriteLine("1. Start Game");
    Hlpr::WriteLine("2. Exit");
}

void Application::DrawTutorial()
{
    Hlpr::ClearScreen();
    Hlpr::WriteLine("\n\n       ******** ESCAPE ROOM ********");
    Hlpr::WriteLine("        --------------------------");
    Hlpr::WriteLine("        ******** TUTORIAL ********");
    Hlpr::WriteLine("\n   At the start, the size of the Escape Room is determined.");
    Hlpr::WriteLine("   Height and width are set by input.");
    Hlpr::WriteLine("\n   The character moves by pressing the arrow keys: ^, v, <, >.");
    Hlpr::WriteLine("\n   The player is dropped at a random position in the Escape Room.");
    Hlpr::WriteLine("   The room has a locked door that can be opened with a key.");
    Hlpr::WriteLine("   The key can be found somewhere in the room.");
    Hlpr::WriteLine("   When collected, the door opens automatically.");
    Hlpr::WriteLine("\n\n   The game is won when the player goes through the door.");
    Hlpr::WriteLine("");
}

void Application::GameOptions(Application::Screen screen)
{
    auto inputKey = GetInputOptions(screen);
    switch(inputKey)
    {
        case '1':
            EnterGame();
            break;
        case '2':
            ExitApplication();
            break;
        case '3':
            EnterTutorial();
            break;
        default:
            std::cerr << "Invalid input. Something went wrong at GameOptions." << std::endl;
            break;
    }
}

char Application::GetInputOptions(Application::Screen screen)
{
    char inputKey;
    bool valid;

    do
    {
        std::cin >> inputKey;

        switch (screen)
        {
            case TITLE:
                valid = inputKey == '1' || inputKey == '2' || inputKey == '3';
                break;
            case DEFAULT:
                valid = inputKey == '1' || inputKey == '2';
                break;
        }

        if(!valid) Hlpr::WriteLine("Invalid input. Please try again.\n");
        else Hlpr::WriteLine("");

    } while(!valid);

    return inputKey;
}

void Application::EnterTutorial()
{
    DrawTutorial();
    DrawGameOptions();
    GameOptions(DEFAULT);
}

void Application::DrawOutro()
{
    DrawOutroScreen();
    DrawGameOptions();
    GameOptions(DEFAULT);
}

void Application::EnterGame()
{
    auto* game = new Game();
    game->Start();
    delete game;
}

void Application::ExitApplication()
{
    exit(0);
}

