#include <iostream>
#include <string>
#include "inputs.h"


namespace Inputs {

  std::string GetName(){
    std::string name;
    std::getline(std::cin >> std::ws, name);
    return name;
  }

}
