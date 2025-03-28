#include <iostream>
#include <string_view>
#include "names.h"
#include "outputs.h"
#include "inputs.h"

using namespace Names;

//foward declarations and static variables
void SetAllNames();
void SetUserKey();
void SetSelectedName();

static char key;
static std::string_view nameSelected;

//end of foward declarations

int main(){
  SetAllNames();
  SetUserKey();
  SetSelectedName();
  Outputs::ShowNameSelected(nameSelected);
}

void SetSelectedName(){
  if(key == 'd'){
    nameSelected = name1;
  } 
  if(key == 'f'){
    nameSelected = name2;
  } 
  if(key == 'j'){
    nameSelected = name3;
  } 
  if(key == 'k'){
    nameSelected = name4;
  } 
}

void SetUserKey(){
  while (key != 'd' && key != 'f' && key != 'j' && key != 'k'){
    Outputs::AskForUserKey();
    std::cin >> key; 
  }
}

void SetAllNames(){

  //I hate this function but I don't know about list yet!
  Outputs::ShowInsertName(1); 
  name1 = Inputs::GetName();

  Outputs::ShowInsertName(2); 
  name2 = Inputs::GetName();

  Outputs::ShowInsertName(3); 
  name3 = Inputs::GetName();

  Outputs::ShowInsertName(4); 
  name4 = Inputs::GetName();
}
