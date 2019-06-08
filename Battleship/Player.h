#pragma once


#include  <string>

#include "Board.h"
#include "Coordinates.h"


class CPlayer
{
public:
    CPlayer() = default;
    ~CPlayer() = default;


    SCoordinates Shoot();
    CBoardField::EState ProcessInputShoot(SCoordinates& shoot_coordinates);
    bool PlaceShip(CShip new_ship);
    void PrintPlayerBoard();
    bool IsLost();
    void PlaceNShips();

    static constexpr auto MAX_SHIP_NUMBER = 2u;

private:

    CBoard playerBoard;
    CBoard enemyBoard;

    std::string TranslateShootResult(CBoardField::EState state);
};
