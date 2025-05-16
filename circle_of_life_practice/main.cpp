#include <cstdlib>
#include "properties.h" // here I save the variables of each property

void fillProperties(){
  Properties::carrer.showDescription();
  Properties::carrer.setScore();

  Properties::personalGrowth.showDescription();
  Properties::personalGrowth.setScore();

  Properties::health.showDescription();
  Properties::health.setScore();

  Properties::finance.showDescription();
  Properties::finance.setScore();

  Properties::familyFriends.showDescription();
  Properties::familyFriends.setScore();

  Properties::love.showDescription();
  Properties::love.setScore();

  Properties::fun.showDescription();
  Properties::fun.setScore();

  Properties::comunity.showDescription();
  Properties::comunity.setScore();

  Properties::environment.showDescription();
  Properties::environment.setScore();

  Properties::sprirituality.showDescription();
  Properties::sprirituality.setScore();
}


void showResults(){
  system("clear");
  Properties::carrer.showScore();
  Properties::personalGrowth.showScore();
  Properties::health.showScore();
  Properties::finance.showScore();
  Properties::familyFriends.showScore();
  Properties::love.showScore();
  Properties::fun.showScore();
  Properties::comunity.showScore();
  Properties::environment.showScore();
  Properties::sprirituality.showScore();
}

int main(){ 
  fillProperties();
  showResults();
  return 0;
}
