#pragma once

#include <vector>
#include <memory>

#include "Coordinates.h"

/*
 *Ships example
 *          
 * 00000111|1|0 For HORIZONTAL orientation pivot point is rightmost unit
 * 00|1|0000000 For VERTICAL orientation pivot point is upper unit 
 * 000100000000
 * 000000000000
 */

class CShipUnit;

class CShip {
public:
    using TShipSize = uint16_t;
    using TShipUnitContainer = std::vector<CShipUnit>;

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
    bool IsSunk();

private:
    TShipSize shipSize;
    SCoordinates pivotPoint;
    EBoardOrientation positionOrientation;
    TShipUnitContainer shipUnits;

};


//===============================================================
class CShipUnit {
public:
    CShipUnit();
    ~CShipUnit() = default;

    using TShipPtr = std::shared_ptr<CShip>;

    enum class EState {
        INTACT,
        HIT
    };


    void SetShip(TShipPtr owner_ship);
    EState GetState() const;

private:
    TShipPtr ship;
    EState curState;
};
