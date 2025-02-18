#include "GVZork.hpp"

int main(int argc, char const *argv[]){
    try {
        Item rustyNail("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, 1);
        std::cout << rustyNail << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
} 