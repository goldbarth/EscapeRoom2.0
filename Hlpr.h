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
    std::string black() const
    {
        return "30"; // Black color code
    }
    std::string red() const
    {
        return "31"; // Red color code
    }
    std::string green() const
    {
        return "32"; // Green color code
    }
    std::string yellow() const
    {
        return "33"; // Yellow color code
    }
    std::string blue() const
    {
        return "34"; // Blue color code
    }
    std::string magenta() const
    {
        return "35"; // Magenta color code
    }
    std::string cyan() const
    {
        return "36"; // Cyan color code
    }
    std::string gray() const
    {
        return "37"; // Gray color code
    }
    std::string dark_gray() const
    {
        return "90"; // Dark gray color code
    }
    std::string light_red() const
    {
        return "91"; // Light red color code
    }
    std::string light_green() const
    {
        return "92"; // Light green color code
    }
    std::string light_yellow() const
    {
        return "93"; // Light yellow color code
    }
    std::string light_blue() const
    {
        return "94"; // Light blue color code
    }
    std::string light_magenta() const
    {
        return "95"; // Light magenta color code
    }
    std::string light_cyan() const
    {
        return "96"; // Light cyan color code
    }
    std::string white() const
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
        static void Write(const char* text);

        static void WriteAt(int left, int top, const std::string& text, const std::string& textColor);
        static void WriteAt(int left, int top, const char& text);
        static void WriteAt(int left, int top, const char& text, const std::string& textColor);

        static void WriteLine(const std::string& text);
        static void WriteLine(const char& text);

        static void WriteLineAt(int left, int top, const std::string& text, const std::string& textColor);

        static void ClearScreen();
        static void SetConsoleCursorPos(int left, int top);
        static void ShowConsoleCursor(bool showFlag);

};


#endif //ESCAPEROOM2_0_HLPR_H
