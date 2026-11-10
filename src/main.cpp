#include <iostream>
#include "../include/Character.h"
using namespace std;

string Fight() {
	return R"(
                                                                                                     
                                                                                                     
FFFFFFFFFFFFFFFFFFFFFF  iiii                     hhhhhhh                     tttt           !!!  !!! 
F::::::::::::::::::::F i::::i                    h:::::h                  ttt:::t          !!:!!!!:!!
F::::::::::::::::::::F  iiii                     h:::::h                  t:::::t          !:::!!:::!
FF::::::FFFFFFFFF::::F                           h:::::h                  t:::::t          !:::!!:::!
  F:::::F       FFFFFFiiiiiii    ggggggggg   gggggh::::h hhhhh      ttttttt:::::ttttttt    !:::!!:::!
  F:::::F             i:::::i   g:::::::::ggg::::gh::::hh:::::hhh   t:::::::::::::::::t    !:::!!:::!
  F::::::FFFFFFFFFF    i::::i  g:::::::::::::::::gh::::::::::::::hh t:::::::::::::::::t    !:::!!:::!
  F:::::::::::::::F    i::::i g::::::ggggg::::::ggh:::::::hhh::::::htttttt:::::::tttttt    !:::!!:::!
  F:::::::::::::::F    i::::i g:::::g     g:::::g h::::::h   h::::::h     t:::::t          !:::!!:::!
  F::::::FFFFFFFFFF    i::::i g:::::g     g:::::g h:::::h     h:::::h     t:::::t          !:::!!:::!
  F:::::F              i::::i g:::::g     g:::::g h:::::h     h:::::h     t:::::t          !!:!!!!:!!
  F:::::F              i::::i g::::::g    g:::::g h:::::h     h:::::h     t:::::t    tttttt !!!  !!! 
FF:::::::FF           i::::::ig:::::::ggggg:::::g h:::::h     h:::::h     t::::::tttt:::::t          
F::::::::FF           i::::::i g::::::::::::::::g h:::::h     h:::::h     tt::::::::::::::t !!!  !!! 
F::::::::FF           i::::::i  gg::::::::::::::g h:::::h     h:::::h       tt:::::::::::tt!!:!!!!:!!
FFFFFFFFFFF           iiiiiiii    gggggggg::::::g hhhhhhh     hhhhhhh         ttttttttttt   !!!  !!! 
                                          g:::::g                                                    
                              gggggg      g:::::g                                                    
                              g:::::gg   gg:::::g                                                    
                               g::::::ggg:::::::g                                                    
                                gg:::::::::::::g                                                     
                                  ggg::::::ggg                                                       
                                     gggggg                                                          
)";
}

string Dead() {
	return R"(
                                                                                                    
                                                                    dddddddd                        
DDDDDDDDDDDDD                                                       d::::::d                        
D::::::::::::DDD                                                    d::::::d                        
D:::::::::::::::DD                                                  d::::::d                        
DDD:::::DDDDD:::::D                                                 d:::::d                         
  D:::::D    D:::::D     eeeeeeeeeeee    aaaaaaaaaaaaa      ddddddddd:::::d                         
  D:::::D     D:::::D  ee::::::::::::ee  a::::::::::::a   dd::::::::::::::d                         
  D:::::D     D:::::D e::::::eeeee:::::eeaaaaaaaaa:::::a d::::::::::::::::d                         
  D:::::D     D:::::De::::::e     e:::::e         a::::ad:::::::ddddd:::::d                         
  D:::::D     D:::::De:::::::eeeee::::::e  aaaaaaa:::::ad::::::d    d:::::d                         
  D:::::D     D:::::De:::::::::::::::::e aa::::::::::::ad:::::d     d:::::d                         
  D:::::D     D:::::De::::::eeeeeeeeeee a::::aaaa::::::ad:::::d     d:::::d                         
  D:::::D    D:::::D e:::::::e         a::::a    a:::::ad:::::d     d:::::d                         
DDD:::::DDDDD:::::D  e::::::::e        a::::a    a:::::ad::::::ddddd::::::dd                        
D:::::::::::::::DD    e::::::::eeeeeeeea:::::aaaa::::::a d:::::::::::::::::d ......  ......  ...... 
D::::::::::::DDD       ee:::::::::::::e a::::::::::aa:::a d:::::::::ddd::::d .::::.  .::::.  .::::. 
DDDDDDDDDDDDD            eeeeeeeeeeeeee  aaaaaaaaaa  aaaa  ddddddddd   ddddd ......  ......  ...... 
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
)";
}

int main() {
	Character thePlayer("thePlayer", 100);

	// Learn skills
	thePlayer.LearnSkill("Intimidation Skill", 4);
	thePlayer.LearnSkill("Persuasion Skill", 4);
	thePlayer.LearnSkill("Stealth Skill", 3);

	// Print out player details
	thePlayer.DisplayInfo();

	while ( true ) {
		cout << "The Robber demands that the PC hand over your money AND your life. " << endl;
		cout << "Choose your action: " << endl;
		cout << "1. 'Here�s my money.' - The game ends" << endl;
		cout << "2. 'You can try, when you get older' - Requires 'Intimidation Skill' at Level 3" << endl;
		cout << "3. 'What Money? What Life? I�m an Engineer' - Requires 'Persuasion Skill' at Level 5" << endl;
		cout << "4. *Fight* - Leads into combat sequence" << endl;
		cout << "Your action (1-4): ";

		string action;
		cin >> action;

		if ( action == "1" ) {
			cout << "\nYou hand over your money and the robber shoots you. You lose!" << endl;
			cout << Dead() << endl;
			break;
		} else if ( action == "2" ) {
			thePlayer.UseSkill("Intimidation Skill", 3);
			break;
		} else if ( action == "3" ) {
			thePlayer.UseSkill("Persuasion Skill", 5);
			break;
		} else if ( action == "4" ) {
			cout << "\nYou chose to fight! (Combat sequence not implemented)" << endl;
			cout << Fight() << endl;
			break;
		} else {
			cout << "\nInvalid action. Please choose again." << endl;
		}

	}

	return 0;
}