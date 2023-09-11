//
// Created by goldbarth on 10.09.2023.
//

#include "Hlpr.h"

void Hlpr::Write(const std::string &text)
{
    std::cout << text;
}

void Hlpr::Write(const char *text)
{
    std::cout << text;
}

void Hlpr::WriteLine(const std::string& text)
{
    std::cout << text << std::endl;
}

void Hlpr::WriteLine(const char& text)
{
    std::cout << text << std::endl;
}

void Hlpr::WriteLineAt(int left, int top, const std::string &text, const std::string &textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text << std::endl;
    std::cout << "\x1B[0m";
}

void Hlpr::WriteAt(int left, int top, const char& text)
{
    SetConsoleCursorPos(left, top);
    std::cout << text;
}

/// <summary>
/// Write text at a position with a textColor.
/// Insert the textColor over the ConsoleColor struct in Hlpr.h.
/// </summary>
void Hlpr::WriteAt(int left, int top, const std::string& text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text;
    std::cout << "\x1B[0m";
}

/// <summary>
/// Write text at a position with a textColor.
/// Insert the textColor over the ConsoleColor struct in Hlpr.h.
/// </summary>
void Hlpr::WriteAt(int left, int top, const char& text, const std::string& textColor)
{
    SetConsoleCursorPos(left, top);
    std::cout << "\x1B[" << textColor << "m";
    std::cout << text;
    std::cout << "\x1B[0m";
}

void Hlpr::SetConsoleCursorPos(int left, int top)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             {static_cast<SHORT>(left), static_cast<SHORT>(top) });
}

// https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
void Hlpr::ShowConsoleCursor(bool showFlag)
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
    Sleep(60);
}
