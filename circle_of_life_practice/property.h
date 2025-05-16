#ifndef PROPERTY
#define PROPERTY

#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include "input.h" // used for getInput<int>(); line 23

class Property{
private:
  std::string m_title {};
  std::string m_description {};
  int m_score {0};
public:
  Property(std::string title, std::string description): m_title {title},  m_description {description}{
    // constructor block after initialization.
  }

  void showDescription(){
    system("clear");
    std::cout << "Property name: " << m_title << std::endl;
    std::cout << "Description: " << m_description << std::endl;
  }

  int getScore(){
    return m_score;
  }

  void showScore() const {
    std::cout << m_title << ": " << m_score << std::endl;
  }

  void setScore(){
    m_score = getInput<int>();
  }

  std::string_view getTitle() const {
    return m_title;
  }

  std::string_view getDescription() const {
    return m_description;
  }
};

#endif
