//
// Created by goldbarth on 10.09.2023.
//

#include "Hlpr.h"

void Hlpr::Write(const std::string &text)
{
    std::cout << text;
}

void Hlpr::Write(const char& text)
{
    std::cout << text;
}

void Hlpr::WriteLine(const std::string& text)
{
    std::cout << text << std::endl;
}

void Hlpr::WriteLine(const char& letter)
{
    std::cout << letter << std::endl;
}

/// <summary>
/// Write a line at a cursor position with a textColor.
/// Insert the textColor over the ColorCode struct in Hlpr.h.
/// </summary>
void Hlpr::WriteLineAt(const double& left, const double& top, const std::string &text, const std::string &textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text << std::endl;
    std::cout << "\x1B[0m";
}

void Hlpr::WriteAt(const int& left, const int& top, const char& letter)
{
    SetConsoleCursorPos(left, top);
    std::cout << letter;
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ColorCode struct in Hlpr.h.
/// </summary>
void Hlpr::WriteAt(const int& left, const int& top, const std::string& text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text;
    std::cout << "\x1B[0m";
}

/// <summary>
/// Write at a cursor position with a textColor.
/// Insert the textColor over the ColorCode struct in Hlpr.h.
/// </summary>
void Hlpr::WriteAt(const int& left, const int& top, const char& text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text;
    std::cout << "\x1B[0m";
}

void Hlpr::SetConsoleCursorPos(const double& left, const double& top)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             {static_cast<SHORT>(left), static_cast<SHORT>(top) });
}

/// <summary>
/// Set the parameter to true to show the cursor.
/// Set it to false will hide the blinking bar/underscore.
/// Src: https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
/// </summary>
void Hlpr::ShowConsoleCursor(const bool& showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Hlpr::ClearScreen()
{
    system("cls");
    Sleep(100);
}
