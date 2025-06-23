#ifndef SESSION_H
#define SESSION_H

#include "words.h"
#include <iostream>
#include <iterator>
#include <string>
#include <limits>
#include <vector>

class Session{
private:
  int m_attemps {10};
  bool m_isRunning {true};
  std::string m_word {WordList::getRandomWord()}; 
  std::vector<char> m_guess;
  std::vector<char> m_wrong;

public:

  void run(){
     
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";

    while(m_isRunning){
      showStatus();
      getLetter();
    }
  }

  void showStatus(){
    std::cout << "The word is: ";
    for([[maybe_unused]] auto c : m_word){
      if(isGuessedBefore(c)){
        std::cout << c;
      } else {
        std::cout << "_";
      }
    }

    std::cout << "\t\tWrong guesses: ";
    for([[maybe_unused]] int i = 0; i < m_attemps - static_cast<int>(m_wrong.size()); i++){
      std::cout << "+";
    }
    for([[maybe_unused]] const auto c : m_wrong){
      std::cout << c;
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

      // if there is weird input.
      if(isNumber || isNaN){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That wasn't a valid input. Try again'\n\n";
        continue;
      }

      // if it was guessed before.
      if(confirmGuess(letter) && isGuessedBefore(letter) || isGuessedWrongBefore(letter)){
        std::cout << "You already guessed that. Try again'\n\n";
        continue;
      }

      if(confirmGuess(letter)){

        setMatch(letter, m_guess);

        // game over handling
        if(isGameOver()){
          std::cout << "Congratulations! you have guessed all the letters is in the word!\n\n";
          m_isRunning = false;
        } else {
          std::cout << "Yes, '" << letter << "' is in the word!\n\n";
        }

      } else {

        m_wrong.push_back(letter);

        // game over handling
        if(isGameOver()){
          std::cout << "Game Over you have not guessed all the letters is in the word...\n\n";
          m_isRunning = false;
        } else {
          std::cout << "No, '" << letter << "' is not in the word!\n\n";
        }
      }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

  bool isGameOver(){
    // return if won
    if(static_cast<int>(m_guess.size()) == static_cast<int>(m_word.size())){
      return true;
    }

    // return if loose
    if(static_cast<int>(m_wrong.size()) == m_attemps){
      return true;
    }

    return false;
  }

  bool confirmGuess(char guess){
    for([[maybe_unused]] const auto c : m_word){
      if(c == guess)
        return true;
    }
    return false;
  }

  bool isGuessedBefore(char guess){
    for([[maybe_unused]] const auto c : m_guess){
      if(c == guess)
        return true;
    }
    return false;
  }
  
  bool isGuessedWrongBefore(char guess){
    for([[maybe_unused]] const auto c : m_wrong){
      if(c == guess)
        return true;
    }
    return false;
  }

  void setMatch(char c, std::vector<char>& arr){
    for([[maybe_unused]] auto l : m_word){
      if(l == c){
        arr.push_back(c);
      }
    }
  }

};

#endif
