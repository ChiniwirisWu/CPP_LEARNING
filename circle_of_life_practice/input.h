#ifndef INPUT
#define INPUT
#include <iostream>
#include <limits>

template <typename T>
T getInput(){
  T score {};
  bool isInvalid {true};

  while(isInvalid){
    std::cout << "> "; 
    std::cin >> score;
    if(!std::cin){
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Invalid input from user." << std::endl;
      std::cout << "Press any button to continue...";
      std::cin.get(); // this line is to make a break before trying again.
      continue;
    }
    std::cout << std::endl;
    isInvalid = false; // this statement breaks the while loop.
  }
  return score;
}

#endif
