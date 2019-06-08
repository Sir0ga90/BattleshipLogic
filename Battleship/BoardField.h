#pragma once

#include <map>
#include <string>

#include "Ship.h"


class CBoardField
{
public:

    CBoardField();
    ~CBoardField() = default;

    enum class EState
    {
        EMPTY,
        FILLED,
        HIT,
        SHOT_DOWN,
        SUNK,
    };

    using TStateAnswerMap = std::map<EState, std::string>;

    void SetState(EState new_state);
    EState GetState() const;

    void SetShipUnit(CShipUnit new_ship_unit);
    CShipUnit& GetShipUnit();

private:
    
    EState curState;
    static const TStateAnswerMap stateAnswerMap;
    CShipUnit shipUnit;
};
