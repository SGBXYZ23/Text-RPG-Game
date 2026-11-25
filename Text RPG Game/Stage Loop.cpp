#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Stage System.h"
#include "Combat System.h"

using namespace std;

// Introduces the current stage
void Stage::enterStage()
{
    cout << "\n================================\n";
    cout << "      GRANT'S LAIR - STAGE "
        << CurrentStage << " / " << MaxStages << "\n";
    cout << "================================\n";

    cout << "\nYou enter the next area of the dungeon...\n";
}

// Displays available choices
void Stage::displayChoices()
{
    cout << "\nWhat would you like to do?\n\n";

    cout << "1. Search the area(Item)\n";
    cout << "2. Look around if anyone is nearby (Recruitment)\n";
    cout << "3. Find a place to train (XP)\n";
    cout << "4. Explore some odd noises... (Combat)\n";
}

// Handles the player's selected choice
void Stage::makeChoice(int choice, Party& party)
{
    switch (choice)
    {
    case 1:
        cout << "\nYou search the area...\n";
        cout << "You discover a mysterious potion!\n";
        cout << "You have found an item!\n";

        // Inventory functionality will be implemented later.
        break;

    case 2:
        cout << "\nYou find someone buried under a pile of diamonds and rescue them.\n";
        cout << "They thank you and want to join your party!\n";

        party.recruitMember();
        break;

    case 3:
        cout << "\nYou find a feeble litte goblin to practice your skills on. He had a family waiting for him.\n";
        cout << "No matter, you gain 25 XP!\n";

        party.getMember(0)->XP += 25;

        cout << "Your current XP: "
            << party.getMember(0)->XP << "\n";
        break;

    case 4:
    {
        cout << "\nYou check the noises and get spotted by a creature\n";
        cout << "Looks like they won't let you leave easy...\n";

        int enemyChoice = rand() % 3;

        if (enemyChoice == 0)
        {
            Goblin monster;
            Combat encounter(&monster);
            encounter.runCombat(party);
        }
        else if (enemyChoice == 1)
        {
            Skeleton monster;
            Combat encounter(&monster);
            encounter.runCombat(party);
        }
        else
        {
            Golem monster;
            Combat encounter(&monster);
            encounter.runCombat(party);
        }

        break;
    }
    } 

}     

// Progresses to the next stage
void Stage::progressStage()

{
    CurrentStage++;
}

// Runs the entire dungeon
void Stage::runDungeon(Party& party)
{
    // Seeds the random number generator for the random combat encounters
    srand(static_cast<unsigned int>(time(nullptr)));

    // Loops the stages until you get to Stage 10

    while (CurrentStage < MaxStages)
    {
        enterStage();

        displayChoices();

        int choice = 0;

        while (true)
        {
            cout << "\nYour choice: ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a number between 1 and 4.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice >= 1 && choice <= 4)
            {
                break;
            }

            cout << "Please select an option between 1 and 4.\n";
        }

        makeChoice(choice, party);

        // Checks is anyone in the party is still alive
        bool partyAlive = false;

        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            Adventurer* member = party.getMember(i);

            if (member != nullptr && member->HP > 0)
            {
                partyAlive = true;
                break;
            }
        }

        if (!partyAlive)
        {
            cout << "\nYour party has been slain...\n";
            cout << "The kingdom is brought to ruin and never heard from again...\n";
            return;
        }

        progressStage();
    }

    // Stage 10 - Mandatory Final Fight
    enterStage();

    cout << "\nYou have reached the deepest part of the lair!\n";
    cout << "Piles and piles of gold and jewels littered on the floor...\n";

    cout << "\nGREEDY GRANT RISES FROM THE MOUND!\n";
    cout << "KE HA HA HA HA! YOUR DEATH SHALL BE ENSURED AND I'LL POUND YOU INTO THE GROUND!\n";

    GreedyGrant boss;

    Combat finalEncounter(&boss);

    finalEncounter.runCombat(party);
}