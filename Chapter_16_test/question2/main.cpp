#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

namespace Items{
  enum Type{
    health_potion,
    torch,
    arrow,
    max_items // the number of item_types = 3
  };
};

int countTotalItems(const std::vector<int>& items){
  int sum {0};

  for(const int item : items){
    sum += item;
  }

  return sum;
}

std::string getItemNamePlural(Items::Type itemType){

  switch (itemType){

    case Items::health_potion: return "health potions";

    case Items::torch: return "torches";

    case Items::arrow: return "arrows";

    case Items::max_items: return "items";

    default: return "Unvaliable option";
  }
}

std::string getItemNameSingular(Items::Type itemType){

  switch (itemType){

    case Items::health_potion: return "health potion";

    case Items::torch: return "torch";

    case Items::arrow: return "arrow";

    case Items::max_items: return "items";

    default: return "Unvaliable option";
  }
}

void printInventory(std::vector<int>& inventory){
  int counter = 0;
  inventory.push_back(countTotalItems(inventory));

  for(const int itemAmount : inventory){
    if(itemAmount > 1){
      std::cout << "You have " << itemAmount <<  " " << getItemNamePlural(static_cast<Items::Type>(counter)) << '\n';
    } else {
      std::cout << "You have " << itemAmount <<  " " << getItemNameSingular(static_cast<Items::Type>(counter)) << '\n';
    }
    counter++;
  }

  inventory.pop_back();
}

int main(){
  std::vector inventory {1, 5, 10};
  
  assert(inventory.size() == Items::max_items);

  printInventory(inventory);
}
