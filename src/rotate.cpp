#include "main.h"
#include "rotate.hpp"

// Controller Output
RotateControllerOutput::RotateControllerOutput(const std::shared_ptr<ChassisModel> chassisModel)
    : chassisModel(chassisModel) {} // constructor taking a shared pointer to a chassis model

void RotateControllerOutput::controllerSet(double ivalue) { // function PID controller calls to move the chassis
  chassisModel->rotate(ivalue);
}

// Controller Input
RotateControllerInput::RotateControllerInput(const std::shared_ptr<pros::Imu> inertialSensor)
    : inputImu(inertialSensor) {} // constructor taking a shared pointer to an inertial sensor

double RotateControllerInput::controllerGet(void) { // function PID controller calles to read from the inertial sensor
  return inputImu->get_rotation();
}

// Gyro Rotate Controller Class
GyroRotateController::GyroRotateController(std::shared_ptr<RotateControllerInput> input,
                                           std::shared_ptr<RotateControllerOutput> output)
    : controllerInput(input), controllerOutput(output),
      rotateController(IterativeControllerFactory::posPID(kP, kI, kD)),
      rotateSettledUtility(TimeUtilFactory::createDefault().getTimer(), 3, 5, 50_ms), rotateSettledUtilityAccurate(TimeUtilFactory::createDefault().getTimer(), 3, 5, 250_ms) {}

void GyroRotateController::setGains(const okapi::IterativePosPIDController::Gains &igains) {
    rotateController.setGains({igains.kP, igains.kI, igains.kD});
}

void GyroRotateController::resetGains(void) {
    rotateController.setGains({kP, kI, kD});
  }

// function to set zero position
void GyroRotateController::tareHeading(void) { zeroPosition = controllerInput->controllerGet(); }

// function to set heading offset
void GyroRotateController::setHeadingOffset(double offset) { zeroPosition = -offset; }

// function to return heading with offset
double GyroRotateController::getHeading() { return controllerInput->controllerGet() - zeroPosition; }

// rotate to an absolute target
void GyroRotateController::rotateAbsolute(double idegTarget, bool accurate) {
  rotateController.setTarget(idegTarget); // set the target to rotate to
  rotateSettledUtility.reset();           // reset the settled utility
  rotateSettledUtilityAccurate.reset();           // reset the settled utility
  while (true) {                          // loop infinitely

    controllerOutput->controllerSet(rotateController.step(getHeading())); // set output to the value
                                                                          // calculated by the PID controller
    rotateController.setIntegratorReset(true); // reset the integral value when target is passed

    // temporary debugging
    /*pros::lcd::set_text(0, "Gyro Rotate Debugging");
    pros::lcd::print(2, "Yaw: %1.2f degrees\n", getHeading());                     // print yaw value to LCD
    pros::lcd::print(3, "Target: %1.0f\n", idegTarget);                            // print target value to LCD
    pros::lcd::print(4, "Error: %1.2f degrees\n", abs(getHeading() - idegTarget)); // print error value to LCD

    printf("Yaw: %1.2f degrees Power: %1.2f\n", getHeading(), rotateController.step(getHeading()));*/

    if (rotateSettledUtility.isSettled(rotateController.getError())  && !accurate) { // if the controller is settled
      // printf("Settled\n");
      controllerOutput->controllerSet(0); // set controller output to zero
      break;                              // break out of loop
    } else if (rotateSettledUtilityAccurate.isSettled(rotateController.getError())  && accurate) { // if the controller is settled
          // printf("Settled\n");
          controllerOutput->controllerSet(0); // set controller output to zero
          break;                              // break out of loop
        }

    pros::delay(20); // delay 20 milliseconds to not overload cpu
  }
}

// rotates to a target realative to the robots current position
void GyroRotateController::rotateRelative(double idegTarget) {
  const long int currentValue = getHeading();   // get current heading
  const int target = currentValue + idegTarget; // set target to current value + destination
  rotateAbsolute(target);                       // rotate to the calculated target
}
