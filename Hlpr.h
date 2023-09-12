//
// Created by goldbarth on 10.09.2023.
//


#ifndef ESCAPEROOM2_0_HLPR_H
#define ESCAPEROOM2_0_HLPR_H

#include <Windows.h>
#include <iostream>
#include <string>


struct ColorCode
{
    // Foreground (text)
    static std::string black(){ return "30"; }
    static std::string red(){ return "31"; }
    static std::string green(){ return "32"; }
    static std::string yellow(){ return "33"; }
    static std::string blue(){ return "34"; }
    static std::string magenta(){ return "35"; }
    static std::string cyan(){ return "36"; }
    static std::string gray(){ return "37"; }
    static std::string dark_gray(){ return "90"; }
    static std::string light_red(){ return "91"; }
    static std::string light_green(){ return "92"; }
    static std::string light_yellow(){ return "93"; }
    static std::string light_blue(){ return "94"; }
    static std::string light_magenta(){ return "95"; }
    static std::string light_cyan(){ return "96"; }
    static std::string white(){ return "97"; }

    // Background
    static std::string bg_black(){ return "40"; }
    static std::string bg_red(){ return "41"; }
    static std::string bg_green(){ return "42"; }
    static std::string bg_yellow(){ return "43"; }
    static std::string bg_blue(){ return "44"; }
    static std::string bg_magenta(){ return "45"; }
    static std::string bg_cyan(){ return "46"; }
    static std::string bg_gray(){ return "47"; }
    static std::string bg_dark_gray(){ return "100"; }
    static std::string bg_light_red(){ return "101"; }
    static std::string bg_light_green(){ return "102"; }
    static std::string bg_light_yellow(){ return "103"; }
    static std::string bg_light_blue(){ return "104"; }
    static std::string bg_light_magenta(){ return "105"; }
    static std::string bg_light_cyan(){ return "106"; }
    static std::string bg_white(){ return "107"; }
};

class Hlpr
{
    public:
        static void Write(const std::string& text);
        static void Write(const char& text);

        static void WriteAt(const int& left, const int& top, const std::string& text, const std::string& textColor);
        static void WriteAt(const int& left, const int& top, const char& letter, const std::string& textColor);
        static void WriteAt(const int& left, const int& top, const char& letter);

        static void WriteLine(const std::string& text);
        static void WriteLine(const char& letter);

        static void WriteLineAt(const double& left, const double& top, const std::string& text, const std::string& textColor);

        static void ClearScreen();
        static void SetConsoleCursorPos(const double& left, const double& top);
        static void ShowConsoleCursor(const bool& showFlag);
};


#endif //ESCAPEROOM2_0_HLPR_H
