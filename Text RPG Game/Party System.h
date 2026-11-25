#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include "Class System.h"

using namespace std;

class Party
{
private:

    // Stores all the party members
    vector<unique_ptr<Adventurer>> Members;

    // Maximum party size, including the player
    const int MaxPartySize = 3;

public:

    // Adds a character to the party (mainly for Beast Tamer to start with a pet party member)
    bool addMember(unique_ptr<Adventurer> member)
    {
        if (Members.size() >= MaxPartySize)
        {
            cout << "Woah there, your party is full!\n";
            return false;
        }

        Members.push_back(move(member));

        cout << "A new member has joined your party!\n";

        return true;
    }

    // Shows the current party members and their stats
    void displayParty()
    {
        cout << "\n================================\n";
        cout << "              PARTY\n";
        cout << "================================\n";

        for (size_t i = 0; i < Members.size(); i++)
        {
            cout << "\nMember " << i + 1 << endl;

            cout << "Name: " << Members[i]->Name << endl;
            cout << "Class: " << Members[i]->getClassName() << endl;
            cout << "HP: " << Members[i]->HP
                << "/" << Members[i]->MaxHp << endl;
            cout << "AP: " << Members[i]->AP
                << "/" << Members[i]->MaxAP << endl;
        }

        cout << "\nParty Size: " << Members.size()
            << "/" << MaxPartySize << endl;
    }

    // Returns the number of party members
    size_t getPartySize() const
    {
        return Members.size();
    }

    // Returns a party member using their position
    Adventurer* getMember(size_t index)
    {
        if (index >= Members.size())
        {
            return nullptr;
        }

        return Members[index].get();
    }

    // Lets the player recruit a member when given the option
    void recruitMember()
    {
        // Check if the player's party is full if they agree to recruit a member
        if (Members.size() >= MaxPartySize)
        {
            cout << "\nSorry bud,your party is full!\n";
            return;
        }

        string recruitName;
        int recruitClass = 0;

        
        cout << "\nNew friend, huh? What's their name?: ";
        getline(cin, recruitName);

        // Stops empty named being added
        while (recruitName.find_first_not_of(" \t") == string::npos)
        {
            cout << "It can't be empty. Ask them, dummy!: ";
            getline(cin, recruitName);
        }

        
        cout << "\nChoose your recruit's class:\n";
        cout << "1. Wizard\n";
        cout << "2. Warrior\n";
        cout << "3. Cleric\n";
        cout << "4. Beast Tamer\n";

        while (true)
        {
            cout << "\nSelect a class: ";

            if (!(cin >> recruitClass))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid input. Enter a number from 1 to 4.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (recruitClass)
            {
            case 1:
                addMember(make_unique<Wizard>(recruitName));
                break;

            case 2:
                addMember(make_unique<Warrior>(recruitName));
                break;

            case 3:
                addMember(make_unique<Cleric>(recruitName));
                break;

            case 4:
                addMember(make_unique<BeastTamer>(recruitName));
                break;

            default:
                cout << "Please select a class from 1 to 4.\n";
                continue;
            }

            break;
        }
    }
};