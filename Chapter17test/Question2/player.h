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
    static constexpr int maxGold {70};

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

  //TODO: i am here.
    void interact(){
      std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    }

    void print(){
      std::cout << "Hello '" << m_name << "' you have " << m_gold << " gold\n\n";
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
