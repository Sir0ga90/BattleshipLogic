#include "BoardField.h"


CBoardField::CBoardField() :
    cur_state{EFieldState::EMPTY}
{}


CBoardField::EFieldState CBoardField::GetState() const
{
    return cur_state;
}


void CBoardField::SetState(EFieldState new_state)
{
    cur_state = new_state;
}
