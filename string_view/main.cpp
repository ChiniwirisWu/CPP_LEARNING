#include <iostream>
#include <string>
#include <string_view>


std::string getName(int n){
  std::string name;
  std::cout << "Enter the name of person #" << n << ":\n";
  std::getline(std::cin >> std::ws, name);
  return name;
}

int getAge(std::string_view name){
  int age;
  std::cout << "Enter age for " << name << ":\n"; 
  std::cin >> age;
  return age;
}

void showWhoIsOlder(std::string_view name1, std::string_view name2, int age1, int age2){
  if(age1 > age2){
    //name 1 is older than name 2
    std::cout << name1 << "(" << age1 << ") is older than " << name2 << "(" << age2 << ")\n";
  } else {
    //name 2 is older than name 1
    std::cout << name2 << "(" << age2 << ") is older than " << name1 << "(" << age1<< ")\n";
  }
}

int main(){
  
  //declaration of user's variables
  std::string name1;
  std::string name2;
  int age1;
  int age2;

  name1 = getName(1);
  name2 = getName(2);
  age1 = getAge(name1);
  age2 = getAge(name2);

  showWhoIsOlder(name1, name2, age1, age2);
}



