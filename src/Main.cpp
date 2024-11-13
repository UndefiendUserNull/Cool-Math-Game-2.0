#include <iostream>

#include "Globals.h"
#include "Game.hpp"
#include "Utils.hpp"
#include <Windows.h>

static void showMainMenu()
{
    using namespace Utils;
    printColoredText("[1] Addition", Color::Blue);
    printColoredText("[2] Subtraction", Color::Magenta);
    printColoredText("[3] Multiplication", Color::Yellow);
    printColoredText("[4] Division", Color::BrightRed);
    printColoredText("[5] Random", Color::BrightYellow);
    printColoredText("[6] History", Color::BrightGreen);
    printColoredText("[7] Settings", Color::Cyan);
    printColoredText("[8] Credits", Color::BrightBlue);
    printColoredText("[0] Exit", Color::BrightCyan);
}

Globals globals{};

Game addition{GameType::Addition, globals};
Game subtraction{GameType::Addition, globals};
Game multiplication{GameType::Addition, globals};
Game division{GameType::Addition, globals};

// whole program is running
bool running{true};

// Horrible
static void settings()
{
    using namespace Utils;
    clearScreen();
    char cheatEnabledSymbol = globals.getCheatEnabled() ? '*' : '-';

    std::cout << "[1] : Cheat Mode " << '(' << cheatEnabledSymbol << ")\n";
    int userInput = getUserInputInt("> ");
    bool inSettings{true};
    while (inSettings)
    {
        switch (userInput)
        {
            case 1:
                globals.setCheat(!globals.getCheatEnabled());
                settings();
                break;
            case 0:
                inSettings = false;
                break;
            default:
                break;
        }
        break;
    }
    clearScreen();

}

static void mainMenu()
{
    int userInput{};

    while (true)
    {
        userInput = Utils::getUserInputInt("Choose : ");
        switch (userInput)
        {
            case 1:
                Utils::clearScreen();
                addition.startGame();
                break;
            case 2:
                Utils::clearScreen();
                subtraction.startGame();
                break;
            case 3:
                Utils::clearScreen();
                multiplication.startGame();
                break;
            case 4:
                Utils::clearScreen();
                division.startGame();
                break;
            case 5:
            case 6:
                Utils::clearScreen();
                Utils::printColoredText("COMING SOON !", Utils::Color::BrightRed);
                Utils::pressToContinue();
                Utils::clearScreen();
                break;
            case 7:
                settings();
                break;
            case 0:
                running = false;
                break;
            default:
                Utils::clearScreen();
                std::cout << "Invalid Input\n";
                break;
        }
        break;
    }
}

// stolen, i have no idea what is that but it fixes the colors
static void enableVirtualTerminalProcessing()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

int main()
{
    enableVirtualTerminalProcessing();
    while (running)
    {
        showMainMenu();
        mainMenu();
    }

    return 0;
}