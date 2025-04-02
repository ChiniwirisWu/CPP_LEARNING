#ifndef CALCULATE_H
#define CALCULATE_H
#include "constants.h"
#include <iostream>
namespace Calculate {

  double calculateBallHeight(double towerHeight, double seconds);
  void printBallHeight(double ballHeight, double seconds);
  void calculateAndPrintBallHeightSequence(double towerHeight, double startingSecond);

}
#endif
