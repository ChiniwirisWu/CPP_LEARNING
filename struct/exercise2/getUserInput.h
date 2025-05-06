#ifndef USER_INPUT
#define USER_INPUT

#include <iostream>
#include <chrono>
namespace UserInput {

  // some user input protection
  void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  //method to getUserInput
  template <typename T>
  void getUserInput(T& xOut){
    while(true){
      std::cin >> xOut;
      //checking if there is an error in the iostream.
      if(!std::cin){
          std::cin.clear(); 
          ignoreLine();
          std::cout << ((typeid(T) == typeid(std::string)) ? "Must introduce an string." :  "Must introduce an integer") << std::endl;
          continue; //skips all the following code
      }
      return;
    }
  }
}
#endif
