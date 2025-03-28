#include <iostream>
#include <string_view>
#include "outputs.h"
using std::cout;


namespace Outputs {

  void ShowInsertName(int nName){
    cout << "Insertar el nombre #" << nName << '\n';
  }

  void AskForUserKey(){
    cout << "Please insert a key (has to be between: d,f,j,k)";
  }

  void ShowNameSelected(std::string_view name){
    cout << "The name selected is: " << name << '\n';
  }

}
