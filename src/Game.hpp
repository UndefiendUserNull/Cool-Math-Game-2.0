#pragma once

#include <string>
#include "Globals.h"

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
    Game(GameType p_gameType, Globals p_globals);

    void startGame();

private:
    GameType m_gameType{};
    Globals m_globals{};

    int m_minX = 0;
    int m_maxX = 10;

    int m_minY = 1;
    int m_maxY = 10;

    int m_ranX = 0;
    int m_ranY = 1;

    int m_streak = 0;

    std::string getGameTypeString() const;

    char getOperatorChar() const;

    std::string getQuestion() const;

    int getAnswer() const;

    void incrementAllAndRandomize();

};
