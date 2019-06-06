#pragma once

#include <map>
#include <string>


class CBoardField
{
public:

    CBoardField();
    ~CBoardField() = default;

    enum class EFieldState
    {
        EMPTY,
        FILLED,
        HIT
    };

    using TStateAnswerMap = std::map<EFieldState, std::string>;

    EFieldState GetState() const;
    void SetState(EFieldState new_state);

private:
    
    EFieldState curState;
    static const TStateAnswerMap stateAnswerMap;
};
