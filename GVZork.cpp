#include "GVZork.hpp"
#include <string>
#include <sstream>

int main(int argc, char const *argv[]){
	GAME g;
	LOCATIONS awa;
	g.create_world();
	g.randomloc(awa);
	while (g.progcheck() == false){
	
		std::string input;
		std::cout << "Enter a line of text: ";
    		getline(std::cin, input);  // Read the entire line
    		std::stringstream ss(input);
		std::string token;
		std::vector<std::string> inputvec;
		while (ss >> token) {  // Extract words separated by spaces
       			inputvec.push_back(token);
    		} 
		if (inputvec[0] == 'help'){
			g.showHelp();
		}else if (inputvec[0] == '?'){
			g.showHelp();
                }else if (inputvec[0] == 'talk'){
			g.talk(inputvec[1]);
                }else if (inputvec[0] == 'go'){
			g.go(inputvec[1]);
                }else if (inputvec[0] == 'move'){
			g.go(inputvec[1]);
                }else if (inputvec[0] == 'look'){
			g.look();
                }else if (inputvec[0] == 'take'){
			g.take(inputvec[0]);
                }else if (inputvec[0] == 'get'){
			g.take(inputvec[0]);
                }else if (inputvec[0] == 'give'){
			g.give(inputvec[1]);
                }else if (inputvec[0] == 'inventory'){
			g.show_items();
                }else if (inputvec[0] == 'items'){
			g.show_items();
                }else if (inputvec[0] == 'see'){
			g.see();
		}else if (inputvec[0] == 'meet'){
			g.meet(inputvec[1]);
		}else if (inputvec[0] == 'teleport'){
			g.teleport();
		}else if (inputvec[0] == 'quit'){
			g.quit();
		}else if (inputvec[0] == 'exit'){
			g.quit();
		}else{
			std::cout<< "Invalid Command" << std::endl;
		};
	}
	std::cout << "Would you like to play again?\nYes      No\n";
	
};
