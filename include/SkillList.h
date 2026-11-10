#pragma once
#include <iostream>
#include <string>
#include "SkillNode.h"
using namespace std;

class SkillList {
private:
	SkillNode * head;

public:
	SkillList();
	SkillList(SkillNode * h);
	~SkillList();

	void AddSkill(string skillName, int level); // Add the Skill to the list
	void RemoveSkill(string skillName); // Remove the skill by the skill name
	string ReadSkill(int index); // Return the skill name by the index of the skill
	void ModifySkill(string skillName, int newLevel); // Modify the skill level by the skill name

	void DisplaySkill(); // Display all skills in the list

	bool IsEmpty(); // Check if the skill list is empty
	SkillNode * begin(); // Return the head pointer
};