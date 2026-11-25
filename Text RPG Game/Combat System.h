#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include "Party System.h"
#include "Enemy System.h"

using namespace std;

class Combat
{
private:
    Enemy* CurrentEnemy;
    vector<Adventurer*> DefendingMembers;

public:

    
    Combat(Enemy* enemy)
        : CurrentEnemy(enemy)
    {
    }

    // Displays the enemy stats
    void displayEnemy()
    {
        cout << "Name: " << CurrentEnemy->Name << "\n";
        cout << "HP: " << CurrentEnemy->HP
            << "/" << CurrentEnemy->MaxHP << "\n";
        cout << "Strength: " << CurrentEnemy->Strength << "\n";
        cout << "Defense: " << CurrentEnemy->Defense << "\n";
    }

	
    void playerAttack(Adventurer* attacker)
    {
        if (attacker == nullptr || CurrentEnemy == nullptr)
            return;

        if (attacker->HP <= 0 || CurrentEnemy->isDefeated())
            return;

        //Damage formula for basic attack

        int damage = attacker->Strength - CurrentEnemy->Defense;

        if (damage < 1)
            damage = 1;

        CurrentEnemy->HP -= damage;

        if (CurrentEnemy->HP < 0)
            CurrentEnemy->HP = 0;

        cout << "\n" << attacker->Name
            << " attacks " << CurrentEnemy->Name
            << " for " << damage << " damage!\n";

        cout << CurrentEnemy->Name << "'s HP: "
            << CurrentEnemy->HP << "/"
            << CurrentEnemy->MaxHP << "\n";
    }

    // Checks whether the enemy has been defeated
    bool enemyDefeated() const
    {
        return CurrentEnemy == nullptr || CurrentEnemy->isDefeated();
    }

    // Basic attack with AP cost
    void basicAttack(Adventurer* attacker)
    {
        if (attacker == nullptr || CurrentEnemy == nullptr)
            return;

        if (attacker->HP <= 0 || CurrentEnemy->isDefeated())
            return;
     
		// Basic attack costs 2 AP
        const int APCost = 2;

        if (attacker->AP < APCost)
        {
            cout << "\nNot enough AP!\n";
            return;
        }

        attacker->AP -= APCost;

        playerAttack(attacker);

        cout << attacker->Name << " has "
            << attacker->AP << " AP remaining.\n";
    }
    /// Wizard Skills //////////
    void wizardFireball(Wizard* wizard)
    {
        if (wizard == nullptr || CurrentEnemy == nullptr)
            return;

        const int APCost = 2;

        if (wizard->AP < APCost)
        {
            cout << "\nNot enough AP!\n";
            return;
        }

        wizard->AP -= APCost;

        int damage = (wizard->Intelligence * 2 + 5)
            - CurrentEnemy->Defense;

        if (damage < 1)
            damage = 1;

        CurrentEnemy->HP -= damage;

        if (CurrentEnemy->HP < 0)
            CurrentEnemy->HP = 0;

        cout << "\n" << wizard->Name << " casts Fireball!\n";
        cout << CurrentEnemy->Name << " takes "
            << damage << " damage!\n";

        cout << CurrentEnemy->Name << "'s HP: "
            << CurrentEnemy->HP << "/"
            << CurrentEnemy->MaxHP << "\n";

        cout << wizard->AP << " AP remaining.\n";
    }

    // Wizard Lightning ability
    void wizardLightning(Wizard* wizard)
    {
        if (wizard == nullptr || CurrentEnemy == nullptr)
            return;

        const int APCost = 4;

        if (wizard->AP < APCost)
        {
            cout << "\nNot enough AP!\n";
            return;
        }

        wizard->AP -= APCost;

        int damage = (wizard->Intelligence * 3 / 2 + 3)
            - CurrentEnemy->Defense;

        if (damage < 1)
            damage = 1;

        CurrentEnemy->HP -= damage;

        if (CurrentEnemy->HP < 0)
            CurrentEnemy->HP = 0;

        cout << "\n" << wizard->Name << " casts Lightning!\n";
        cout << CurrentEnemy->Name << " takes "
            << damage << " damage!\n";

        cout << CurrentEnemy->Name << "'s HP: "
            << CurrentEnemy->HP << "/"
            << CurrentEnemy->MaxHP << "\n";

        cout << wizard->AP << " AP remaining.\n";
    }

    // Restores AP at the beginning of a round
    void resetPartyAP(Party& party)
    {
        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            Adventurer* member = party.getMember(i);

            if (member != nullptr && member->HP > 0)
            {
                member->AP = member->MaxAP;
            }
        }

        cout << "\nAll living party members have restored their AP!\n";
    }



	// Displays the party  members' combat status
    void displayPartyCombatStatus(Party& party)
    {
        cout << "\n================================\n";
        cout << "         PARTY STATUS\n";
        cout << "================================\n";

        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            Adventurer* member = party.getMember(i);

            cout << "\n" << member->Name
                << " (" << member->getClassName() << ")\n";

            cout << "HP: " << member->HP
                << "/" << member->MaxHp << "\n";

            cout << "AP: " << member->AP
                << "/" << member->MaxAP << "\n";

            if (member->HP <= 0)
            {
                cout << "Status: KO\n";
            }
        }
    }

    // Allows a party member to defend
    void defend(Adventurer* member)
    {
        if (member == nullptr || member->HP <= 0)
            return;

       //Defending cost 1 AP
        const int APCost = 1;

        if (member->AP < APCost)
        {
            cout << "\nNot enough AP!\n";
            return;
        }

        member->AP -= APCost;

        DefendingMembers.push_back(member);

        cout << "\n" << member->Name
            << " prepares to defend!\n";

        cout << member->AP << " AP remaining.\n";
    }

    // Displays the combat options for the player
    void displayCombatMenu(Adventurer* member)
    {
        cout << "\nWhat would you like to do?\n";
        cout << "1. Basic Attack (2 AP)\n";
        cout << "2. Defend (1 AP)\n";
        cout << "3. Finish Turn\n";

        if (dynamic_cast<Wizard*>(member) != nullptr)
        {
            cout << "4. Fireball (2 AP)\n";
            cout << "5. Lightning (4 AP)\n";
            cout << "6. Mana Burst (2 AP)\n";
        }
    }

    // This manages a party members' turn
    void memberTurn(Adventurer* member)
    {
        if (member == nullptr || member->HP <= 0)
            return;

        int choice = 0;

        cout << member->Name << "'s turn!\n";
        

        while (member->AP > 0 && !CurrentEnemy->isDefeated())
        {
            cout << "\nCurrent AP: "
                << member->AP << "/" << member->MaxAP << "\n";

            displayCombatMenu(member);

            cout << "\nSelect an action: ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                basicAttack(member);
                break;

            case 2:
                defend(member);
                break;

            case 3:
                cout << member->Name << " ends their turn.\n";
                return;
            // Wizard Skills below
            case 4:
            {
                Wizard* wizard = dynamic_cast<Wizard*>(member);
                wizardFireball(wizard);
                break;
            }

            case 5:
            {
                Wizard* wizard = dynamic_cast<Wizard*>(member);
                wizardLightning(wizard);
                break;
            }

            case 6:
            {
                Wizard* wizard = dynamic_cast<Wizard*>(member);

                if (member->AP < 2)
                {
                    cout << "\nNot enough AP to use Mana Burst!\n";
                }
                else if (wizard->activateManaBurst())
                {
                    member->AP -= 2;
                }
                else
                {
                    cout << "\nMana Burst is already active!\n";
                }

                break;
            }
            default:
                cout << "Please select an option from 1 to 3.\n";
                break;
            }
        }

        cout << "\n" << member->Name << "'s turn has ended.\n";
    }


    // Handles the entire party's turn
    void partyTurn(Party& party)
    {
        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            if (CurrentEnemy->isDefeated())
                break;

            memberTurn(party.getMember(i));
        }
    }


    // Handles the enemy's turn
    void enemyTurn(Party& party)
    {
        if (CurrentEnemy == nullptr || CurrentEnemy->isDefeated())
            return;

        
        cout << CurrentEnemy->Name << "'s turn!\n";
   

        // Find the first living party member
        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            Adventurer* target = party.getMember(i);

            if (target != nullptr && target->HP > 0)
            {
                // Checks if the target is defending

                bool isDefending = false;

                for (Adventurer* defender : DefendingMembers)
                {
                    if (defender == target)
                    {
                        isDefending = true;
                        break;
                    }
                }

                CurrentEnemy->attack(*target, isDefending);
                break;

				
            }
        }

        // Defensive effects expire after the enemy's turn
        DefendingMembers.clear();

    }


    // Checks if the entire party has been beaten
    bool partyDefeated(Party& party)
    {
        for (size_t i = 0; i < party.getPartySize(); i++)
        {
            Adventurer* member = party.getMember(i);

            if (member != nullptr && member->HP > 0)
            {
                return false;
            }
        }

        return true;
    }

    // Runs the combat encounter
    void runCombat(Party& party)
    {
        if (CurrentEnemy == nullptr)
        {
            cout << "No enemy available for combat!\n";
            return;
        }

        cout << "\n================================\n";
        cout << "        COMBAT BEGINS!\n";
        cout << "================================\n";

        displayEnemy();

        while (!CurrentEnemy->isDefeated() &&
            !partyDefeated(party))
        {
            // Start of the round
            cout << "\n========== NEW ROUND ==========\n";

            resetPartyAP(party);

            displayPartyCombatStatus(party);

            // Party members take their turn
            partyTurn(party);

            // Check whether the enemy was defeated
            if (CurrentEnemy->isDefeated())
                break;

            // Enemy takes their turn
            enemyTurn(party);

            displayPartyCombatStatus(party);
        }

        cout << "\n================================\n";

        if (CurrentEnemy->isDefeated())
        {
            cout << "        ENEMY BEATEN! :D\n";
            
        }
        else
        {
            cout << "        PARTY BEATEN! :(\n";
            
        }
    }
};
