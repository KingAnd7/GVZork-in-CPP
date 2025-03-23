// made by Andrew Hills and Gerrit Mitchell

#ifndef         __HPP__GVZork__
#define         __HPP__GVZork__

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <functional>

class ITEM{
    public:
	ITEM(){};
        ITEM(std::string name, std::string description, int calorie, float weight, bool gobbo){
            if (name.empty()){
                throw std::runtime_error("Name can not be Null");
            }
            else{
                this-> name = name;
            }
            if (description.empty()){
                throw std::runtime_error("Description can not be Null");
            }
            else{
                this->description = description;
            }
            if(calorie < 0 || calorie > 100 || typeid(calorie) != typeid(int)){
                throw std::runtime_error("Calorie has to be a int that is more than 0 or less than 100");
            }
            else{
                this->calorie = calorie;
            }
            if(weight < 0 || weight > 500 || typeid(weight) != typeid(float)){
                throw std::runtime_error("Calorie has to be a int that is more than 0 or less than 100");
            }
            else{
                this->weight = weight;
            }
            if (gobbo != true && gobbo != false){
                throw std::runtime_error("true or false expected");
            }
            else{
                this->gobbo = gobbo;
	    }

        }

        friend std::ostream& operator<<(std::ostream& os, const ITEM& i){
            os << i.name << " (" << i.calorie << " calories) - " << i.weight << "lb - " << i.description;
            return os;
        }

//      Getters and setters
        std::string getName() const{
            return name;
        }
        void setName(std::string newValue){
            name = newValue;
        }
        std::string getDescription() const{
            return description;
        }
        void setDescription(std::string newValue){
            description = newValue;
        }
        int getCalorie() const{
            return calorie;
        }
        void setCalorie(int newValue){
            calorie = newValue;
        }
        float getWeight() const{
            return weight;
        }
        void setWeight(float newValue){
            weight = newValue;
        }

    private:
        std::string name;
        std::string description;
        int calorie;
        float weight;
        bool gobbo;

};

class NPC{
    public:
	NPC(){};
        NPC(std::string name, std::string description, std::vector<std::string> messages, bool gobbo){
            if (name.empty()){
                throw std::runtime_error("Name can not be Null");
            }
            else{
                this-> name = name;
            }
            if (description.empty()){
                throw std::runtime_error("Description can not be Null");
            }
            else{
                this->description = description;
            }
            if (gobbo != true && gobbo != false){
                throw std::runtime_error("true or false expected");
            }
            else{
                this->gobbo = gobbo;
            }

        }

        std::string getName() const{
            return name;
        }
        void setName(std::string newValue){
            name = newValue;
        }
        std::string getDescription() const{
            return description;
        }
        void setDescription(std::string newValue){
            description = newValue;
        }
        void addMessage(std::string newValue){
            messages.push_back(newValue);
        }

	std::string getMessage() {
            if (messages.empty()){
                return "No messages available";
            }

            std::string currentMessage = messages[message_count];
            message_count = (message_count + 1) % messages.size();
            return currentMessage;
        }

        friend std::ostream& operator<<(std::ostream& os, const NPC& i){
            os << i.name;
            return os;
        }

    private:
    std::string name;
    std::string description;
    int message_count;
    std::vector<std::string> messages;
    bool gobbo;
};

class LOCATIONS{
        public:
		LOCATIONS(){};
                LOCATIONS(std::string name, std::string description, bool visited){
			if (name.empty()){
				throw std::runtime_error("Name cannot be empty");
			}else{
				this -> name = name;
            		}
			if (description.empty()){
				throw std::runtime_error("Description cannot be empty");
			}else{
				this -> description = description;
			}
		    }
            void add_location(std::string direction, std::reference_wrapper<LOCATIONS> location){
		    neighbors[direction] = location;
            }

            void add_item(std::reference_wrapper<ITEM> item){
                location_items.push_back(item);
            };
            std::vector<std::reference_wrapper<ITEM>> getItem() const{
                return location_items;
            };
	    ITEM removeItem(std::string itemName) {
                int count = 0;
		for (auto it : location_items) {
			if (it.get().getName() == itemName) {
				ITEM item = it.get();
		    		location_items.erase(location_items.begin()+count);
                        	return item;
			};
			count += 1;
                };
            };

	    std::map<std::string, std::reference_wrapper<LOCATIONS> > getneighbors(){
		    return neighbors;
	    }

            void add_npc(std::reference_wrapper<NPC> npc){
                location_npcs.push_back(npc);
            }            
            std::vector<std::reference_wrapper<NPC>> getNPC() const{
                return location_npcs;
            }
            void set_visited(){
                if (visited == false){
                    visited = true;
                }
            }		
            std::string getName() const{
                return name;
	    }

	    friend std::ostream& operator<<(std::ostream& os, const LOCATIONS& i){
		os << i.name;
		return os;
	    }

        private:
		std::string name;
		std::string description;
		bool visited;
		std::map<std::string, std::reference_wrapper<LOCATIONS>> neighbors;
		std::vector<std::reference_wrapper<NPC>> location_npcs;
		std::vector<std::reference_wrapper<ITEM>> location_items;
};

class GAME{
    public:
    	GAME(){};
	std::map<std::string, std::function<void(std::vector<std::string>)>> setup_commands(std::map<std::string, std::function<void(std::vector<std::string>)>> cmds){

        	cmds["help"] = [this](std::vector<std::string> args) { showHelp(args); };
        	cmds["?"] = [this](std::vector<std::string> args) { showHelp(args); };
        	cmds["talk"] = [this](std::vector<std::string> args) { talk(args); };
        	cmds["go"] = [this](std::vector<std::string> args) { go(args); };
		cmds["teleport"] = [this](std::vector<std::string> args) { teleport(); };
        	cmds["move"] = [this](std::vector<std::string> args) { go(args); };
        	cmds["look"] = [this](std::vector<std::string> args) { look(args); };
        	cmds["take"] = [this](std::vector<std::string> args) { take(args); };
        	cmds["get"] = [this](std::vector<std::string> args) { take(args); };
        	cmds["give"] = [this](std::vector<std::string> args) { give(args); };
        	cmds["inventory"] = [this](std::vector<std::string> args) { show_items(args); };
        	cmds["items"] = [this](std::vector<std::string> args) { show_items(args); };
        	cmds["meet"] = [this](std::vector<std::string> args) { meet(args); };
        	cmds["quit"] = [this](std::vector<std::string> args) { quit(args); };
        	cmds["exit"] = [this](std::vector<std::string> args) { quit(args); };
        
        	return cmds;
    	}

	void addloclist(std::reference_wrapper<LOCATIONS> loc) {
		locationlist.push_back(loc);
	}

        void create_world() {
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
                	std::cout << goblin << " says: \"" << goblin.getMessage() << "\"" << std::endl;
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
         
			std::cout << elf << " says: \"" << elf.getMessage() << "\"" << std::endl;
       		}

        	//ranger test code
		NPC ranger("Arana", "A drider ranger who's hunting the madman who made the crystal.", {}, false);
		ranger.addMessage("Hello there! My name is Arana!");
                ranger.addMessage("You wouldn't happen to have any mice, would you?");
        	ranger.addMessage("Or perhaps you've seen the man I'm hunting.");
		ranger.addMessage("He has a very pointy hat.");
		std::cout << "NPC Name " << ranger << std::endl;
		std::cout << "description: " << ranger.getDescription() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << ranger << " says: \"" << ranger.getMessage() << "\"" << std::endl;
		}

		//cleric test code
        	NPC cleric("Lyco", "a werewolf healer who searches for a cure to their own affliction", {}, false);
		cleric.addMessage("");
		cleric.addMessage("");
		cleric.addMessage("");
		cleric.addMessage("");
		std::cout << "NPC Name " << cleric << std::endl;
		std::cout << "description: " << cleric.getDescription() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << cleric << " says: \"" << cleric.getMessage() << "\"" << std::endl;
		}

		//location creation
		LOCATIONS Makinaw("Mackinaw", "The Home of the Computer Science Department", false);
		Makinaw.add_npc(wizard);
		Makinaw.add_item(cakelie);
		Makinaw.add_item(morningstar);

		LOCATIONS Manitou("Manitou", "No one ever knows what classes are truly held here, only that it has a computer lab", false);
		Manitou.add_item(cookie);

		LOCATIONS Holton_Hooker("Holton_Hooker", "Students live here despite there being classes", false);
		Holton_Hooker.add_item(cake);
		Holton_Hooker.add_item(ration);

		LOCATIONS Padnos("Padnos", "Home of the science students", false);
		Padnos.add_npc(goblin);
		Padnos.add_item(armor);
		
		LOCATIONS Loutit("Loutit", "Lecture Halls that are connected to Henry", false);
		Loutit.add_item(gcookie);
		Loutit.add_item(potion);

		LOCATIONS Henry("Henry", "Computer Labs that are connected to Loutit", false);
		Henry.add_npc(ranger);
		Loutit.add_item(lasagna);

		LOCATIONS Kindshi("Kindshi", "Home to biology classes", false);
		Kindshi.add_npc(cleric);
		Kindshi.add_item(shield);
		
		LOCATIONS Arboretum("Arboretum", "The Woods where the Elf resides", false);
		Arboretum.add_npc(elf);

		Makinaw.add_location("South", Manitou);
		Makinaw.add_location("East", Holton_Hooker);
		addloclist(Makinaw);

		Manitou.add_location("North", Makinaw);
		Manitou.add_location("South", Padnos);
		Manitou.add_location("West", Kindshi);
		addloclist(Manitou);
		
		Holton_Hooker.add_location("South", Arboretum);
		Holton_Hooker.add_location("West", Makinaw);
		addloclist(Holton_Hooker);
		
		Padnos.add_location("North", Manitou);
		Padnos.add_location("East", Arboretum);
		Padnos.add_location("West", Loutit);
		addloclist(Padnos);
		
		Loutit.add_location("North", Kindshi);
		Loutit.add_location("South", Henry);
		Loutit.add_location("East", Padnos);
		addloclist(Loutit);
		
		Henry.add_location("North", Loutit);
		addloclist(Henry);
		
		Kindshi.add_location("South", Loutit);
		Kindshi.add_location("East", Manitou);
		addloclist(Kindshi);

		Arboretum.add_location("North", Holton_Hooker);
		Arboretum.add_location("West", Padnos);
        	addloclist(Arboretum);
	}

	// done
	void randomloc(std::reference_wrapper<LOCATIONS> cantloc){
		randomIndex = rand() % locationlist.size();
		if (locationlist[randomIndex] != cantloc){
			currentLocation = locationlist[randomIndex].get();
			std::cout << "location updated!\n";
		}
		else{
			randomloc(cantloc);
		}
	};
	
	//done
        void showHelp(std::vector<std::string>){
            std::cout << "Help Commands: \n" <<
                "help or ? - show this help message \n" <<
                "talk - talk to the NPC at your current location \n" <<
                "meet - meet the NPC at your current location \n" <<
                "take - take the item at your current location \n" <<
                "give - give your food to the elf \n" <<
                "go - use \"north\", \"east\", \"south\", or \"west\" to move to a new location\n" <<
                "items - shows the current items in your inventory \n" <<
                "look - shows the current location you are in\n" <<
                "quit - quit the game \n";
        }
	
	//done
        void talk(std::vector<std::string> target){
            if(target.empty()){
                std::cout << "There is no one here to talk to";
            }

            for (auto npc : currentLocation.getNPC()){
                if (npc.get().getName() == target[0]){
                    std::cout << npc.get().getName() << " says: " << npc.get().getMessage() << "\n";
                }
            }
        }

        //done
	void meet(std::vector<std::string> target) {
            if(target.empty()){
                std::cout << "There is no one here";
            }

            for (auto npc : currentLocation.getNPC()){
                if (npc.get().getName() == target[0]){
                    std::cout << "You meet " << npc.get().getName() << "\n";
                }
            }
        }
	
	//done
        void take(std::vector<std::string> target) {
            if(target.empty()){
                std::cout << "There is nothing to take \n";
            }
            
            std::string itemName = target[0];
	    ITEM item = currentLocation.removeItem(itemName); //why is there equals here
            
            // Need to fix weight cap
            if (currentWeight >= 30.0 || currentWeight + item.getWeight() >= 30.0){
                std::cout << "You are carrying too much weight \n";
            }

            for (auto item : currentLocation.getItem()){
                if (item.get().getName() == target[0]){
                    inventory.push_back(item);
                    currentWeight += item.get().getWeight();
                    std::cout << "You have taken " << item.get().getName() << "\n";
                }
            }
        }

        void give(std::vector<std::string> target){
            if(inventory.empty()){
                std::cout << "There is nothing in your inventory to give \n";
            }
            if(target.empty()){
                std::cout << "Please retype the command with the item you would like to give \n";
            }

            for (auto item : inventory){
                if (item.get().getName() == target[0]){
                    currentLocation.add_item(item);
		    if (currentLocation.getName() == "Arboretum"){
			caloriesNeded = caloriesNeded - item.get().getCalorie();
		    }
		    //if (item.get().getCalorie() == 0){
			    //currentLocation = ranloc.returnloc();
		    //}
                }
            }
                    
        }

        //done
	void go(std::vector<std::string> target){
		if (currentLocation.getneighbors().contains(target[0])){
			currentLocation.set_visited();
			currentLocation = currentLocation.getneighbors()[target[0]].get() ;
		} else {
			std::cout << "That is not a valid location.\n";
		};
				
        };

        void teleport(){
		randomloc(currentLocation);
	}
	
	void show_items(std::vector<std::string> target){
            if (inventory.empty()){
                std::cout << "There is nothing in your inventory \n";
            }
            std::cout << "Inventory: \n";
            for (auto item : inventory){
                std::cout << item << "\n";
            };
            std::cout << currentWeight << "/30.0 lbs \n"; 

        };

	//good
        void look(std::vector<std::string> target){
            std::cout << currentLocation.getName() << "\n";
        }

	//good
        void quit(std::vector<std::string> target){
            gameInProgress = false;
            throw std::runtime_error("You have quit the game");
        }

    private:
        bool gameInProgress = true;
        int caloriesNeded =  500;
        float currentWeight = 0;
        int elfCalories = 0;
        LOCATIONS currentLocation;
	std::vector<std::reference_wrapper<LOCATIONS>> locationlist;
        std::vector<std::reference_wrapper<ITEM>> inventory;

};

#endif
