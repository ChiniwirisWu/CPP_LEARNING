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

  bool isEqual(Point3d& point2){
    if(m_x == point2.m_x && m_y == point2.m_y && m_z == point2.m_z){
      return true;
    } else {
      return false;
    }
  }
};

int main()
{
	Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

	return 0;
}
