#include <iostream>
#include <string_view>

// Write the function getQuantityPhrase() here
std::string_view getQuantityPhrase(int quantity){
  std::string_view phrase;
  if(quantity < 0)
    phrase = "negative";
  if(quantity == 0)
    phrase = "no";
  if(quantity == 1)
    phrase = "a single of";
  if(quantity == 2)
    phrase = "a couple of";
  if(quantity == 3)
    phrase = "a few of";
  if(quantity > 3)
    phrase = "many";
  return phrase;
}

// Write the function getApplesPluralized() here
std::string_view getApplesPluralized(int quantity){
  std::string_view phrase;
  if(quantity > 0){
    phrase = "apples";
  } else {
    phrase = "apple";
  }
  return phrase;
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
