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

    static constexpr uint8_t BOARD_SIZE = 10u;

    CBoard();
    ~CBoard() = default;

    void PlaceShip(CShip new_ship);
    void Print();

private:
    CBoardField::EFieldState GetFieldState(const SCoordinates shoot_coordinates) const;
    void PlaceShipUnit(SCoordinates unit_coordinates);
    bool IsFieldAppropriate(const SCoordinates& field_coordinates) const;
    bool IsPossibleToPlaceShip(CShip ship);
    bool IsPossibleToPlaceShipInOneOrientation(SCoordinates::TCoord ship_head_a,
                                               SCoordinates::TCoord ship_head_b, 
                                               CShip::TShipSize ship_size);

    bool IsCoordinateInBoardBounds(SCoordinates::TCoord coord);

    TBoardFields mainBoard;
};