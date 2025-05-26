#ifndef INPUT
#define INPUT
#include <iostream>
#include <limits>
#include <typeinfo>
#include <string>

class MyInput{
private:
  void clearInput() const{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
public:
  MyInput() = default;

  template <typename T>
  T getTextInput() const;

  template <typename T>
  T getNumberInput() const;

};


//T can be std::string or std::string_view
template <typename T>
T inline MyInput::getTextInput() const{
  T text = {}; 
  bool isFinding = { true };
  while(isFinding){

    std::getline(std::cin >> std::ws, text);

    if(!std::cin){
      clearInput();

      std::cout << "An error just happened! press any button to retry~" << "\n";
      std::cin.get(); // this line is to make a break before trying again.
      continue;
    }

    isFinding = false;
    break;
  }
  return text;
}


template <typename T>
T inline MyInput::getNumberInput() const{
  //T can be any number
  T number = {}; 
  bool isFinding = { true };
  while(isFinding){

    std::cin >> number;

    if(!std::cin){
      clearInput();

      std::cout << "An error just happened! press any button to retry~" << "\n";
      std::cin.get(); // this line is to make a break before trying again.
      continue;
    }

    isFinding = false;
    break;
  }
  return number;
}

#endif
