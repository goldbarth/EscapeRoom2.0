//
// Created by goldbarth on 07.09.2023.
//

#include <iostream>
//#include <ncurses.h>
#include <conio.h>
#include <cstdlib>
#include "Windows.h"
#include "Application.h"


using namespace std;


void Application::Run()
{
     MainMenu();
}

void Application::MainMenu()
{
    DrawTitleScreen();
    DrawGameOptions();
    GameOptions(TITLE);
}

void Application::DrawTitleScreen()
{
    WriteLine("");
    WriteLine("   ###### ************************** * *  ");
    WriteLine("   ######                           *     ");
    WriteLine("   ##     #### #### #### #### ####     *  ");
    WriteLine("   ####   #    #    ## # ## # #           ");
    WriteLine("   ##     #### #    #### #### ###    *  * ");
    WriteLine("   ######    # #    ## # ##   #           ");
    WriteLine("   ###### #### #### ## # ##   ####     *  ");
    WriteLine("                                    *     ");
    WriteLine("   ############  =======================  ");
    WriteLine("   #          #   ######                  ");
    WriteLine("   #  @       ?   ##   # #### #### ##   # ");
    WriteLine("   #          #   #####  #  # #  # ### ## ");
    WriteLine("   #     $    #   ##   # #  # #  # ## # # ");
    WriteLine("   #          #   ##   # #  # #  # ##   # ");
    WriteLine("   ############   ##   # #### #### ##   # ");
    WriteLine("");
    WriteLine("");
}

void Application::DrawGameOptions()
{
    WriteLine("1. Start Game");
    WriteLine("2. Tutorial");
    WriteLine("3. Exit");
}

void Application::DrawTutorial()
{
    system("cls");
    Sleep(60);
    WriteLine("\n\n       ******** ESCAPE ROOM ********");
    WriteLine("        --------------------------");
    WriteLine("        ******** TUTORIAL ********");
    WriteLine("\n   At the start, the size of the Escape Room is determined.");
    WriteLine("   Height and width are set by input.");
    WriteLine("\n\n   The character moves by pressing the arrow keys: ^, v, <, >.");
    WriteLine("\n\n   The player is dropped at a random position in the Escape Room.");
    WriteLine("   The room has a locked door that can be opened with a key.");
    WriteLine("   The key can be found somewhere in the room.");
    WriteLine("   When collected, the door opens automatically.");
    WriteLine("\n\n   The game is won when the player goes through the door.");
}

void Application::GameOptions(Application::Screen screen)
{
    auto inputKey = GetInputOptions(screen);
    switch(inputKey)
    {
        case '1':
            cout << "Start Game" << endl;
            break;
        case '2':
            DrawTutorial();
            break;
        case '3':
            cout << "Exit" << endl;
            break;
        default:
            cerr << "Invalid input. Something went wrong at the." << endl;
            break;
    }


}

char Application::GetInputOptions(Application::Screen screen)
{
    char inputKey;
    bool valid;

    do
    {
        cin >> inputKey;
        // inputKey = (char)_getch(); // Maybe later with INPUT_RECORD, DWORD, PeekConsoleInput, etc.

        switch (screen)
        {
            case TITLE:
                valid = inputKey == '1' || inputKey == '2' || inputKey == '3';
                break;
            case DEFAULT:
                valid = inputKey == '1' || inputKey == '2';
                break;
        }

        if(!valid) WriteLine("Invalid input. Please try again.\n");
        else WriteLine("");

    } while(!valid);

    return inputKey;
}

void Application::WriteLine(const string& text)
{
    cout << text << endl;
}

