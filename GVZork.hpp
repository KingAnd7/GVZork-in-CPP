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
            if (gobbo != true || gobbo != false){
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
        NPC(std::string name, std::string description, std::vector<ITEM> inventory, bool gobbo){
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
            if (gobbo != true || gobbo != false){
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

    private:
    std::string name;
    std::string description;
    std::vector<ITEM> inventory;
    bool gobbo;
};

class LOCATIONS{
        public:
                LOCATIONS(std::string map, std::string direction, LOCATIONS location, NPC npc, std::vector<ITEM> items){

                }
        private:

};

#endif