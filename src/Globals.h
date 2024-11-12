#pragma once

// It's not really Globals
struct Globals
{
private:
    bool m_cheatEnabled{true};
    int m_clearOn{2};

public:
    bool getCheatEnabled() const { return m_cheatEnabled; }
    void setCheat(bool newVal) { m_cheatEnabled = newVal; }

    int getClearOn() const { return m_clearOn; }
    void setClearOn(int newVal) { m_clearOn = newVal; }
};