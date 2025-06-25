#include <string_view>
#include <array>
#include <iostream>
#include <string>

struct Item{
  std::string_view name; 
  int gold;
};

constexpr std::array items {
  Item{"Sword", 4}, Item{"Bow", 2}, Item{"Shield", 3}
};

const Item* findItem(const std::string_view name){
  for(const auto& item : items){
    if(item.name == name){
      return &item;
    }
  } 
  return nullptr;
}

const void print(const Item* item){
  if(item == nullptr){
    std::cout << "Item not founded\n\n"; 
    return;
  }
  std::cout << "A " << item->name << " cost " << item->gold << '\n';
}

int main(){
  constexpr std::string_view nothing {"Nothing"};
  const Item* item1 {findItem("Sword")};
  print(item1);

  const Item* item2 {findItem("Shield")};
  print(item2);

  const Item* item3 {findItem("Spear")};
  print(item3);
} 
