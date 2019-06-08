#pragma once


#include  <string>
#include  <memory>

#include "Board.h"
#include "Coordinates.h"


class CPlayer
{
public:
    CPlayer() = default;
    ~CPlayer() = default;


    SCoordinates Shoot();
    CBoardField::EState ProcessInputShoot(SCoordinates& shoot_coordinates);
    void PlaceShip(CShip new_ship);
    void PrintPlayerBoard();

private:
    static constexpr auto MAX_SHIP_NUBMER = 2u;

    CBoard playerBoard;
    CBoard enemyBoard;

    std::string TranslateShootResult(CBoardField::EState state);
};
