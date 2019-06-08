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

void CPlayer::PlaceShip(CShip new_ship) {
    playerBoard.PlaceShip(new_ship);
}

void CPlayer::PrintPlayerBoard()
{
    playerBoard.Print();
}

std::string CPlayer::TranslateShootResult(CBoardField::EState state) {
    return std::string();   //TODO
}
