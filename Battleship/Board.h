#pragma once

#include <vector>

#include "BoardField.h"
#include "Coordinates.h"
#include "Ship.h"


class CBoard {
public:
    //TODO: make start index from 1 but not from 0

    using TBoardLine = std::vector<CBoardField>;
    using TBoardFields = std::vector<TBoardLine>;
    using TShipContainer = std::vector<CShipUnit::TShipPtr>;

    static constexpr uint8_t BOARD_SIZE = 10u;

    CBoard();
    ~CBoard() = default;

    bool PlaceShip(CShip new_ship);
    void Print();
    CBoardField::EState ProcessInputShoot(SCoordinates shoot_coordinates);
    bool AllShipsSunk();

private:
    CBoardField& GetBoardField(const SCoordinates field_coordinates);
    CBoardField::EState GetFieldState(const SCoordinates shoot_coordinates);
    void PlaceShipUnit(const SCoordinates& unit_coordinates,
                       CShipUnit::TShipPtr& owner_ship);

    bool IsFieldAppropriate(const SCoordinates& field_coordinates);
    bool IsPossibleToPlaceShip(CShip ship);
    bool IsPossibleToPlaceShipInOneOrientation(SCoordinates::TCoord ship_head_a,
                                               SCoordinates::TCoord ship_head_b,
                                               CShip::TShipSize ship_size);

    bool IsCoordinateInBoardBounds(SCoordinates::TCoord coord);

    void ProcessShipHit(CBoardField::EState& cur_field_state,
                        const SCoordinates& shoot_coordinates);


    TBoardFields mainBoard;
    TShipContainer ships;   //TODO: move ships to CPlayer

};