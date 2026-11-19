#pragma once
#include <iostream>

using namespace std;

// Stats that the Classes will Inherit

class Adventurer
{
public:

	string Name;

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
		HP = 0;
		MaxHp = 0;
		AP = 0;
		MaxAP = 0;
		Strength = 0;
		Defense = 0;
		Intelligence = 0;
		Speed = 0;

		Level = 1;
		XP = 0;
		XPToNextLevel = 100;
	}

	virtual void statsUpgrade()
	{
		HP += 1;
		MaxHp += 1;
		AP += 1;
		MaxAP += 1;
		Strength += 1;
		Defense += 1;
		Intelligence += 1;
		Speed += 1;
	}

	virtual ~Adventurer() {}

	virtual int combat() = 0;
};

// Level up system

int Level;
int XP;
int XPToNextLevel;

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

	virtual void statsUpgrade() override
	{
		HP += 5;
		MaxHp += 5;
		AP += 1;
		MaxAP += 2;
		Strength += 1;
		Defense += 1;
		Intelligence += 3;
		Speed += 1;
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

	virtual void statsUpgrade() override
	{
		HP += 10;
		MaxHp += 10;
		AP += 1;
		MaxAP += 1;
		Strength += 2;
		Defense += 4;
		Intelligence += 1;
		Speed += 1;
	}

	virtual ~Warrior() {}

	virtual int combat()
	{
		std::cout << "I'm a Warruir harry\n";
		return 1;
	}
};

void displayStats(Adventurer* player)
{
	std::cout << "HP: " << player->HP << "/" << player->MaxHp << std::endl;
	std::cout << "AP: " << player->AP << "/" << player->MaxAP << std::endl;
	std::cout << "Strength: " << player->Strength << std::endl;
	std::cout << "Defense: " << player->Defense << std::endl;
	std::cout << "Intelligence: " << player->Intelligence << std::endl;
	std::cout << "Speed: " << player->Speed << std::endl;
}

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

	virtual void statsUpgrade() override
	{
		HP += 6;
		MaxHp += 6;
		AP += 1;
		MaxAP += 2;
		Strength += 3;
		Defense += 3;
		Intelligence += 5;
		Speed += 1;
	}

	virtual ~Cleric() {}

	virtual int combat()
	{
		std::cout << "I'm a Cleric!\n";
		return 1;
	}

};

class BeastTamer : public Adventurer
{
public:

	BeastTamer()
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

	virtual void statsUpgrade() override
	{
		HP += 4;
		MaxHp += 4;
		AP += 2;
		MaxAP += 2;
		Strength += 3;
		Defense += 2;
		Intelligence += 3;
		Speed += 2;
	}

	virtual ~BeastTamer() {}

	virtual int combat()
	{
		std::cout << "I'm a Beast Tamer!\n";
		return 1;
	}

};
