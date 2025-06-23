#include "words.h"
#include "session.h"
#include <iostream>

int main(){
  std::cout << "Welcome to C++man (a variant of Hangman)\n";
  std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";
  
  Session session;

  while(true){
    session.showWord();
    session.getLetter();
  }
}
