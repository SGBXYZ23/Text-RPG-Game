#pragma once

#include "Party System.h"

class Stage
{
private:

    int CurrentStage;
    const int MaxStages;

public:

    Stage()
        : CurrentStage(1), MaxStages(10)
    {
    }

    // Displays the current stage
    void enterStage();

    // Displays available choices
    void displayChoices();

    // Handles the player's selected choice
    void makeChoice(int choice, Party& party);

    // Advances to the next stage
    void progressStage();

    // Runs the entire dungeon
    void runDungeon(Party& party);
};