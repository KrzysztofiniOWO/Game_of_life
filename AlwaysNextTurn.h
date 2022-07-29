#pragma once
#include "CommandSource.h"

class AlwaysNextTurn : public CommandSource {
public:
    std::string next_command() override;

private:
    int turns_played = 0;
};