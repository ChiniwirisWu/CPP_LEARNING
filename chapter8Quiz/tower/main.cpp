#include "calculate.h"

// Gets tower height from user and returns it
double getDoubleValue(std::string_view message)
{
	std::cout << message;
	double value{};
	std::cin >> value;
	return value;
}


int main()
{
	const double towerHeight{ getDoubleValue("Enter the height of the tower in meters: ") };
  const double startingSecond { getDoubleValue("Enter the starting second: ") };
  Calculate::calculateAndPrintBallHeightSequence(towerHeight, startingSecond);

	return 0;
}
