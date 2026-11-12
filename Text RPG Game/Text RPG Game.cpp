
// Text RPG Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Class System.h"
using namespace std;

int main()
{
    int choice = 0;
    cout << "================================\n";
    cout << "          MY NEW RPG GAME\n";
    cout << "================================\n";

    
    cout << "\n1. Start Your Journey!\n";
    cout << "2. Exit\n";
    cin >> choice;

    if (choice == 1)
    {

        int choice2 = 0;
        Adventurer* player;
        std::cout << "Pick 1: Wizard, 2: Warrior, 3: Cleric\n";
        std::cin >> choice2;

        switch (choice2)
        {
        case 1:
            player = new Wizard();
            break;

        case 2:
            player = new Warrior();
            break;

        case 3:
            player = new Cleric();
            break;

        default:
            player = new Wizard();
            break;
        }

        player->combat();
    }
    else
    {
        std::cout << "Bye\n";
        return 0;
    }

    return 0;
}