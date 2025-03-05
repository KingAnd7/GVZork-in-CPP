#include "GVZork.hpp"

int main(int argc, char const *argv[]){
//    ITEM TEST CODE
        ITEM rustyNail("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, 1, false);
        std::cout << rustyNail << std::endl;

//      NPC TEST CODE
        NPC wizard("Merlin", "An old and wise wizard with a long white beard", {}, false);
        wizard.addMessage("Greetings, young adventurer!");
        wizard.addMessage("Beware of the dragon in the northern mountains.");
        wizard.addMessage("Have you found the ancient spell book yet?");
        wizard.addMessage("The stars are aligned for great magic tonight.");
        std::cout << "NPC Name: " << wizard << std::endl;
        std::cout << "Description: " << wizard.getDescription() << std::endl;
        
        for (size_t i = 0; i < 10; i++)
        {
            std::cout << "Wizard says: \"" << wizard.getMessage() << "\"" << std::endl;
        }
	
	NPC goblin("Fartbuckle", "A goblin companion who's yet to find his purpose", {}, true);
	goblin.addMessage("Hello adventurer.");
	goblin.addMessage("Fartbuckle would like to come with adventurer.");
	goblin.addMessage("Bring Fartbuckle lost equipment.");
	goblin.addMessage("(something indecernable in goblinspeech)");
	std::cout << "NPC Name " << goblin << std::endl;
	std::cout << "description: " << goblin.getDescription() << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << goblin << " says: \"" goblin.getMessage() << "\"" << std::endl;
	}

    return 0;
};
};
