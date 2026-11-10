#pragma once
#include <iostream>
#include <string>
#include "SkillList.h"
using namespace std;

class Character {
private:
	string name;
	int hp;
	int maxhp;

	SkillList skills;

public:
	Character(string n, int h);
	Character(string n, int h, int mh);
	~Character();

	// Get Value
	string GetName();
	int GetHP();

	// Set Value
	void SetName(string newName);
	void SetHp(int newhp);

	// Print out the details
	void DisplayInfo();

	void LearnSkill(string skillName, int level); // Add the Skill to the list
	void ForgetSkill(string skillName); // Remove the skill by the skill name
	string CheckSkill(int index); // Return the skill name by the index of the skill
	void UpgradeSkill(string skillName, int newLevel); // Modify the skill level by the skill name
	void UseSkill(string skillName, int requireLevel); // Use the skill by the skill name
};