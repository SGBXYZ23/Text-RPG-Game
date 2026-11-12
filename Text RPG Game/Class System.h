#pragma once
#include <iostream>

using namespace std;

// Stats that the Classes will Inherit with Inheritance

class Adventurer
{
public:
	int HP;
	int MaxHp;
	int AP;
	int MaxAP;
	int Strength;
	int Defense;
	int Intelligence;
	int Speed;

	Adventurer()
	{

	}

	virtual ~Adventurer() {}

	virtual int combat() = 0;
};

class Wizard : public Adventurer
{
public:

	Wizard()
	{
		HP = 70;
		MaxHp = 70;
		AP = 7;
		MaxAP = 7;
		Strength = 2;
		Defense = 3;
		Intelligence = 10;
		Speed = 5;
	}

	virtual ~Wizard() {}

	virtual int combat() 
	{
		std::cout << "I'm a wizard harry\n";return 1;
	}
};

class Warrior : public Adventurer
{
public:

	Warrior()
	{
		HP = 100;
		MaxHp = 100;
		AP = 5;
		MaxAP = 5;
		Strength = 7;
		Defense = 5;
		Intelligence = 1;
		Speed = 3;
	}

	virtual ~Warrior() {}

	virtual int combat()
	{
		std::cout << "I'm a Warruir harry\n";
		return 1;
	}
};

class Cleric : public Adventurer
{
public:

	Cleric()
{
	HP = 85;
	MaxHp = 85;
	AP = 6;
	MaxAP = 6;
	Strength = 4;
	Defense = 5;
	Intelligence = 6;
	Speed = 4;
}
	virtual ~Cleric() {}

	virtual int combat()
	{
		std::cout << "I'm a Cleric!\n";
		return 1;
	}

};
