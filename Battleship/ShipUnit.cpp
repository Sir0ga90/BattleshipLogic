#include "ShipUnit.h"


CShipUnit::CShipUnit() :
    curState(EState::INTACT) {}


//void CShipUnit::SetShip(TShipPtr owner_ship) {
//    ship = owner_ship;
//}

CShipUnit::EState CShipUnit::GetState() {
    return curState;
}
