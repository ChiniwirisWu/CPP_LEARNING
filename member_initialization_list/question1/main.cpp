#include <iostream>
#include <string_view>

class Ball{
private:
  std::string m_color { "white" }; //it is better that classes does not have a reference values.
  float m_radius { 0.4 };
public:
  Ball(std::string_view color, float radius): 
    m_color {color}, 
    m_radius {radius}
  {};
  Ball(){};

  // i make these methods const because i don't modify its member values.
  std::string_view getColor() const {
    return m_color;
  }

  float getRadius() const {
    return m_radius;
  }
};

void print(const Ball ball){
  std::cout << "Ball(" << ball.getColor() << "," << ball.getRadius() << ")" << std::endl;
}

int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

  Ball white{};
  print(white);

	return 0;
}
