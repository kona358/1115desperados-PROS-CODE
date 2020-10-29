#include "main.h"
#include "subsystems.hpp"
#include "okapi/api.hpp"
#include "autoPrograms.hpp"
#include "display.hpp"


using namespace okapi;
//running a function here run them during auton
//runSelectedAuto(); is a function that lets you pick an auton on the brain screen
//autons are in autoPrograms.cpp
//display.cpp lets you change the name of autons and what "autons"(functions) are run during match autons
void autonomous() {
//red2();
//flip();
// blue2();
//  blue1();
  //red1();
//skills();
  //stack();
runSelectedAuto();
}
