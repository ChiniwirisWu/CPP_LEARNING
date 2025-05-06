#include <iostream>
#include <string>
#include <chrono>

void ignoreLine(){
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct AdvertisingData {
  // default values initialization.
  int addsWatched {0};
  float percentageOfClicks {0.0};
  float averageEarningsPerClick {0.0};
};

template <typename T>
T getUserInput(T& xOut){
  while(true){
    std::cin >> xOut;
    //checking if there is an error in the iostream.
    if(!std::cin){
        std::cin.clear(); 
        ignoreLine();
        std::cout << ((typeid(T) == typeid(std::string)) ? "Must introduce an string." :  "Must introduce an integer") << std::endl;
        continue; //skips all the following code
    }
    return xOut;
  }
}

AdvertisingData getUserData(){
  AdvertisingData temp {};
  
  std::cout << "Introduce 1) addWatched, 2) percentageOfClicks, 3) averageEarnings" << std::endl;
  getUserInput(temp.addsWatched);
  getUserInput(temp.percentageOfClicks);
  getUserInput(temp.averageEarningsPerClick);
  std::cout << std::endl;
  return temp;
}

//es curioso como ahora no uso string_view porque paso los argumentos por referencia. 
void printTodayStats(AdvertisingData& advertisingData){
  std::cout << "Adds watched: " << advertisingData.addsWatched << std::endl;
  std::cout << "Percentage of clicks: " << advertisingData.addsWatched << std::endl;
  std::cout << "Average Earnings per click " << advertisingData.averageEarningsPerClick << std::endl;
  std::cout << "Todays earnings: $" << (advertisingData.addsWatched * (advertisingData.percentageOfClicks/100) * advertisingData.averageEarningsPerClick) << std::endl; 
}

int main(){
  AdvertisingData advertisingData { getUserData() }; //list initialization.
  printTodayStats(advertisingData);
}
