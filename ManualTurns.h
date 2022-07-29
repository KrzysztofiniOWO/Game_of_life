#pragma once
#include "CommandSource.h"

class ManualTurns : public CommandSource {
public:
    std::string next_command() override;

private:
    int turns_played = 0;
};

