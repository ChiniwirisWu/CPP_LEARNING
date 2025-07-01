#include "player.h"
#include "potion.h"

using namespace Potion;

int main(){
  std::cout << "Welcome to Roscoe's potion emporium!\n";

  Player::Player player {};

  shop();

  std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
  return 0;
}
