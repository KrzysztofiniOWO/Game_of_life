#include "ManualTurns.h"


std::string ManualTurns::next_command() {
    if (turns_played > 50)
    {
        return "quit";

    }else
    {
        getchar();
        turns_played++;
        return "next";
    }
}