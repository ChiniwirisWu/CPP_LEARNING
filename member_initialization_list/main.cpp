#include <iostream>

class Foo{
private:
  int m_x;
  int m_y;

public:
  Foo(int x, int y): m_x{x}, m_y{y}{
    std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
  }
};

int main(){
  Foo foo {3,4};
}
