#include <iostream>

class Stage
{
public:
    int CurrentStage;
    int MaxStages;

    Stage()
    {
        CurrentStage = 1;
        MaxStages = 10;
    }

    void enterStage();
    void displayChoices();
    void progressStage();
};