#ifndef PLAYER_H
#define PLAYER_H

#include <ios>
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "random.h"
#include "potion.h"

namespace Player{

  class Player{
  private:
    static constexpr int minGold {70};
    static constexpr int maxGold {120};

    int m_gold {Random::get(minGold, maxGold)};
    std::string m_name {};
    std::array<int, static_cast<int>(Potion::max_type)> m_inventory {}; // access by array[Potion::Type]
  public:
    
    Player(){
      setName();
      print();
    }

    void setName(){
      std::string name {}; 
      while(true){

        std::cout << "Enter your name: ";
        std::getline(std::cin >> std::ws, name);

        if(!std::cin){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Try again\n\n";
          continue;
        }

        m_name = name;
        break;
      }
    }

    bool interact(){
      char input;
      std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

      while(true){
        std::cin >> input;
        
        // check for out of scope inputs.
        bool isNaN = !std::cin;

        if(isNaN){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Try again. ";
          continue;
        }
        
        // check numeric inputs
        bool isNumber = input < 'a' || input > 'z';
        
        if(isNumber){
          int option { static_cast<int>(input) - '0' };
          if(option >= 0 && option < static_cast<int>(Potion::max_type)){
            if(m_gold >= Potion::cost[option]){
              // buy.
              m_inventory[option]++;
              m_gold -= Potion::cost[option];
              std::cout << "You bought a " << Potion::name[option] << ". You have " << m_gold << " left.\n\n";
              return true;
            } else {
              // don't have enough gold to buy.
              std::cout << "Don't have enough gold to buy this item. Select another one: ";
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              continue;
            }

          } else {
            std::cout << "Invalid option. Try again: ";  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
          }
        }
          
        // check for char handling
        if(input == 'q'){
          printInventory();
          return false;
        } else {
          std::cout << "Invalid option. Try again: ";  
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          continue;
        }

      // end of while loop.
      }

    }

    void print(){
      std::cout << "Hello '" << m_name << "' you have " << m_gold << " gold\n\n";
    }

    void printInventory(){
      std::cout << "Your inventory contains: \n";
      for(std::size_t i {0}; i < m_inventory.size(); i++){
        if(m_inventory[i] > 0){
          std::cout << m_inventory[i] << "X " << Potion::name[i] << " potion\n";
        }
      }
      
      std::cout << "You scaped with " << m_gold << " of gold.\n\n";
    }

    int gold() const{
      return m_gold; 
    } 

    int inventory(Potion::Type type) const {
      return m_inventory[static_cast<size_t>(type)]; 
    }
  };
  
}

#endif
