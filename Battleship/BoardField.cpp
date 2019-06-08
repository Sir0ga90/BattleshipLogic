#include "BoardField.h"


CBoardField::CBoardField() :
    curState{EState::EMPTY} {}


CBoardField::EState CBoardField::GetState() const {
    return curState;
}

void CBoardField::SetShipUnit(CShipUnit new_ship_unit) {
    shipUnit = new_ship_unit;    
}


void CBoardField::SetState(EState new_state) {
    curState = new_state;
}


CShipUnit& CBoardField::GetShipUnit() {
    return shipUnit;
}


const CBoardField::TStateAnswerMap CBoardField::stateAnswerMap = {
    {EState::EMPTY, std::string{"Miss"}},
    {EState::FILLED, std::string{"Hit"}},
    {EState::HIT, std::string{"Already hit"}}
};
