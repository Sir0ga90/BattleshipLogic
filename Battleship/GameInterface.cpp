#include <iostream>

#include "GameInterface.h"


CGameInterface::CGameInterface() {
    for (uint16_t player_id = 1; player_id <= CPlayer::MAX_SHIP_NUMBER; ++player_id) {
        players.push_back(CPlayer{player_id});
    }
}

std::string CGameInterface::GetInfoAbout2Ships() {
    return std::string{"Hello! This is test version. It's able to add only 2 ships for each player.\n"};
}


void CGameInterface::GameMainLoop() {
    PrintMsg(GetInfoAbout2Ships());
    PromptAddShips();

    auto shooting_player = players.at(EPlayers::Player1);
    auto defending_player = players.at(EPlayers::Player2);

    constexpr bool GAME_IN_PROCESS{true};

    while (GAME_IN_PROCESS) {
        auto shoot_coordinates = shooting_player.Shoot();
        const auto shoot_result = defending_player.ProcessInputShoot(shoot_coordinates);

        PrintMsg(CPlayer::TranslateShootResult(shoot_result) + "\n");

        //check if lost
        if (shoot_result == CBoardField::EState::SUNK) {
            if (defending_player.IsLost()) {
                PrintMsg(std::string("\nPlayer").append(std::to_string(shooting_player.GetId())) +
                         ", congratulations!!! You won! Thank you for game!\n");
                break;
            }
        }

        switch (shoot_result) {
            case CBoardField::EState::EMPTY:
                std::swap(shooting_player, defending_player);
                break;
            case CBoardField::EState::SHOT_DOWN:
                //continue shooting
                break;
            default:
                break;
        }

    }

}


void CGameInterface::PrintMsg(const std::string& message) const {
    std::cout << message;
}


void CGameInterface::PromptAddShips() {
    PrintMsg(std::string{"Now each of you should to add 2 ships.\n"});
    PrintMsg(std::string("Ship parameters format:\n\n\
 'size x y board_orientation'\n\n\
where: \n\
-size from 1 to 4\n\
-x-horizontal, y-vertical coordinates of ship head\n\
-board_orientation:0-horizontal, 1-vertical\n\n\n"));

    //Set ships on boards
    for (auto player = 0u; player < 2; ++player) {
        PrintMsg(std::string{"Player"}.append(std::to_string(player + 1) + " , add 2 ships.\n"));
        PrintMsg(std::string("Opponent, please, don't look at the screen.\n"));
        players.at(player).PlaceNShips();

        system("CLS");
    }
}
