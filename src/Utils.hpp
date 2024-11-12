#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <random>

namespace Utils
{
    enum class Color
    {
        Reset = 0,
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        BrightBlack = 90,
        BrightRed = 91,
        BrightGreen = 92,
        BrightYellow = 93,
        BrightBlue = 94,
        BrightMagenta = 95,
        BrightCyan = 96,
        BrightWhite = 97
    };


    inline std::string colorCode(Utils::Color color)
    {
        return "\033[" + std::to_string(static_cast<int>(color)) + "m";
    }

    void printColoredText(const std::string& msg, Color color, bool newLine = true)
    {
        std::cout << colorCode(color) << msg << colorCode(Color::Reset);
        if (newLine) std::cout << '\n';
    }

    void clearScreen()
    {

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

    }

    int getUserInputInt(const std::string& msg)
    {
        while (true)
        {
            std::cout << msg;
            int userInput{};
            std::cin >> userInput;
            bool success{std::cin};
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!success)
                continue;

            return userInput;
        }
    }

    //// Couldn't use a template cause of the Division

    float getUserInputFloat(const std::string& msg)
    {
        while (true)
        {
            std::cout << msg;
            float userInput{};
            std::cin >> userInput;
            bool success{std::cin};
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!success)
                continue;

            return userInput;
        }
    }

    int getRandom(int min, int max)
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

        return dist6(rng);
    }

    void pressToContinue()
    {
        system("pause");
    }
}