#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <vector>
#include "random.h"

namespace WordList{

  std::vector<std::string> inline words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

  // Get a random word from WordList::words 
  std::string inline getRandomWord(){
    return words[Random::get(0, static_cast<int>(words.size() - 1))] ;
  }
}

#endif
