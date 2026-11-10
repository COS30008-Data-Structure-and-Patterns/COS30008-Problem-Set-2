#pragma once
#pragma once
#include <iostream>
using namespace std;

class SkillNode {
public:
	string name;	// Stores the name of the skill (e.g. Persuasion, Aggression, Dodge, etc.)
	int level;	// Stores a number that indicates how strong this skill is (e.g. 1, 2, 9000, etc.) 
	SkillNode * next; // Next pointer for the node
	SkillNode * prev; // Previous pointer for the node

	SkillNode(string n, int l) :
		name(n), level(l), next(nullptr), prev(nullptr) {}
};