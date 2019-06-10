#pragma once


#include  <string>

#include "Board.h"
#include "Coordinates.h"


class CPlayer
{
public:
    CPlayer(uint16_t player_id);
    ~CPlayer() = default;


    SCoordinates Shoot();
    CBoardField::EState ProcessInputShoot(SCoordinates& shoot_coordinates);
    bool PlaceShip(CShip new_ship);
    void PrintPlayerBoard();
    bool IsLost();
    void PlaceNShips();
    uint16_t GetId() const;

    static constexpr auto MAX_SHIP_NUMBER = 2u;

    static std::string TranslateShootResult(CBoardField::EState state);

private:
    CBoard playerBoard;
    CBoard enemyBoard;
    uint16_t id;

};
