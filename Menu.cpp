//
// Created by goldbarth on 11.09.2023.
//

#include "Menu.h"

#include <random>


void Menu::InitializeMainMenu()
{
    DrawTitleScreen();
    DrawTitleOptions();
    GameOptions(Title);
}

void Menu::InitializeOutro()
{
    DrawOutroScreen();
    DrawGameOptions();
    GameOptions(Default);
}

void Menu::InitializeTutorial()
{
    DrawTutorial();
    DrawGameOptions();
    GameOptions(Default);
}

void Menu::InitializeExit()
{
    DrawExitOptions();
    ExitOptions(Exit);
}

void Menu::DrawGameOptions()
{
    Hlpr::WriteLine("1. Main Menu");
    Hlpr::WriteLine("2. Exit");
}

void Menu::DrawTitleOptions()
{
    Hlpr::WriteLine("1. Start Game");
    Hlpr::WriteLine("2. Exit");
    Hlpr::WriteLine("3. Tutorial");
}

void Menu::DrawExitOptions()
{
    Hlpr::WriteLine("Do you really want to exit?");
    Hlpr::WriteLine("(y/n)");
}

void Menu::DrawTitleScreen()
{
    Hlpr::ClearScreen();
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

void Menu::DrawOutroScreen()
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

void Menu::DrawTutorial()
{
    Hlpr::ClearScreen();
    Hlpr::WriteLine("\n\n                   ******** ESCAPE ROOM ********");
    Hlpr::WriteLine("                    --------------------------");
    Hlpr::WriteLine("                    ******** TUTORIAL ********");
    Hlpr::WriteLine("\n     At the start, the size of the Escape Room is determined.");
    Hlpr::WriteLine("                  Height and width are set by input.");
    Hlpr::WriteLine("\n    The character moves by pressing the arrow keys: ^, v, <, >.");
    Hlpr::WriteLine("\n   The player is dropped at a random position in the Escape Room.");
    Hlpr::WriteLine("     The room has a locked door that can be opened with a key.");
    Hlpr::WriteLine("            The key can be found somewhere in the room.");
    Hlpr::WriteLine("           When collected, the door opens automatically.");
    Hlpr::WriteLine("\n\n       The game is won when the player goes through the door.");
    Hlpr::WriteLine("");
}

void Menu::GameOptions(ScreenType screen) // NOLINT(*-no-recursion)
{
    auto inputKey = GetInputOptions(screen);
    switch(inputKey)
    {
        case '1':
            app->SetState(screen == Title ?  GameState::Game : GameState::MainMenu);
            break;
        case '2':
            app->SetState(GameState::Exit);
            break;
        case '3':
            app->SetState(GameState::Tutorial);
            break;
        default:
            std::cerr << "Invalid input. Something went wrong at GameOptions." << std::endl;
            break;
    }
}

void Menu::ExitOptions(ScreenType screen)
{
    auto inputKey = GetInputOptions(screen);
    switch(inputKey)
    {
        case 'y':
            ExitApplication();
            break;
        case 'n':
            app->SetState(GameState::MainMenu);
            break;
        default:
            std::cerr << "Invalid input. Something went wrong at GameOptions." << std::endl;
            break;
    }
}

char Menu::GetInputOptions(Menu::ScreenType screen)
{
    char inputKey;
    bool valid;

    do
    {
        std::cin >> inputKey;

        switch (screen)
        {
            case Title:
                valid = inputKey == '1' || inputKey == '2' || inputKey == '3';
                break;
            case Default:
                valid = inputKey == '1' || inputKey == '2';
                break;
            case Exit:
                valid = inputKey == 'y' || inputKey == 'n';
                break;
        }

        if(!valid) Hlpr::WriteLine("Invalid input. Please try again.\n");
        else Hlpr::WriteLine("");

    } while(!valid);

    return inputKey;
}

void Menu::ExitApplication()
{
    Hlpr::WriteLine("Console is closing...\n");
    Hlpr::WriteLine("Bye, bye. See you next time.\n");
    Sleep(1000);
    Hlpr::WriteLine("<whisper> Bye.");
    Sleep(3000);
    Hlpr::ClearScreen();

    std::srand(static_cast<unsigned>(time(nullptr)));
    std::string farewell[13] = {"Bye", "Ciao", "Tschuess", "Adios", "Aloha", "Dovizhdane", "Ade", "Adieu", "Arrivederci",
                                "Au revoir", "Auf Wiedersehen", "Bless", "Bon voyage"};
    // Shuffle the farewell array randomly
    std::shuffle(std::begin(farewell), std::end(farewell), std::mt19937(std::random_device()()));
    for (const auto & i : farewell) // Foreach loop
    {
        for (int j = 30; j < 37; ++j)
        {
            // Range from 0 to 79 columns and 0 to 23 rows
            int k = rand() % 80;
            int n = rand() % 24;

            Hlpr::WriteLineAt(k, n, i, std::to_string(j));
            Beep(10 * k, 100);
        }
    }

    exit(0);
}
