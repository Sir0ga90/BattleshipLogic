#include "Ship.h"


CShip::CShip(
    TShipSize size,
    SCoordinates pivot_point,
    EBoardOrientation orientation)
    : shipSize{size},
    pivotPoint{pivot_point},
    positionOrientation{orientation},
    shipUnits(shipSize)
{}


CShip::TShipSize CShip::GetShipSize() {
    return shipSize;
}


SCoordinates CShip::GetPivotPoint() {
    return pivotPoint;
}


CShip::EBoardOrientation CShip::GetBoardOrientation() {
    return positionOrientation;
}


void CShip::SetShipUnit(CShipUnit new_unit) {
    new_unit.SetShip(shared_from_this());
    shipUnits.push_back(new_unit);
}


bool CShip::IsSunk() {
    bool is_sunk = true;

    for (auto& unit : shipUnits) {
        if (unit.GetState() == CShipUnit::EState::INTACT) {
            is_sunk = false;
        }
    }

    return is_sunk;
}

CShip::ESate CShip::GetState() const {
    return curState;
}


//===================================================================
CShipUnit::CShipUnit() :
    curState{EState::INTACT} {}


void CShipUnit::SetShip(TShipPtr owner_ship) {
    ship = owner_ship;
}


CShipUnit::EState CShipUnit::GetState() const {
    return curState;
}

CShip::ESate CShipUnit::GetShipState() const {
    return ship->GetState();
}
