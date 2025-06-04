#ifndef MONSTER_GENERATOR_H
#define MONSTER_GENERATOR_H

#include <string>
#include <string_view>
#include <iostream>
#include "random.h"

class Monster{

public:
  enum Type{
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    maxMonsterTypes = 8,
  };

private:
  Type m_type{};
  std::string m_name{"???"};
  std::string m_roar{"???"};
  int m_hitPoints{};

public: 
  Monster(Type type, std::string name, std::string roar, int hitPoints):
    m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}{}

  constexpr std::string_view getTypeString() const;

  void print() const;

};

// outside class method declaration.
constexpr inline std::string_view Monster::getTypeString() const {
  switch(m_type){
    case Dragon: return "Dragon";
    case Goblin: return "Goblin";
    case Ogre: return "Ogre";
    case Orc: return "Orc";
    case Skeleton: return "Skeleton";
    case Troll: return "Troll";
    case Vampire: return "Vampire";
    case Zombie: return "Zombie";
    default: return "???";
  }
}

void inline Monster::print() const{
  std::cout << m_name << " the " << getTypeString();
  if(m_hitPoints > 0){
    std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
  } else {
    std::cout << " is dead.\n"; 
  }
}

namespace MonsterGenerator{

  // main function of this header.
  std::string inline getName(int index = 0){
    switch(index){
      case 0: return "Frederick";
      case 1: return "Lucas";
      case 2: return "Jett";
      case 3: return "Viper";
      case 4: return "Sova";
      case 5: return "Chamber";
      default: return "Ari";
    }
  }

  std::string inline getRoar(int index = 0){
    switch(index){
      case 0: return "*Huu*";
      case 1: return "*Roar*";
      case 2: return "*Wuff*";
      case 3: return "*Miaw*";
      case 4: return "*Waa*";
      case 5: return "*Gwee*";
      default: return "*Prr*";
    }
  }

  Monster::Type getType(int index = 0){
    return static_cast<Monster::Type>(index);
  }


  Monster inline generate(){
    Monster monster { MonsterGenerator::getType(Random::get(0, 7)), MonsterGenerator::getName(Random::get(0, 5)), MonsterGenerator::getRoar(Random::get(0, 5)), Random::get(1, 100) };
    return monster;
  }
}



#endif
