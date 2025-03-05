#include "GVZork.hpp"

int main(int argc, char const *argv[]){
//    ITEM TEST CODE
        //cookie
	ITEM cookie("Cookie", "A tasty cookie for the elf", 78, 1.5, false);
        std::cout << cookie  << std::endl;

	//cake
	ITEM cake("Cake", "A slice of cake! It was someone's birthday recently!", 129, 2.5, false);
	std::cout << cake << std::endl;
	
	//lie cake
	ITEM cakelie("Cake?", "Something doesn't seem right with this cake.", 0, 1, false);
	std::cout << cakelie << std::endl;

	//goblin morningstar
	ITEM morningstar("Goblin Morningstar", "One of the lost pieces of goblin equipement.", 0, 3.5, true);
	std::cout << morningstar << std::endl;

	// ration
	ITEM ration("Ration", "It's cheese flavored!", 200, 1, false);
	std::cout << ration << std::endl;
	
	//goblin armor
	ITEM armor("Goblin Armor", "One of the lost pieces of goblin equipment.", 0, 5.0, true);
	std::cout << armor << std::endl;

	//goblin cookie
	ITEM gcookie("Rasin Cookie", "Don't let the goblin near this cookie!", 78, 1.5, true);
	std::cout << gcookie << std::endl;

	//lasagna
	ITEM lasagna("Lasagna", "I heard the wizard's familiar loves these things!", 166, 2.0, false);
	std::cout << lasagna << std::endl;

	//goblin shield
	ITEM shield("Goblin Shield", "One of the lost pieces of goblin equipment.", 0, 3.0, true);
	std::cout << shield << std::endl;

	//potion
	ITEM potion("Potion", "I wonder what this does?", 1000, 1, false);
	std::cout << potion << std::endl;

//      NPC TEST CODE
        //wizard test code
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

	//goblin test code
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

	//elf test code
	NPC elf("Heimlin", "An elf who has come to save the day, given payment.", {}, false);
	elf.addMessage("Greetings traveler.");
	elf.addMessage("It seems you need my assistance.");
	elf.addMessage("Bring me payment in the form of calories.");
	elf.addMessage("If you bring me enough, I will save your school.");
	std::cout << "NPC Name " << elf << std::endl;
        std::cout << "description: " << elf.getDescription() << std::endl;
        for (size_t i = 0; i < 10; i++)
        {
                std::cout << elf << " says: \"" elf.getMessage() << "\"" << std::endl;
        }
	
	//ranger test code
	NPC ranger("Arana", "A drider ranger who's hunting the madman who made the crystal.", {}, false);
		

	//cleric test code
	NPC cleric("Lyco", "a werewolf healer who searches for a cure to their own affliction", {}, false);
    return 0;
};
};
