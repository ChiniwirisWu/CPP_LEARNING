#include <vector>
#include <string_view>
#include <string>
#include <iostream>

template <typename T>
bool isValueInArray(std::vector<T> &array, const T &value){
  for(const auto &item : array){
    if(item == value){
      return true;
    }
  }
  return false;
}

int main(){
  std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
  std::string name;

  std::cout << "Ingresa un nombre: ";
  std::getline(std::cin >> std::ws, name);
  if(!std::cin){
    std::cin.clear();
  }

  std::cout << ((isValueInArray<std::string_view>(names, name)) ? "El nombre pertenece a la lista" : "El nombre no se encuentra en la lista.");

  return 0;
}
