#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Class System.h"

using namespace std;

struct EnemyAttack
{
    string Name;
    int BonusDamage;
};

class Enemy

{
public:


    // Enemy stats
    string Name;
    int HP;
    int MaxHP;
    int Strength;
    int Defense;

    // Constructor (Tests combat system)
    Enemy(const string& name, int hp, int strength, int defense)
        : Name(name),
        HP(hp),
        MaxHP(hp),
        Strength(strength),
        Defense(defense),
        NextAttack(0)
    {
        AttackPattern =
        {
            {"Claw Swipe", 0},
            {"Gimme the Goods!", 5},
            {"Bite", -2}
        };
    }

	// Goblin enemy will follow this attack pattern
    void attack(Adventurer& target, bool targetIsDefending = false)
    {
        if (AttackPattern.empty())
            return;

        EnemyAttack currentAttack = AttackPattern[NextAttack];

        int damage = Strength
            + currentAttack.BonusDamage
            - target.Defense;

        if (damage < 1)
        {
            damage = 1;
        }

        if (targetIsDefending)
        {
            damage = (damage + 1) / 2;

            cout << target.Name
                << " blocks some of the damage!\n";
        }

        target.HP -= damage;

        if (target.HP < 0)
        {
            target.HP = 0;
        }

        // Displays attack information
        cout << "\n" << Name << " uses "
            << currentAttack.Name << " against "
            << target.Name << "!\n";

        cout << "Damage dealt: " << damage << "\n";

        cout << target.Name << "'s HP: "
            << target.HP << "/" << target.MaxHp << "\n";

        // Moves to the next attack in the pattern
        NextAttack++;

        if (NextAttack >= AttackPattern.size())
        {
            NextAttack = 0;
        }
    }

    // Checks if the enemy has been killed
    bool isDefeated() const
    {
        return HP <= 0;
    }

private:

    vector<EnemyAttack> AttackPattern;
    size_t NextAttack;

protected:

    // Allows the enemies to have their own attack patterns
    void setAttackPattern(vector<EnemyAttack> pattern)
    {
        AttackPattern = pattern;
        NextAttack = 0;
    }

};

class Goblin : public Enemy
{
public:

    Goblin()
        : Enemy("Golden Gobo", 40, 9, 2)
    {
        setAttackPattern(
            {
                {"Gimme, Gimme!", -1},
                {"Mine, Mine, Mine!", 2},
                {"Greedy Galestorm", 3}
            });
    }
};

class Golem : public Enemy
{
public:

    Golem()
        : Enemy("Gold Golem", 100, 12, 8)
    {
        setAttackPattern(
            {
                {"Heavy Metal", 3},
                {"Glitz and Gut!", 6},
                {"Gold Cracker", 3}
            });
    }
};

class Skeleton : public Enemy
{
public:

    Skeleton()
        : Enemy("Sir Skel-a-ton", 65, 14, 4)
    {
        setAttackPattern(
            {
                {"Pity the Poor", 1},
                {"Respect the Rich", 2},
                {"Into the Ditch!", 4}
            });
    }
};

class GreedyGrant : public Enemy
{
public:

    GreedyGrant()
        : Enemy("Greedy Grant", 167, 17, 7)
    {
        setAttackPattern(
            {
                {"GOLD RUSH, BABY!", -7},
                {"Tough Luck...", 0},
                {"Good Luck!", 7},
                {"JACKPOT!!! WOOOOOOO!", 77}


            });
    }
};
