//
// Created by goldbarth on 10.09.2023.
//

#include <Windows.h>
#include <iostream>
#include "cwtr.h"

void cwtr::Read(std::string& text)
{
    std::cin >> text;
}

void cwtr::Read(char& letter)
{
    std::cin >> letter;
}

void cwtr::Read(int& number)
{
    std::cin >> number;
}

void cwtr::Write(const std::string &text)
{
    std::cout << text;
}

void cwtr::Write(const char& letter)
{
    std::cout << letter;
}

void cwtr::Write(const char& letter, const Color& textColor)
{
    const int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< letter << "\x1B[0m";
}

void cwtr::WriteLine(const std::string& text)
{
    std::cout << text << '\n';
}

void cwtr::WriteLine(const char& letter)
{
    std::cout << letter << '\n';
}

/// <summary>
/// Write a line at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in cwtr.h.
/// </summary>
void cwtr::WriteLineAt(const double& left, const double& top, const std::string &text, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< text << "\x1B[0m";
}

void cwtr::WriteLineAt(const double &left, const double &top, const std::string &text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m"<< text << "\x1B[0m";
}

void cwtr::WriteAt(const int& left, const int& top, const char& letter)
{
    SetConsoleCursorPos(left, top);
    std::cout << letter;
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in cwtr.h.
/// </summary>
void cwtr::WriteAt(const int& left, const int& top, const std::string& text, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< text << "\x1B[0m";
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ConsoleColor struct in cwtr.h.
/// </summary>
void cwtr::WriteAt(const int& left, const int& top, const char& letter, const Color& textColor)
{
    SetConsoleCursorPos(left, top);
    int colorCode = static_cast<int>(textColor);
    std::cout << "\x1B[" << colorCode << "m"<< letter << "\x1B[0m";
}

void cwtr::SetConsoleColor(const Color& consoleColor)
{
    std::cout << "\x1B[" << static_cast<int>(consoleColor) << "m";
}

void cwtr::SetConsoleCursorPos(const int& left, const int& top)
{
    COORD coord;
    coord.X = static_cast<SHORT>(left);
    coord.Y = static_cast<SHORT>(top);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void cwtr::SetConsoleCursorPos(const double& left, const double& top)
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
void cwtr::ShowConsoleCursor(const bool& showCursor)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showCursor;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void cwtr::ClearScreen()
{
    system("cls");
    Sleep(100);
}
