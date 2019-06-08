#include <iostream>

#include "GameInterface.h"


CGameInterface::CGameInterface() {
    for (auto player = 0u; player < CPlayer::MAX_SHIP_NUMBER; ++player) {
        players.push_back(CPlayer{});
    }
}

std::string CGameInterface::GetInfoAbout2Ships() {
    return std::string{"Hello! This is test version. It's able to add only 2 ships for each player.\n"};
}


void CGameInterface::GameMainLoop() {
    PrintMsg(GetInfoAbout2Ships());
    PromtAddShips();
}


void CGameInterface::PrintMsg(const std::string& message) const {
    std::cout << message;
}


void CGameInterface::PromtAddShips() {
    PrintMsg(std::string{"Now each of you should to add 2 ships. I won't check it's size, but better to use from 1 to 4.\n"});
    PrintMsg(std::string("Ship parameters format: 'size x y board_orientation'. x-horizontal, \
    y-vertical coordinates of ship head.\nboard_orientation:0-horizontal, 1-vertical\n"));

    for (auto player = 0u; player < 2; ++player) {
        PrintMsg(std::string{"Player"}.append(std::to_string(player + 1) + " , add 2 ships.\n"));
        players.at(player).PlaceNShips();
    }
}
