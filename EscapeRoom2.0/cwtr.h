//
// Created by goldbarth on 10.09.2023.
//

// A custom console class to write text and manipulate the console.
// cwtr stands for "Console Writer".

#ifndef ESCAPEROOM2_0_CSPTR_H
#define ESCAPEROOM2_0_CSPTR_H

#include <string>

enum class Color
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    Gray = 37,
    DarkGray = 90,
    LightRed = 91,
    LightGreen = 92,
    LightYellow = 93,
    LightBlue = 94,
    LightMagenta = 95,
    LightCyan = 96,
    White = 97,
    Reset = 0,
    BgBlack = 40,
    BgRed = 41,
    BgGreen = 42,
    BgYellow = 43,
    BgBlue = 44,
    BgMagenta = 45,
    BgCyan = 46,
    BgGray = 47,
    BgDarkGray = 100,
    BgLightRed = 101,
    BgLightGreen = 102,
    BgLightYellow = 103,
    BgLightBlue = 104,
    BgLightMagenta = 105,
    BgLightCyan = 106,
    BgWhite = 107,
    BgReset = 49
};

class cwtr
{
public:
    static void Read(std::string& text);
    static void Read(int& text);

    static void Write(const char& letter);
    static void Write(const std::string& text);
    static void Write(const char &letter, const Color &textColor);

    static void WriteAt(const int& left, const int& top, const char& letter);
    static void WriteAt(const int& left, const int& top, const char& letter,  const Color& textColor);
    static void WriteAt(const int& left, const int& top, const std::string& text, const Color& textColor);

    static void WriteLine(const char& letter);
    static void WriteLine(const std::string& text);

    static void WriteLineAt(const double& left, const double& top, const std::string& text, const Color& textColor);
    static void WriteLineAt(const double& left, const double& top, const std::string& text, const std::string& textColor);

    static void SetConsoleCursorPos(const double& left, const double& top);
    static void SetConsoleCursorPos(const int &left, const int &top);

    static void SetConsoleColor(const Color& consoleColor);

    static void ShowConsoleCursor(const bool& showCursor);

    static void ClearScreen();
};


#endif //ESCAPEROOM2_0_CSPTR_H
