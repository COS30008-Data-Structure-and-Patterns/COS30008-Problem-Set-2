#include "../include/Character.h"

// Default hp is same as max hp
Character::Character(string n, int h) :
    name(n), hp(h), maxhp(h) {}

// Customise the max hp and default hp
Character::Character(string n, int h, int mh) :
    name(n), hp(h), maxhp(mh) {}

// Destructor - properly delete all skill nodes from heap
Character::~Character() {}

// Get Value
string Character::GetName() { return name; }

int Character::GetHP() { return hp; }

// Change the Character name
void Character::SetName(string newName) {
    string oldName = name;
    name = newName;
    cout << oldName << " character's name changed to " << name << "." << endl;
}

// Change the Character HP
void Character::SetHp(int newhp) {
    // If the newhp is greater than maxhp, set hp to maxhp
    hp = (newhp > maxhp) ? maxhp : newhp;
    cout << name << "'s hp set to " << hp << "." << endl;
}

// Display all skills
void Character::DisplayInfo() {
    cout << "\n=== Character: " << name << " ===" << endl;
    cout << "Character HP: " << hp << "/" << maxhp << endl;
    cout << name << "'s Skills:" << endl;
    skills.DisplaySkill();
    cout << endl;
}

// Add the new skill in the list
void Character::LearnSkill(string skillName, int level) {
    skills.AddSkill(skillName, level);
    cout << name << " is learning " << skillName << " - level " << level << "." << endl;
}

// Remove the skill from the list
void Character::ForgetSkill(string skillName) {
    skills.RemoveSkill(skillName);
    cout << name << " has forgotten " << skillName << "." << endl;
}

// Read skill data from user input
string Character::CheckSkill(int index) {
    return skills.ReadSkill(index);
}

// Modify the level of an existing skill
void Character::UpgradeSkill(string skillName, int newLevel) {
    skills.ModifySkill(skillName, newLevel);
    cout << name << "'s " << skillName << " skill upgraded to level " << newLevel << "." << endl;
}

// Use the skill if the required level is met
void Character::UseSkill(string skillName, int requireLevel) {
    // Set the current pointer to the head of the skill list
    SkillNode * curr = skills.begin();
    while ( curr != nullptr ) {
        // If the pointer of the skill name matches
        if ( curr->name == skillName ) {
            // If the current level is greater than or equal to the required level, use skill successful.
            // Otherwise use failed
            if ( curr->level >= requireLevel ) {
                cout << name << " used " << skillName << " successfully!" << endl;
            } else {
                cout << name << " failed to use " << skillName << ". Required level: " << requireLevel << ", Current level: " << curr->level << "." << endl;
            }
            // Stop the program after finding the skill
            return;
        }
        curr = curr->next;
    }
    // Return the message if the character does not know the skill
    cout << name << " does not know the skill " << skillName << "." << endl;
}