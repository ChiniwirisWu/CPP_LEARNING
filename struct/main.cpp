#include <string_view>
#include <string>
#include <iostream>

using string = std::string;

struct Person{
  string name;
  int age;
  float height;
};

std::ostream& operator<<(std::ostream& out, Person& person){
  out << person.name << ", " << person.age << ", " <<  person.height << std::endl;
  return out;
}

int main(){
  Person person1 { "Jeff", 21, 1.89 }; 
  Person person2 { .name{ "Mary" }, .age{25}, .height{1.6} };
  std::cout << person1 << std::endl;
}
