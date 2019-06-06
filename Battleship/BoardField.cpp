#include "BoardField.h"


CBoardField::CBoardField() :
    curState{EFieldState::EMPTY}
{}


CBoardField::EFieldState CBoardField::GetState() const
{
    return curState;
}


void CBoardField::SetState(EFieldState new_state)
{
    curState = new_state;
}


const CBoardField::TStateAnswerMap CBoardField::stateAnswerMap = {
    {EFieldState::EMPTY, std::string{"Miss"}},
    {EFieldState::FILLED, std::string{"Hit"}},
    {EFieldState::HIT, std::string{"Already hit"}}
};
