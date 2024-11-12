#include <string>
#include <iostream>
#include "Utils.hpp"
#include "Globals.h"
#include "Game.hpp"


Game::Game(GameType p_gameType, Globals p_globals) : m_gameType{p_gameType}, m_globals{p_globals} {};

std::string Game::getGameTypeString() const
{
    switch (m_gameType)
    {
        case GameType::Addition:
            return "Addition";
        case GameType::Subtraction:
            return "Subtraction";
        case GameType::Multiplication:
            return "Multiplication";
        case GameType::Division:
            return "Division";
        default:
            return "Addition";
    }
}

char Game::getOperatorChar() const
{
    switch (m_gameType)
    {
        case GameType::Addition:
            return '+';
        case GameType::Subtraction:
            return '-';
        case GameType::Multiplication:
            return '*';
        case GameType::Division:
            return '/';
        default:
            return '+';
    }
}

std::string Game::getQuestion() const
{
    return std::to_string(m_ranX) + " " + getOperatorChar() + " " + std::to_string(m_ranY) + " = ? ";
}

int Game::getAnswer() const
{
    switch (m_gameType)
    {
        case GameType::Addition:
            return m_ranX + m_ranY;
        case GameType::Subtraction:
            return m_ranX - m_ranY;
        case GameType::Multiplication:
            return m_ranX * m_ranY;
        case GameType::Division:
            return -1;
        default:
            return m_ranX + m_ranY;
    }
}

void Game::incrementAllAndRandomize()
{
    m_ranX = Utils::getRandom(++m_minX, ++m_maxX);
    m_ranY = Utils::getRandom(++m_minY, ++m_maxY);
    m_streak++;
}

void Game::startGame()
{
    int userInput{};

    // That is NOT the streak
    int correctAnswers{};

    while (true)
    {
        std::cout << getQuestion() << '\n';

        if (m_globals.getCheatEnabled())
            std::cout << getAnswer() << '\n';

        userInput = Utils::getUserInputInt("> ");

        if (userInput != getAnswer())
        {
            Utils::printColoredText("Wrong !, You ended with " + std::to_string(m_streak) + " Streak", Utils::Color::Red);
            Utils::pressToContinue();
            break;
        }

        incrementAllAndRandomize();
        correctAnswers++;

        Utils::printColoredText("Correct !", Utils::Color::BrightGreen);

        if (correctAnswers == m_globals.getClearOn())
            Utils::clearScreen();

    }
}

