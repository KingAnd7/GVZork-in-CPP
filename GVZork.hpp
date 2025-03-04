#ifndef         __HPP__GVZork__
#define         __HPP__GVZork__

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>

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
                LOCATIONS(std::string name, std::string description, bool visited, std::map<std::string, LOCATIONS> neighbors, std::vector<NPC> location_npcs, std::vector<ITEM> location_items){
			if (name.empty()){
				throw std::runtime_error("Name cannot be empty");
			}else{
				this->name = name;
			if (description.empty()){
				throw std::runtime_error("Description cannot be empty");
			}else{
				this->description = description;
			}
		}
		//void add_location(std::string direction, LOCATIONS location){
		//awawa
		//}

		void add_item(ITEM item){
			location_items.push_back(item);
		}
		void add_npc(NPC npc){
			location_npcs.push_back(npc);
		}
		void set_visited(){
			if (visited == false){
				visited = true;
			}
		}		
        private:
		std::string name;
		std::string description;
		bool visited;
		std::map<std::string, LOCATIONS> neighbors;
		std::vector<NPC> location_npcs;
		std::vector<ITEM> location_items;
};

class GAME{
    public:
        void create_world() {
// Everything needs to go in here ITEMS, NPCS, and LOCATIONS
        }

        void showHelp(std::vector<std::string>){
            printf("Help Commands:\n"
                "talk - talk to the NPC at your current location \n"
                "meet, take, give, go, show_items, look, quit");
        }

        void talk(std::vector<std::string> target){
            if( target.empty()){
                std::cout << "There is no one here to talk to";
            }

            for (auto npc : currentLocation->getNPCs()){
                if (npc->getName() == target){
                    std::cout << npc->getName() << " says: " << npc->getMessage() << "\n";
                }
            }
            
        }

        void meet(std::vector<std::string> target) {
            if( target.empty()){
                std::cout << "There is no one here";
            }

            for (auto npc : currentLocation->getNPCs()){
                if (npc->getName() == target){
                    std::cout << "You meet " << npc->getName() << "\n";
                }
            }
            
        }

        void take(std::vector<std::string> target) {
            if(target.empty()){
                std::cout << "There is nothing to take \n";
            }

        }

        void give(std::vector<std::string> target){
            if(inventory.empty()){
                std::cout << "There is nothing in your inventory to give \n";
            }
            if(target.empty()){
                std::cout << "Please retype the command with the item you would like to give \n";
            }

        }

        void go(std::vector<std::string> target){

        }

        void show_items(std::vector<std::string> target){

        }

        void look(std::vector<std::string> target){

        }

        void quit(std::vector<std::string> target){
            gameInProgress = false;
            throw std::runtime_error("You have quit the game");
        }
    private:
        bool gameInProgress = true;
        int caloriesNeded =  500;
        int currentWeight = 0;
        int elfCalories = 500;
        LOCATIONS* currentLocation;
        std::vector<ITEM*> inventory;

};

#endif
