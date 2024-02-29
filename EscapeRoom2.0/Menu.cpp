//
// Created by goldbarth on 11.09.2023.
//

#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <random>

#include "Defines.h"
#include "Menu.h"

void Menu::InitializeMainMenu() const
{
    DrawTitleBanner();
    MainMenuOptions();
}

void Menu::InitializeOutro() const
{
    DrawEscapeBanner();
    DefaultOptions();
}

void Menu::InitializeTutorial() const
{
    DisplayRules();
    DefaultOptions();
}

void Menu::InitializeExit() const
{
    DrawExitOptions();
    ExitOptions();
}

void Menu::DrawExitOptions()
{
    cwtr::WriteLine("Do you really want to exit?");
    cwtr::WriteLine("(y/n)");
}

void Menu::DrawTitleBanner()
{
    const std::vector<std::string> lines =
    {
        "",
        "   ###### ************************** * *  ",
        "   ######                           *     ",
        "   ##     #### #### #### #### ####     *  ",
        "   ####   #    #    ## # ## # #           ",
        "   ##     #### #    #### #### ###    *  * ",
        "   ######    # #    ## # ##   #           ",
        "   ###### #### #### ## # ##   ####     *  ",
        "                                    *     ",
        "   ############  =======================  ",
        "   #          #   ######                  ",
        "   #  @       ?   ##   # #### #### ##   # ",
        "   #          #   #####  #  # #  # ### ## ",
        "   #     $    #   ##   # #  # #  # ## # # ",
        "   #          #   ##   # #  # #  # ##   # ",
        "   ############   ##   # #### #### ##   # ",
        "",
        ""
    };

    cwtr::ClearScreen();

    for (const auto& line : lines)
    {
        cwtr::WriteLine(line);
    }
}

void Menu::DrawEscapeBanner()
{
    const std::vector<std::string> lines =
    {
        "",
        "   ###### ******YOU ESCAPED THE***** * *  ",
        "   ######                           *     ",
        "   ##     #### #### #### #### ####     *  ",
        "   ####   #    #    ## # ## # #           ",
        "   ##     #### #    #### #### ###    *  * ",
        "   ######    # #    ## # ##   #           ",
        "   ###### #### #### ## # ##   ####     *  ",
        "                                    *     ",
        "   ############  =======================  ",
        "   #          #   ######                  ",
        "   #         ...@ ##   # #### #### ##   # ",
        "   #          #   #####  #  # #  # ### ## ",
        "   #          #   ##   # #  # #  # ## # # ",
        "   #          #   ##   # #  # #  # ##   # ",
        "   ############   ##   # #### #### ##   # ",
        "",
        ""
    };

    cwtr::ClearScreen();

    for (const auto& line : lines)
    {
        cwtr::WriteLine(line);
    }
}

void Menu::DisplayRules()
{
    const std::vector<std::string> lines =
    {
        "\n\n                   ******** ESCAPE ROOM ********",
        "                    --------------------------",
        "                    ********* RULES *********",
        "\n     At the start, the size of the Escape Room is determined.",
        "                  Height and width are set by input.",
        "\n    The character moves by pressing the arrow keys: ^, v, <, >.",
        "\n   The player is dropped at a random position in the Escape Room.",
        "     The room has a locked door that can be opened with a key.",
        "            The key can be found somewhere in the room.",
        "           When collected, the door opens automatically.",
        "\n\n       The game is won when the player goes through the door.",
        ""
    };

    cwtr::ClearScreen();

    for (const auto& line : lines)
    {
        cwtr::WriteLine(line);
    }
}

void Menu::MainMenuOptions() const
{
    std::vector<std::string> options = {"Start Game", "Exit Application", "Rules"};
    GameOptions(TITLE, options, INITIAL_LINE_MAIN);
}

void Menu::DefaultOptions() const
{
    std::vector<std::string> options = {"Main Menu", "Exit Application"};
    GameOptions(DEFAULT, options, INITIAL_LINE_OPTIONS);
}

void Menu::GameOptions(const ScreenType& screen, const std::vector<std::string>& options, const int& initialLine) const
{
    const int numOptions = static_cast<int>(options.size());
    int currentLine = initialLine;
    int currentOption = 0;
    bool hasSelected = false;

    while (!hasSelected)
    {
        int startPos = 0;
        // Clear only the part of the console where the options are displayed
        for (int i = 0; i < numOptions + 1; ++i)
        {
            constexpr char spaceChar = ' ';
            cwtr::SetConsoleCursorPos(startPos, currentLine);
            cwtr::Write(std::string(PADDING_CHARS, spaceChar));
            currentLine++;
        }

        // Draw menu options with highlighting
        for (int i = 0; i < numOptions; ++i)
        {
            cwtr::SetConsoleCursorPos(startPos, currentLine);
            
            if (i == currentOption)
            {
                cwtr::SetConsoleColor(Color::BgDarkGray);
                cwtr::SetConsoleColor(Color::Black);
                cwtr::WriteLine(">" + options[i] + "\x1B[0m");
            }
            else
            {
                cwtr::SetConsoleColor(Color::BgReset);
                cwtr::WriteLine(" " + options[i] + "\x1B[0m");
            }

            currentLine++;
        }

        char key = static_cast<char>(_getch());
        if (key == KEY_CODE_ENTER)
        {
            hasSelected = true;
            switch (currentOption)
            {
                case 0:
                    app->SetState(screen == TITLE ? GameState::GAME : GameState::MAIN_MENU);
                    break;
                case 1:
                    app->SetState(GameState::EXIT);
                    break;
                case 2:
                    app->SetState(GameState::TUTORIAL);
                    break;
            default:
                    cwtr::WriteLine("Invalid input. Something went wrong at GameOptions.");
                    break;
            }
        }
        
        if (key == KEY_CODE_UP && currentOption > 0)
            currentOption--;

        if (key == KEY_CODE_DOWN && currentOption < numOptions - 1)
            currentOption++;

        currentLine = initialLine;
    }
}

void Menu::ExitOptions() const
{
    const auto inputKey = GetInputOptions();
    switch(inputKey)
    {
        case CONFIRM_KEY:
            ExitApplication();
            break;
        case CANCEL_KEY:
            app->SetState(GameState::MAIN_MENU);
            break;
        default:
            cwtr::WriteLine("Invalid input. Something went wrong at ExitOptions.");
            break;
    }
}

char Menu::GetInputOptions()
{
    char inputKey;
    bool valid;

    do
    {
        cwtr::Read(inputKey);
        valid = inputKey == CONFIRM_KEY || inputKey == CANCEL_KEY;
        if(!valid) cwtr::WriteLine("Invalid input. Please try again.\n");
        else cwtr::WriteLine("");

    } while(!valid);

    return inputKey;
}

[[noreturn]]void Menu::ExitApplication()
{
    cwtr::WriteLine("Console is closing...\n");
    cwtr::WriteLine("Bye, bye. See you next time.\n");
    Sleep(1000);
    cwtr::WriteLine("<whisper> Bye.");
    Sleep(3000);
    cwtr::ClearScreen();

    std::srand(static_cast<unsigned>(time(nullptr)));
    std::string farewell[13] = {"Bye", "Ciao", "Tschuess", "Adios", "Aloha", "Dovizhdane", "Ade", "Adieu", "Arrivederci",
                                "Au revoir", "Auf Wiedersehen", "Bless", "Bon voyage"};
    // Shuffle the farewell array randomly
    std::shuffle(std::begin(farewell), std::end(farewell), std::mt19937(std::random_device()()));
    for (const auto & i : farewell) // Foreach loop
    {
        for (int j = 0; j < 3; ++j)
        {
            // Range from 0 to 79 columns and 0 to 23 rows
            const int k = rand() % 80;
            const int n = rand() % 24;

            cwtr::WriteLineAt(k, n, i, std::to_string(j));
            Beep(10 * k, 100);
        }
    }

    exit(0);
}
