#include "../include/SkillList.h"

// Constructor
SkillList::SkillList() :
    head(nullptr) {}

SkillList::SkillList(SkillNode * h) :
    head(h) {}

SkillList::~SkillList() {
    SkillNode * curr = head;
    // If the list is not empty
    while ( curr != nullptr ) {
        // Delete the current node
        // Move the pointer to next
        SkillNode * temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// Add the new skill in the list
void SkillList::AddSkill(string skillName, int level) {
    SkillNode * newNode = new SkillNode(skillName, level);
    if ( head == nullptr ) {
        head = newNode;
    } else {
        SkillNode * curr = head;
        while ( curr->next != nullptr ) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
}

// Remove the skill from the list
void SkillList::RemoveSkill(string skillName) {
    SkillNode * curr = head;
    while ( curr != nullptr ) {
        if ( curr->name == skillName ) {
            if ( curr->prev != nullptr ) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next; // Update head if needed
            }
            if ( curr->next != nullptr ) {
                curr->next->prev = curr->prev;
            }
            delete curr;
            return;
        }
        curr = curr->next;
    }
}

// Read skill data from user input
string SkillList::ReadSkill(int index) {
    SkillNode * curr = head;
    int count = 1;
    while ( curr != nullptr ) {
        if ( count == index ) {
            return "Skill: " + curr->name + ", Level: " + to_string(curr->level);
        }
        curr = curr->next;
        count++;
    }
    return "";
}

// Modify the level of an existing skill
void SkillList::ModifySkill(string skillName, int newLevel) {
    SkillNode * curr = head;
    while ( curr != nullptr ) {
        if ( curr->name == skillName ) {
            curr->level = newLevel;
            return;
        }
        curr = curr->next;
    }
}

// Display all skills in the list
void SkillList::DisplaySkill() {
    SkillNode * curr = head;
    // When the list is not empty
    // Print out the skills names and levels
    // move the pointer to next
    while ( curr != nullptr ) {
        cout << "- " << curr->name << " (Level " << curr->level << ")" << endl;
        curr = curr->next;
    }
    cout << endl;
}

// Check if the skill list is empty
bool SkillList::IsEmpty() { return head == nullptr; }

// Return the head pointer
SkillNode * SkillList::begin() { return head; }