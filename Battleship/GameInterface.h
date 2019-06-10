#pragma once

#include <string>

#include "Board.h"
#include "Player.h"


class CGameInterface
{
public:
    enum EPlayers
    {
        Player1,
        Player2
    };

    using TPlayers = std::vector<CPlayer>;

    CGameInterface();
    ~CGameInterface() = default;

    static std::string GetInfoAbout2Ships();
    void GameMainLoop();

private:
    TPlayers players;

    void PrintMsg(const std::string& message) const;
    void PromptAddShips();
};