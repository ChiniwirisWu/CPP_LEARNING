#include "calculate.h"
// Returns the current ball height after "seconds" seconds
// Prints ball height above ground
namespace Calculate {
  void printBallHeight(double ballHeight, double seconds)
  {
    if (ballHeight > 0.0)
      std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
    else
      std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
  }

  double calculateBallHeight(double towerHeight, double seconds)
  {
    // Using formula: s = (u * t) + (a * t^2) / 2
    // here u (initial velocity) = 0, so (u * t) = 0
    const double fallDistance { CONSTANTS::gravity * (seconds * seconds) / 2.0 };
    const double ballHeight { towerHeight - fallDistance };

    // If the ball would be under the ground, place it on the ground
    if (ballHeight < 0.0){
      return 0.0;
    } else {
      return ballHeight;
    }
  }

  // Calculates the current ball height and then prints it
  // This is a helper function to make it easier to do this
  void calculateAndPrintBallHeightSequence(double towerHeight, double startingSecond)
  {
    double ballHeight;
    double second { startingSecond };
    bool isBallOnAir = true;

    while (isBallOnAir){

      ballHeight = calculateBallHeight(towerHeight, second);  
      printBallHeight(ballHeight, second);

      isBallOnAir = (ballHeight > 0.0f);
      second += 0.1;
    }
  }
}
