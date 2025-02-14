#include <string>
#include <iostream>

class Item{
    public:
        Item(std::string name, std::string description, int calorie, float weight){
            this-> name = name;
            this->description = description;
            this->calorie = calorie;
            this->weight = weight;
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
        void setweight(float newValue){
            weight = newValue;
        }
        
    private:
        std::string name;
        std::string description;
        int calorie;
        float weight;

};