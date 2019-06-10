#include <iostream>

#include "Player.h"


CPlayer::CPlayer(uint16_t player_id) :
    id{player_id} {}

SCoordinates CPlayer::Shoot() {
    std::cout << "Player" << GetId()
        << " Enter coordinates for shoot ('x y' where x, y from 0 to 9)." << "\n";

    SCoordinates::TCoord x = -1;
    SCoordinates::TCoord y = -1;

    std::cin >> x >> y;

    while ((x < 0 || x > 9) || (y < 0 || y > 9)) {
        std::cout << "Entered coordinates not in bounds, try again.\n";

        std::cin >> x >> y;
    }

    return SCoordinates(x, y);
}


CBoardField::EState CPlayer::ProcessInputShoot(SCoordinates& shoot_coordinates) {
    return playerBoard.ProcessInputShoot(shoot_coordinates);
}


bool CPlayer::PlaceShip(CShip new_ship) {
    playerBoard.PlaceShip(new_ship);
    return true;
}


void CPlayer::PrintPlayerBoard() {
    playerBoard.Print();
}


bool CPlayer::IsLost() {
    return playerBoard.AllShipsSunk();
}

void CPlayer::PlaceNShips() {
    for (auto ship_num = 0u; ship_num < MAX_SHIP_NUMBER; ++ship_num) {
        int16_t size = -1;
        SCoordinates::TCoord x = -1;
        SCoordinates::TCoord y = -1;
        int16_t orientation = -1;

        std::cin >> size >> x >> y >> orientation;

        while ((size < 1 || size > 4) ||
               (x < 0 || x > 9) ||
               (y < 0 || y > 9) ||
               (orientation < 0 || orientation > 1)
               ) {
            std::cout << "Entered size, coordinates or orientation not in bounds, try again.\n";

            std::cin >> size >> x >> y >> orientation;
        }

        while (!PlaceShip(CShip(size,
                                SCoordinates{x, y},
                                static_cast<CShip::EBoardOrientation>(orientation)))
               );
    }
}

uint16_t CPlayer::GetId() const {
    return id;
}


std::string CPlayer::TranslateShootResult(CBoardField::EState state) {
    return CBoardField::stateAnswerMap.find(state)->second;
}
