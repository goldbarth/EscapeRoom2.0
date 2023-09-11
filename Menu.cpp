//
// Created by goldbarth on 11.09.2023.
//

#include "Menu.h"

void Menu::InitializeMainMenu()
{
    DrawTitleScreen();
    DrawTitleOptions();
    Options(Title);
}

void Menu::InitializeOutro()
{
    DrawOutroScreen();
    DrawGameOptions();
    Options(Default);
}

void Menu::InitializeTutorial()
{
    DrawTutorial();
    DrawGameOptions();
    Options(Default);
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

void Menu::Options(Menu::Screen screen) // NOLINT(*-no-recursion)
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
            std::cerr << "Invalid input. Something went wrong at Options." << std::endl;
            break;
    }
}

char Menu::GetInputOptions(Menu::Screen screen)
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
        }

        if(!valid) Hlpr::WriteLine("Invalid input. Please try again.\n");
        else Hlpr::WriteLine("");

    } while(!valid);

    return inputKey;
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
