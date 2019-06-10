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
        SHOT_DOWN,
        SUNK,
    };

    using TStateAnswerMap = std::map<EState, std::string>;
    static const TStateAnswerMap stateAnswerMap;

    void SetState(EState new_state);
    EState GetState() const;

    void SetShipUnit(CShip::TShipUnitPtr& new_ship_unit);
    CShip::TShipUnitPtr& GetShipUnit();

private:
    
    EState curState;
    CShip::TShipUnitPtr shipUnit;
};
