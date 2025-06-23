#include <vector>
#include <string_view>

using namespace std::literals::string_view_literals;

int main(){
  std::vector evens {2,4,6,8,10,12};

  const std::vector floats {1.2, 3.4, 5.6, 7.8};

  const std::vector names {"Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv}; 

  std::vector number {12};

  std::vector<int> numbers (12);
}
