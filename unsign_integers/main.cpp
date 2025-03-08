#include <iostream>

int main(){
  unsigned short x{65535};
  std::cout << sizeof(x) << "\n";
  std::cout << x << " Is permitted" << "\n";
  x = 65536;
  std::cout << x << " Is overflowed by 1" << "\n";
  x = 65537;
  std::cout << x << " Is overflowed by 2" << "\n";
  return 0;
}
