#include "words.h"
#include <iostream>

int main(){
  std::cout << "Welcome to C++man (a variant of Hangman)\n";
  std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";

  for(int i = 0; i < 20; i++){
    std::cout << "The word is: " << WordList::getRandomWord();
    std::cout << "\n";
  }
}
