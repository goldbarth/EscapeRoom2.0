//
// Created by goldbarth on 10.09.2023.
//


#ifndef ESCAPEROOM2_0_HLPR_H
#define ESCAPEROOM2_0_HLPR_H

#include <Windows.h>
#include <iostream>
#include <string>

struct ConsoleColor
{
    // Foreground (text)
    static std::string black()
    {
        return "30"; // Black color code
    }
    static std::string red()
    {
        return "31"; // Red color code
    }
    static std::string green()
    {
        return "32"; // Green color code
    }
    static std::string yellow()
    {
        return "33"; // Yellow color code
    }
    static std::string blue()
    {
        return "34"; // Blue color code
    }
    static std::string magenta()
    {
        return "35"; // Magenta color code
    }
    static std::string cyan()
    {
        return "36"; // Cyan color code
    }
    static std::string gray()
    {
        return "37"; // Gray color code
    }
    static std::string dark_gray()
    {
        return "90"; // Dark gray color code
    }
    static std::string light_red()
    {
        return "91"; // Light red color code
    }
    static std::string light_green()
    {
        return "92"; // Light green color code
    }
    static std::string light_yellow()
    {
        return "93"; // Light yellow color code
    }
    static std::string light_blue()
    {
        return "94"; // Light blue color code
    }
    static std::string light_magenta()
    {
        return "95"; // Light magenta color code
    }
    static std::string light_cyan()
    {
        return "96"; // Light cyan color code
    }
    static std::string white()
    {
        return "97"; // White color code
    }

    // Background
    std::string bg_black = "40";
    std::string bg_red = "41";
    std::string bg_green = "42";
    std::string bg_yellow = "43";
    std::string bg_blue = "44";
    std::string bg_magenta = "45";
    std::string bg_cyan = "46";
    std::string bg_gray = "47";
    std::string bg_dark_gray = "100";
    std::string bg_light_red = "101";
    std::string bg_light_green = "102";
    std::string bg_light_yellow = "103";
    std::string bg_light_blue = "104";
    std::string bg_light_magenta = "105";
    std::string bg_light_cyan = "106";
    std::string bg_white = "107";
};

class Hlpr
{
    public:
        static ConsoleColor color;

        static void Write(const std::string& text);
        static void Write(const char& text);

        static void WriteAt(int left, int top, const std::string& text, const std::string& textColor);
        static void WriteAt(int left, int top, const char& letter);
        static void WriteAt(int left, int top, const char& text, const std::string& textColor);

        static void WriteLine(const std::string& text);
        static void WriteLine(const char& letter);

        static void WriteLineAt(int left, int top, const std::string& text, const std::string& textColor);

        static void ClearScreen();
        static void SetConsoleCursorPos(int left, int top);
        static void ShowConsoleCursor(bool showFlag);

};


#endif //ESCAPEROOM2_0_HLPR_H
