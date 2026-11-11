
// Text RPG Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "================================\n";
    cout << "          MY NEW RPG GAME\n";
    cout << "================================\n";

    cout << "\n1. Start Your Journey!\n";
    cout << "2. Exit\n";

    int choice;

    cout << "\nSelect an option: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nStarting the game...\n";
    }
    else if (choice == 2)
    {
        cout << "\nThanks for playing!\n";
    }
    else
    {
        cout << "\nInvalid option!\n";
    }

    return 0;
}