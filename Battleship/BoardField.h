#pragma once


class CBoardField
{
public:

    CBoardField();
    ~CBoardField() = default;

    enum class EFieldState
    {
        EMPTY,
        FILLED
    };

    EFieldState GetState() const;
    void SetState(EFieldState new_state);

private:
    
    EFieldState cur_state;
};