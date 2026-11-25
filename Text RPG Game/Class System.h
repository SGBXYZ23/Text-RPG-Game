#pragma once
#include <iostream>
#include <string>

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

	int Level;
	int XP;
	int XPToNextLevel;

	Adventurer(const string& name)
	{
		Name = name;

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

	// Finds what class the player picks

	virtual string getClassName() = 0;

	virtual ~Adventurer() {}

	virtual int combat() = 0;
};

class Wizard : public Adventurer
{

private:

	int ManaBurstTurnsRemaining = 0;
	int OriginalIntelligence = 0;
	bool ManaBurstActive = false;


public:

	// Activates Mana Burst skill for Mage
	bool activateManaBurst()
	{
		if (ManaBurstActive)
			return false;

		OriginalIntelligence = Intelligence;
		Intelligence += 5;

		ManaBurstTurnsRemaining = 2;
		ManaBurstActive = true;

		cout << "\nMana Burst activated! Intelligence increased by 5!\n";

		return true;
	}

	// Reduces the remaining buff duration
	void updateManaBurst()
	{
		if (!ManaBurstActive)
			return;

		ManaBurstTurnsRemaining--;

		if (ManaBurstTurnsRemaining <= 0)
		{
			Intelligence = OriginalIntelligence;
			ManaBurstActive = false;

			cout << "\nMana Burst has worn off!\n";
		}
	}


public:

	Wizard(const string& name) : Adventurer(name)
	{
		HP = 70;
		MaxHp = 70;
		AP = 8;
		MaxAP = 8;
		Strength = 4;
		Defense = 3;
		Intelligence = 10;
		Speed = 5;

		Level = 1;
		XP = 0;
		XPToNextLevel = 100;
	}

	virtual string getClassName() override
	{
		return "Wizard";
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
		std::cout << "I'm a wizard!\n";return 1;
	}


};

class Warrior : public Adventurer
{
public:

	Warrior(const string& name) : Adventurer(name)
	{
		HP = 120;
		MaxHp = 120;
		AP = 6;
		MaxAP = 6;
		Strength = 11;
		Defense = 10;
		Intelligence = 1;
		Speed = 3;

		Level = 1;
		XP = 0;
		XPToNextLevel = 100;
	}

	virtual string getClassName() override
	{
		return "Warrior";
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
		std::cout << "I'm a Warrior!\n";
		return 1;
	}
};

inline void displayStats(Adventurer* player)
{
	// Displays the player's name and class
	std::cout << "Name: " << player->Name << std::endl;
	std::cout << "Class: " << player->getClassName() << std::endl;

	// Displays the player's stats
	std::cout << "HP: " << player->HP << "/" << player->MaxHp << std::endl;
	std::cout << "AP: " << player->AP << "/" << player->MaxAP << std::endl;
	std::cout << "Strength: " << player->Strength << std::endl;
	std::cout << "Defense: " << player->Defense << std::endl;
	std::cout << "Intelligence: " << player->Intelligence << std::endl;
	std::cout << "Speed: " << player->Speed << std::endl;
	std::cout << "Level: " << player->Level << std::endl;
	std::cout << "XP: " << player->XP << std::endl;
	std::cout << "XP to Next Level: " << player->XPToNextLevel << std::endl;
}

class Cleric : public Adventurer
{
public:

	Cleric(const string& name) : Adventurer(name)
{
	HP = 95;
	MaxHp = 95;
	AP = 9;
	MaxAP = 9;
	Strength = 4;
	Defense = 5;
	Intelligence = 6;
	Speed = 4;

	Level = 1;
	XP = 0;
	XPToNextLevel = 100;
}

	virtual string getClassName() override
	{
		return "Cleric";
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

	BeastTamer(const string& name) : Adventurer(name)
	{
		HP = 85;
		MaxHp = 85;
		AP = 7;
		MaxAP = 7;
		Strength = 8;
		Defense = 11;
		Intelligence = 3;
		Speed = 5;

		Level = 1;
		XP = 0;
		XPToNextLevel = 100;
	}

	virtual string getClassName() override
	{
		return "Beast Tamer";
	}

	virtual void statsUpgrade() override
	{
		HP += 4;
		MaxHp += 4;
		AP += 2;
		MaxAP += 2;
		Strength += 3;
		Defense += 2;
		Intelligence += 4;
		Speed += 2;
	}

	virtual ~BeastTamer() {}

	virtual int combat()
	{
		std::cout << "I'm a Beast Tamer!\n";
		return 1;
	}

};
