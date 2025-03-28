#ifndef OUTPUTS_H
#define OUTPUTS_H

#include <string_view>
namespace Outputs {

  void ShowInsertName(int nName);
  void AskForUserKey();
  void ShowNameSelected(std::string_view name);

}

#endif
