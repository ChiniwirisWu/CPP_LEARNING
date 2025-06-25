#include <array>
#include <iostream>

template <typename T, std::size_t N>
void print(const std::array<T, N>& array){
  int index { 0 };
  bool isFirst {true};

  if(N > index){
    std::cout << "The array ("; 
    for(const T element : array){

      if(isFirst){
        std::cout << element;  
        isFirst = false;
      }

      std::cout << ", " << element;  
    }
    std::cout << ") has " << N << " elements. \n\n"; 
  }

}

int main(){
  constexpr std::array array {1, 4, 6, 9};
  print(array);
  constexpr std::array array2 {'h', 'e', 'l','l','o'};
  print(array2);
}
