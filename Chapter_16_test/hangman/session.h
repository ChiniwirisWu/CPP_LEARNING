#ifndef SESSION_H
#define SESSION_H

#include "words.h"
#include <iostream>
#include <iterator>
#include <string>
#include <limits>

class Session{
private:
  std::string m_word {WordList::getRandomWord()}; 

public:
  
  void showWord(){
    std::cout << "The word is: ";
    for([[maybe_unused]] auto c : m_word){
      std::cout << "_";
    }
    std::cout << "\n";
  }
  
  void getLetter(){
    char letter;
    while(true){
      std::cout << "Enter your next letter: ";
      std::cin >> letter;

      bool isNaN {!std::cin};
      bool isNumber {letter < 'a' || letter > 'z'};

      // if there is weird input
      if(isNumber || isNaN){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That wasn't a valid input. Try again'\n\n";
        continue;
      }


      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
};

#endif
