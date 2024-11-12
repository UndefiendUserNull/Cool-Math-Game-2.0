#include <string>
#include <iostream>
#include "Utils.hpp"

enum class GameType
{
    Addition,
    Subtraction,
    Multiplication,
    Division
};

class Game
{
public:
    Game(GameType p_gameType) : m_gameType{p_gameType} {};

    void startGame();

private:
    GameType m_gameType{};

    int m_minX = 0;
    int m_maxX = 10;

    int m_minY = 1;
    int m_maxY = 10;

    int m_ranX = 0;
    int m_ranY = 1;

    int m_streak = 0;

    std::string getGameTypeString() const
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

    char getOperatorChar() const
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

    std::string getQuestion() const
    {
        return std::to_string(m_ranX) + " " + getOperatorChar() + " " + std::to_string(m_ranY) + " = ? ";
    }

    int getAnswer() const
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

    void incrementAllAndRandomize()
    {
        m_minX += 1;
        m_maxX += 1;

        m_minY += 1;
        m_maxY += 1;

        m_ranX = Utils::getRandom(m_minX, m_maxX);
        m_ranY = Utils::getRandom(m_minY, m_maxY);


        m_streak += 1;

    }
};

void Game::startGame()
{
    int userInput{};

    // That is NOT the streak
    int correctAnswers{};

    while (true)
    {
        std::cout << getQuestion() << '\n';
        userInput = Utils::getUserInputInt("> ");

        if (userInput != getAnswer())
        {
            Utils::printColoredText("Wrong !, You ended with " + std::to_string(m_streak), Utils::Color::Red);
            Utils::pressToContinue();
            break;
        }
        else
        {
            incrementAllAndRandomize();
            correctAnswers++;
            Utils::printColoredText("Correct !", Utils::Color::BrightGreen);
            if (correctAnswers == 5)
                Utils::clearScreen();
        }
    }
}

int main()
{
    Game g{GameType::Addition};
    g.startGame();
}