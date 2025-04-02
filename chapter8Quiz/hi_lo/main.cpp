#include "random.h"
#include <iostream>
#include <string>

int getUserGuess(){
  int guess{0};
  std::cout << "Insert a number between 1 and 100: ";
  std::cin >> guess; 
  return guess;
}

void showIfCorrectAnswer(bool isCorrect){
  std::string message = isCorrect ? "Your guess is right!" : "Incorrect guess, try again!";
  std::cout << message << '\n';
}

void showIfHiLow(int target, int guess){
  std::string message =  (target > guess) ? "Your answer is low." : "Your answer is high.";
  std::cout << message << '\n';
}

void run(){
  int target = Random::get(1, 100);    
  int attemps = 7;
  int guess;

  while(attemps > 0){
    guess = getUserGuess();
    if(target == guess){
      showIfCorrectAnswer(true);
      break;
    } else {
      showIfHiLow(target, guess);
      showIfCorrectAnswer(false);
      --attemps;
    }
  } 
}

char getIfRestartGame(){
  char playAgain = 'y';
  std::cout << "Thanks for playing! would you play again? (y/n): ";
  std::cin >> playAgain;
  return playAgain;

}

int main(){
  char playing = 'y';

  while (playing == 'y'){
    run();
    playing = getIfRestartGame();
  }

  std::cout << "See you next time!" << '\n';
}
