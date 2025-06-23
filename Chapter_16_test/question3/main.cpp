#include <utility>
#include <vector>
#include <iostream>


template <typename T>
void printArray(const std::vector<T>& array){
  int counter {0};

  std::cout << "With the array (";
  for(const T item : array){
    if(counter >= static_cast<int>(array.size()) - 1){
      std::cout << " " << item << " ";
    } else {
      std::cout << " " << item << ", ";
    }
    counter++;
  }
  std::cout << ")\n";

}

template <typename T>
void printMinMax(const std::vector<T>& array){

  if(array.size() < 1) {
    std::cout << "The array is empty.\n"; 
    return;
  }

  int index = {0};
  std::pair<std::size_t, T> min {index, array[0]};
  std::pair<std::size_t, T> max {index, array[0]};
  
  for(const T element : array){
    if(element < min.second){
      min.first = index;
      min.second = element;
    }

    if(element > max.second){
      max.first = index;
      max.second = element;
    }

    index++;
  }

  std::cout << "The min element has index " << min.first << " and value " << min.second << "\n"; 
  std::cout << "The max element has index " << max.first << " and value " << max.second << "\n\n"; 
}

int main(){
  std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
  std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

  printArray(v1);
  printMinMax(v1);

  printArray(v2);
  printMinMax(v2);
}
