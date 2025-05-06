#include <iostream>
// use of libraries and templates
#include "getUserInput.h"

struct Fraction{
  int numerator {0};
  int denominator {0};
};

// reference parameters
Fraction getFraction(){
  Fraction temp {};
  std::cout << "Insert numerator and denominator" << std::endl;
  
  UserInput::getUserInput(temp.numerator);
  UserInput::getUserInput(temp.denominator);
  std::cout << std::endl;
  return temp;
}

// reference parameters
Fraction multiplyFractions(Fraction& x, Fraction& y){
  Fraction result;
  result.numerator = x.numerator * y.numerator;
  result.denominator = x.denominator * y.denominator;
  return result;
}

// operator overload
std::ostream& operator<<(std::ostream& out, Fraction& fraction){
  out << fraction.numerator << "/" << fraction.denominator;
  return out;
}

int main(){
  // list initialization
  Fraction x { getFraction() };
  Fraction y { getFraction() };


  Fraction result { multiplyFractions(x, y) };
  std::cout << x << " times " << y << " equals " << result << std::endl;


  // list initialization
  Fraction z { 3, 2 };
  std::cout << "List initalization: " << z << std::endl;
}
