#pragma once

#include "Coordinates.h"

/*
 *Ships example
 *          
 * 00000111|1|0 For HORIZONTAL orientation pivot point is rightmost unit
 * 00|1|0000000 For VERTICAL orientation pivot point is upper unit 
 * 000100000000
 * 000000000000
 */

class CShip {
public:
    using TShipSize = uint16_t;

    enum class EBoardOrientation {
        HORIZONTAL,
        VERTICAL
    };

    enum class ECurSate
    {
        INTACT,
        SHOT_DOWN,
        SUNK,
    };


    CShip() = default;
    explicit CShip(TShipSize size, SCoordinates pivot_point, EBoardOrientation orientation);
    ~CShip() = default;

    TShipSize GetShipSize();
    SCoordinates GetPivotPoint();
    EBoardOrientation GetBoardOrientation();

private:
    TShipSize ship_size;
    SCoordinates pivot_point;
    EBoardOrientation position_orientation;
};
