//
// Created by goldbarth on 11.09.2023.
//

#include <random>
#include "Menu.h"


void Menu::InitializeMainMenu()
{
    DrawTitleScreen();
    std::vector<std::string> options = {"Start Game", "Exit Application", "StartTutorial"};
    GameOptions(Title, options, 16);
}

void Menu::InitializeOutro()
{
    DrawOutroScreen();
    std::vector<std::string> options = {"Main Menu", "Exit Application"};
    GameOptions(Default, options, 18);
}

void Menu::InitializeTutorial()
{
    DrawTutorial();
    std::vector<std::string> options = {"Main Menu", "Exit Application"};
    GameOptions(Default, options, 18);
}

void Menu::InitializeExit()
{
    DrawExitOptions();
    ExitOptions();
}

void Menu::DrawExitOptions()
{
    csptr::WriteLine("Do you really want to exit?");
    csptr::WriteLine("(y/n)");
}

void Menu::DrawTitleScreen()
{
    csptr::ClearScreen();
    csptr::WriteLine("");
    csptr::WriteLine("   ###### ************************** * *  ");
    csptr::WriteLine("   ######                           *     ");
    csptr::WriteLine("   ##     #### #### #### #### ####     *  ");
    csptr::WriteLine("   ####   #    #    ## # ## # #           ");
    csptr::WriteLine("   ##     #### #    #### #### ###    *  * ");
    csptr::WriteLine("   ######    # #    ## # ##   #           ");
    csptr::WriteLine("   ###### #### #### ## # ##   ####     *  ");
    csptr::WriteLine("                                    *     ");
    csptr::WriteLine("   ############  =======================  ");
    csptr::WriteLine("   #          #   ######                  ");
    csptr::WriteLine("   #  @       ?   ##   # #### #### ##   # ");
    csptr::WriteLine("   #          #   #####  #  # #  # ### ## ");
    csptr::WriteLine("   #     $    #   ##   # #  # #  # ## # # ");
    csptr::WriteLine("   #          #   ##   # #  # #  # ##   # ");
    csptr::WriteLine("   ############   ##   # #### #### ##   # ");
    csptr::WriteLine("");
    csptr::WriteLine("");
}

void Menu::DrawOutroScreen()
{
    csptr::ClearScreen();
    csptr::WriteLine("");
    csptr::WriteLine("   ###### ******YOU ESCAPED THE***** * *  ");
    csptr::WriteLine("   ######                           *     ");
    csptr::WriteLine("   ##     #### #### #### #### ####     *  ");
    csptr::WriteLine("   ####   #    #    ## # ## # #           ");
    csptr::WriteLine("   ##     #### #    #### #### ###    *  * ");
    csptr::WriteLine("   ######    # #    ## # ##   #           ");
    csptr::WriteLine("   ###### #### #### ## # ##   ####     *  ");
    csptr::WriteLine("                                    *     ");
    csptr::WriteLine("   ############  =======================  ");
    csptr::WriteLine("   #          #   ######                  ");
    csptr::WriteLine("   #         ...@ ##   # #### #### ##   # ");
    csptr::WriteLine("   #          #   #####  #  # #  # ### ## ");
    csptr::WriteLine("   #          #   ##   # #  # #  # ## # # ");
    csptr::WriteLine("   #          #   ##   # #  # #  # ##   # ");
    csptr::WriteLine("   ############   ##   # #### #### ##   # ");
    csptr::WriteLine("");
    csptr::WriteLine("");
}

void Menu::DrawTutorial()
{
    csptr::ClearScreen();
    csptr::WriteLine("\n\n                   ******** ESCAPE ROOM ********");
    csptr::WriteLine("                    --------------------------");
    csptr::WriteLine("                    ******** TUTORIAL ********");
    csptr::WriteLine("\n     At the start, the size of the Escape Room is determined.");
    csptr::WriteLine("                  Height and width are set by input.");
    csptr::WriteLine("\n    The character moves by pressing the arrow keys: ^, v, <, >.");
    csptr::WriteLine("\n   The player is dropped at a random position in the Escape Room.");
    csptr::WriteLine("     The room has a locked door that can be opened with a key.");
    csptr::WriteLine("            The key can be found somewhere in the room.");
    csptr::WriteLine("           When collected, the door opens automatically.");
    csptr::WriteLine("\n\n       The game is won when the player goes through the door.");
    csptr::WriteLine("");
}

void Menu::GameOptions(const ScreenType& screen, const std::vector<std::string>& options, const int& initialLine)
{
    const int numOptions = (int)options.size();
    int currentLine = initialLine;
    int currentOption = 0;
    bool hasChosen = false;

    while (!hasChosen)
    {
        // Clear only the part of the console where the options are displayed
        for (int i = 0; i < numOptions + 1; ++i)
        {
            csptr::SetConsoleCursorPos(0, currentLine);
            csptr::Write(std::string(80, ' '));
            currentLine++;
        }

        // Draw menu options with highlighting
        for (int i = 0; i < numOptions; ++i)
        {
            // Set cursor position to the beginning of the line
            csptr::SetConsoleCursorPos(0, currentLine);

            // Set background color to yellow if the option is selected
            if (i == currentOption)
            {
                csptr::SetConsoleColor(Color::BgDarkGray);
                csptr::SetConsoleColor(Color::Black);
                csptr::WriteLine(">" + options[i] + "\x1B[0m");
            }
            else
            {
                csptr::SetConsoleColor(Color::BgReset);
                csptr::WriteLine(" " + options[i] + "\x1B[0m");
            }

            currentLine++;
        }

        char key = (char)_getch();

        // If enter was pressed then the user has chosen an option
        if (key == 13)
        {
            hasChosen = true;
            switch (currentOption)
            {
                case 0:
                    app->SetState(screen == Title ? GameState::Game : GameState::MainMenu);
                    break;
                case 1:
                    app->SetState(GameState::Exit);
                    break;
                case 2:
                    app->SetState(GameState::Tutorial);
                    break;
                default:
                    std::cerr << "Invalid input. Something went wrong at GameOptions." << std::endl;
                    break;
            }
        }

        if (key == 'w' && currentOption > 0)
            currentOption--;

        if (key == 's' && currentOption < numOptions - 1)
            currentOption++;

        currentLine = initialLine;
    }
}

void Menu::ExitOptions()
{
    auto inputKey = GetInputOptions();
    switch(inputKey)
    {
        case 'y':
            ExitApplication();
            break;
        case 'n':
            app->SetState(GameState::MainMenu);
            break;
        default:
            std::cerr << "Invalid input. Something went wrong at Exit Options." << std::endl;
            break;
    }
}

char Menu::GetInputOptions()
{
    char inputKey;
    bool valid;

    do
    {
        std::cin >> inputKey;

        valid = inputKey == 'y' || inputKey == 'n';
        if(!valid) csptr::WriteLine("Invalid input. Please try again.\n");
        else csptr::WriteLine("");

    } while(!valid);

    return inputKey;
}

void Menu::ExitApplication()
{
    csptr::WriteLine("Console is closing...\n");
    csptr::WriteLine("Bye, bye. See you next time.\n");
    Sleep(1000);
    csptr::WriteLine("<whisper> Bye.");
    Sleep(3000);
    csptr::ClearScreen();

    std::srand(static_cast<unsigned>(time(nullptr)));
    std::string farewell[13] = {"Bye", "Ciao", "Tschuess", "Adios", "Aloha", "Dovizhdane", "Ade", "Adieu", "Arrivederci",
                                "Au revoir", "Auf Wiedersehen", "Bless", "Bon voyage"};
    // Shuffle the farewell array randomly
    std::shuffle(std::begin(farewell), std::end(farewell), std::mt19937(std::random_device()()));
    for (const auto & i : farewell) // Foreach loop
    {
        for (int j = 13; j < 37; ++j)
        {
            // Range from 0 to 79 columns and 0 to 23 rows
            int k = rand() % 80;
            int n = rand() % 24;

            csptr::WriteLineAt(k, n, i, std::to_string(j));
            Beep(10 * k, 100);
        }
    }

    exit(0);
}
