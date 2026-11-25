
// Text RPG Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include "Class System.h"
#include "Party System.h"
#include "Stage System.h"
#include "Combat System.h"

using namespace std;

int main()
{
    int choice = 0;
    unique_ptr<Adventurer> player;

    cout << "================================\n";
    cout << "        Dungeon Dashers!\n";
    cout << "================================\n";

    // Main Menu
    cout << "\n1. Start Your Journey!\n";
    cout << "2. Exit\n";

    while (true)
    {
        cout << "\nSelect an option: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            break;
        }
        else if (choice == 2)
        {
            cout << "Oh... ok I only spent hours making this but ok, bye :(\n";
            return 0;
        }
        else
        {
            cout << "Please select 1 or 2.\n";
        }
    }

    // Character Name
    string playerName;

    do
    {
        cout << "\nEnter your character's name: ";
        getline(cin, playerName);

        if (playerName.find_first_not_of(" \t") == string::npos)
        {
            cout << "Your name can't be empty, everyone's got a name!\n";
        }

    } while (playerName.find_first_not_of(" \t") == string::npos);

    // Class Selection
    int classChoice = 0;

    cout << "\nChoose your class:\n";
    cout << "1. Wizard\n";
    cout << "2. Warrior\n";
    cout << "3. Cleric\n";
    cout << "4. Beast Tamer\n";

    while (true)
    {
        cout << "\nSelect your class: ";

        if (!(cin >> classChoice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (classChoice)
        {
        case 1:
            player = make_unique<Wizard>(playerName);
            break;

        case 2:
            player = make_unique<Warrior>(playerName);
            break;

        case 3:
            player = make_unique<Cleric>(playerName);
            break;

        case 4:
            player = make_unique<BeastTamer>(playerName);
            break;

        default:
            cout << "Please select a class from 1 to 4.\n";
            continue;
        }

        break;
    }

    
    Party party;

    // Adds the player to the party
    party.addMember(move(player));

    
    cout << "\n================================\n";
    cout << "       CHARACTER CREATED!\n";
    cout << "================================\n\n";

    displayStats(party.getMember(0));

	// Displays the party to the player (later the Beast Tamer will have a pet in the party)
    party.displayParty();



    // Game Intro
    cout << "\n================================\n";
    cout << "  YOUR TIME HAS COME, YOUNG ONE\n";
    cout << "================================\n";

    cout << "\n" << party.getMember(0)->Name
        << ", you have entered the lair of Greedy Grant! "
        << "A creature who stole all our gold! "
        << "We are on the verge of bankruptcy, p-please get rid of him!\n";

    // Creates and runs the dungeon
    Stage dungeon;

    dungeon.runDungeon(party);

    cout << "\n================================\n";
    cout << "          DUNGEON ENDED\n";
    cout << "================================\n";

    return 0;
}