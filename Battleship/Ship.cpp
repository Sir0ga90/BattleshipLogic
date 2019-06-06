#include "Ship.h"


CShip::CShip(
    TShipSize size,
    SCoordinates pivot_point,
    EBoardOrientation orientation) 
    : ship_size{size},
    pivot_point{pivot_point},
    position_orientation{orientation}
{}


CShip::TShipSize CShip::GetShipSize()
{
    return ship_size;
}


SCoordinates CShip::GetPivotPoint()
{ 
    return pivot_point;
}


CShip::EBoardOrientation CShip::GetBoardOrientation()
{
    return position_orientation;
}
