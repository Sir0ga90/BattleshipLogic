#include "Ship.h"
#include <iostream>


CShip::CShip(
    TShipSize size,
    SCoordinates pivot_point,
    EBoardOrientation orientation)
    : shipSize{size},
    pivotPoint{pivot_point},
    positionOrientation{orientation}
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


void CShip::SetShipUnit(TShipUnitPtr& new_unit) {
    auto this_ship = shared_from_this();
    new_unit->SetShip(this_ship);
    shipUnits.push_back(new_unit);
}


bool CShip::IsSunk() {
    bool is_sunk = true;

    for (auto& unit : shipUnits) {
        if (unit->GetState() == CShipUnit::EState::INTACT) {
            is_sunk = false;
            break;
        }
    }

    if (is_sunk) {
        curState = ESate::SUNK;
    }

    return is_sunk;
}

CShip::ESate CShip::GetState() const {
    return curState;
}


//===================================================================
CShipUnit::CShipUnit() :
    curState{EState::INTACT} {}


void CShipUnit::SetShip(TShipPtr& owner_ship) {
    ship = owner_ship;
}


CShipUnit::EState CShipUnit::GetState() const {
    return curState;
}

CShip::ESate CShipUnit::GetShipState() const {
    ship->IsSunk();
    return ship->GetState();
}

CShip::ESate CShipUnit::Hit() {
    curState = EState::HIT;
    return GetShipState();
}
