#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <array>
#include <string_view>
#include <cassert>

// namespace para guardar constantes.
namespace Potion{
  enum Type{
    healing,
    mana,
    speed,
    invisibility,
    max_type,
  };

  using namespace std::string_view_literals;
  constexpr std::array<int, static_cast<int>(max_type)> types { healing, mana, speed, invisibility };
  constexpr std::array<int, static_cast<int>(max_type)> cost { 20, 30, 12, 50 };
  constexpr std::array<std::string_view, static_cast<int>(max_type)> name { "healing"sv, "mana"sv, "speed"sv, "invisibility"sv };

  static_assert(types.size() == max_type);
  static_assert(cost.size() == max_type);
  static_assert(name.size() == max_type);

  void inline shop(){
    std::cout << "Here is our selection for today: \n"; 
    for(const auto p : types){
      std::cout << p << ") " << name[p] << " cost " << cost[p] << '\n';
    }
    
    std::cout << '\n';
  }
};

#endif
