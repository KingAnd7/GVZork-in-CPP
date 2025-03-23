#include "GVZork.hpp"

int main(int argc, char const *argv[]){
	GAME g;
	LOCATIONS awa;
	g.create_world();
	g.randomLocation(awa);
	while (g.progcheck() == false){
		//gamestuff
	}
	std::cout << "Would you like to play again?\nYes      No\n";
	
};
