#include <iostream>

class Point3d{

private:
  int m_x;
  int m_y;
  int m_z;

public:
  void setValues(int x, int y, int z){
    m_x = x;
    m_y = y;
    m_z = y;
  }

  // all the methods that are not going to modify members should be const so it can be accessed by const instances and non-const instances.
  void print() const{
    std::cout << "<" << m_x << "," << m_y << "," << m_z << ">" << std::endl;
  }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}
