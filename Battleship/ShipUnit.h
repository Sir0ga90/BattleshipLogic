#pragma once


#include <memory>

#include "Ship.h"


class CShipUnit
{
public:
    CShipUnit();
    ~CShipUnit() = default;

    using TShipPtr = std::shared_ptr<CShip>;

    enum class EState
    {
        INTACT,
        HIT
    };


    //void SetShip(TShipPtr owner_ship);
    EState GetState();

private:
    //TShipPtr ship;
    EState curState;
};
