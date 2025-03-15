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
                LOCATIONS(std::string name, std::string description, bool visited, std::map<std::string, std::reference_wrapper<LOCATIONS>> neighbors, std::vector<std::reference_wrapper<NPC>> location_npcs, std::vector<std::reference_wrapper<ITEM>> location_items){
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
            //void add_location(std::string direction, LOCATIONS location){
            //addinglocationsinsides
            //}

            void add_item(std::reference_wrapper<ITEM> item){
                location_items.push_back(item);
            }
            std::vector<std::reference_wrapper<ITEM>> getItem() const{
                return location_items;
            }
            ITEM* removeItem(const std::string& itemName) {
                for (auto it = location_items.begin(); it != location_items.end(); ++it) {
                    if (it.getName() == itemName) {
                        item = it;          //<-- What does this do?
                        location_items.erase(it);
                        return item;
                    }
                }
                return nullptr;
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
    std::map<std::string, std::function<void(std::vector<std::string>)>> setup_commands() {std::map<std::string, std::function<void(std::vector<std::string>)>> cmds;

        cmds["help"] = [this](std::vector<std::string> args) { showHelp(args); };
        cmds["?"] = [this](std::vector<std::string> args) { showHelp(args); };
        cmds["talk"] = [this](std::vector<std::string> args) { talk(args); };
        cmds["go"] = [this](std::vector<std::string> args) { go(args); };
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

        void create_world() {
// Everything needs to go in here ITEMS, NPCS, and LOCATIONS
        }

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
	
	//should be good?
        void talk(std::vector<std::string> target){
            if(target.empty()){
                std::cout << "There is no one here to talk to";
            }

            for (auto npc : currentLocation.getNPC()){
                if (npc.getName() == target[0]){
                    std::cout << npc.getName() << " says: " << npc.getMessage() << "\n";
                }
            }
        }

        //should ALSO be good?
	void meet(std::vector<std::string> target) {
            if(target.empty()){
                std::cout << "There is no one here";
            }

            for (auto npc : currentLocation.getNPC()){
                if (npc.getName() == target[0]){
                    std::cout << "You meet " << npc.getName() << "\n";
                }
            }
        }

        void take(std::vector<std::string> target) {
            if(target.empty()){
                std::cout << "There is nothing to take \n";
            }
            
            std::string itemName = target[0];
            item = currentLocation.removeItem(itemName); //why is there equals here?
            
            // Need to fix weight cap
            if (currentWeight >= 30.0 || currentWeight + item.getWeight() >= 30.0){
                std::cout << "You are carrying too much weight \n";
            }

            for (auto item : currentLocation.getItem()){
                if (item.getName() == target[0]){
                    inventory.push_back(item);
                    currentWeight += item.getWeight();
                    std::cout << "You have taken " << item.getName() << "\n";
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
                if (item.getName() == target[0]){
                    
                }
            }
                    
        }

        //done
	void go(std::vector<std::string> target){
		if (currentLocation.neighbors.contains(target)){
			currentLocation.set_visited(currentLocation);
			currentLocation = currentLocation.neighbors[target];
		} else {
			std::cout << "That is not a valid location.\n";
		};
				
        };

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
        std::vector<std::reference_wrapper<ITEM>> inventory;

};

#endif
