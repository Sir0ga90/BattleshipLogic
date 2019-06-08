#include <iostream>

#include "Player.h"


SCoordinates CPlayer::Shoot() {
    std::cout << "Enter coordinates for shoot ('x y' where x, y from 0 to 9)." << "\n";

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

        while ((x < 0 || x > 9) || (y < 0 || y > 9) || (orientation > 2)) {
            std::cout << "Entered coordinates or orientation not in bounds, try again.\n";

            std::cin >> size >> x >> y >> orientation;
        }

        while (!PlaceShip(CShip(size,
                                SCoordinates{x, y},
                                static_cast<CShip::EBoardOrientation>(orientation)))
               );
    }
}


std::string CPlayer::TranslateShootResult(CBoardField::EState state) {
    return std::string();   //TODO
}
