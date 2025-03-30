#include "main.h"

int main(){
  setChosenFood();
  showChosenFood();
}

//primary function
void showChosenFood(){
  switch(FOODS::chosenFood){
    case 1:
      printChosenFood(FOODS::arroz); 
      break;
    case 2:
      printChosenFood(FOODS::dumpling); 
      break;
    case 3:
      printChosenFood(FOODS::chuleta_cerdo); 
      break;
    case 4:
      printChosenFood(FOODS::bisteck_res); 
      break;
    default:
      printChosenFood("Nothing."); 
    break;

  }
}

//primary function
void setChosenFood(){
  int optionSelected { 0 }; //here is nothing selected
  bool isOutsideLimits = ((optionSelected <= 0) || (optionSelected > 4));
  while (isOutsideLimits){
    showMenu(); 
    //exploit: insert a string instead of an integer
    cin >> optionSelected;
    isOutsideLimits = ((optionSelected <= 0) || (optionSelected > 4));
    if(!isOutsideLimits){
      FOODS::chosenFood = static_cast<int>(optionSelected); 
    } else {
      continue;
    }
  } 
}

//outputs
void showMenu(){
  cout << "Please select a number between 1 and 4: " << '\n';
}

void printChosenFood(std::string_view foodSelected){
  cout << "Food selected: " << foodSelected << '\n';
}
