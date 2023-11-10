//
// Created by goldbarth on 10.09.2023.
//

#include <Windows.h>
#include <iostream>
#include "csptr.h"

void csptr::Write(const std::string &text)
{
    std::cout << text;
}

void csptr::Write(const char& letter)
{
    std::cout << letter;
}

void csptr::Write(const char& letter, const Color& textColor)
{
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< letter << "\x1B[0m";
}

void csptr::WriteLine(const std::string& text)
{
    std::cout << text << std::endl;
}

void csptr::WriteLine(const char& letter)
{
    std::cout << letter << std::endl;
}

/// <summary>
/// Write a line at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in csptr.h.
/// </summary>
void csptr::WriteLineAt(const double& left, const double& top, const std::string &text, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< text << "\x1B[0m";
}

void csptr::WriteLineAt(const double &left, const double &top, const std::string &text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m"<< text << "\x1B[0m";
}

void csptr::WriteAt(const int& left, const int& top, const char& letter)
{
    SetConsoleCursorPos(left, top);
    std::cout << letter;
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in csptr.h.
/// </summary>
void csptr::WriteAt(const int& left, const int& top, const std::string& text, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< text << "\x1B[0m";
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in csptr.h.
/// </summary>
void csptr::WriteAt(const int& left, const int& top, const char& letter, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< letter << "\x1B[0m";
}

void csptr::SetConsoleColor(const Color& consoleColor)
{
    std::cout << "\x1B[" << static_cast<int>(consoleColor) << "m";
}

void csptr::SetConsoleCursorPos(const int& left, const int& top)
{
    COORD coord;
    coord.X = static_cast<SHORT>(left);
    coord.Y = static_cast<SHORT>(top);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void csptr::SetConsoleCursorPos(const double& left, const double& top)
{
    COORD coord;
    coord.X = static_cast<SHORT>(left);
    coord.Y = static_cast<SHORT>(top);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/// <summary>
/// Set the parameter to true to show the cursor.
/// Set it to false will hide the blinking bar/underscore.
/// Src: https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
/// </summary>
void csptr::ShowConsoleCursor(const bool& showCursor)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showCursor;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void csptr::ClearScreen()
{
    system("cls");
    Sleep(100);
}
