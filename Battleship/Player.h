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

    using TShipContainer = std::vector<std::shared_ptr<CShip>>;

    SCoordinates Shoot();
    CBoardField::EFieldState ProcessInputShoot(SCoordinates& shoot_coordinates);

private:
    CBoard playerBoard;
    CBoard enemyBoard;

    std::string TranslateShootResult(CBoardField::EFieldState state);
    TShipContainer ships;
};
