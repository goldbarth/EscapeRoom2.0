//
// Created by goldbarth on 07.09.2023.
//

#include "Application.h"
#include <iostream>

using namespace std;


void Application::Run()
{
     MainMenu();
}

void Application::MainMenu()
{
    DrawTitleScreen();
}

void Application::GameOptions(enum Screen)
{

}

void Application::DrawTitleScreen()
{
    cout << "   ###### ************************** * *  " << endl;
    cout << "   ######                           *     " << endl;
    cout << "   ##     #### #### #### #### ####     *  " << endl;
    cout << "   ####   #    #    ## # ## # #           " << endl;
    cout << "   ##     #### #    #### #### ###    *  * " << endl;
    cout << "   ######    # #    ## # ##   #           " << endl;
    cout << "   ###### #### #### ## # ##   ####     *  " << endl;
    cout << "                                    *     " << endl;
    cout << "   ############  =======================  " << endl;
    cout << "   #          #   ######                  " << endl;
    cout << "   #  @       ?   ##   # #### #### ##   # " << endl;
    cout << "   #          #   #####  #  # #  # ### ## " << endl;
    cout << "   #     $    #   ##   # #  # #  # ## # # " << endl;
    cout << "   #          #   ##   # #  # #  # ##   # " << endl;
    cout << "   ############   ##   # #### #### ##   # " << endl;
    cout << "" << endl;
    cout << "" << endl;

}

void Application::DrawGameOptions()
{

}
