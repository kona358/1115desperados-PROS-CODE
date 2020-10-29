 #include "okapi/api.hpp"
#include "main.h"
#include "rotate.hpp"
#include "subsystems.hpp"
using namespace std;
const QLength wheelDiameter = 4_in;
const QLength chassisWidth = 356_mm;
const AbstractMotor::gearset chassisGearset = AbstractMotor::gearset::green;



shared_ptr<okapi::Logger> logger =
std::make_shared<Logger>(TimeUtilFactory::createDefault().getTimer(), "ser/sout", Logger::LogLevel::debug);
MotorGroup leftDrive({4,1}); //red zip ties
MotorGroup rightDrive({-2,-5}); // blue zip ties




  void flip() { //flip(); is a function to call during auton or a button press
  adjuster.moveVelocity(200);
  pros::delay(380);
  adjuster.moveVelocity(0);
  pros::delay(10);
  lift.moveVelocity(200);
  pros::delay(1100);
  lift.moveVelocity(-125);
  pros::delay(200);
  lift.moveVelocity(0);
  adjuster.moveVelocity(-200);
  pros::delay(800);
  adjuster.moveVelocity(0);

  }

shared_ptr<ChassisController> drive =
ChassisControllerBuilder().withMotors(leftDrive,rightDrive).withDimensions(chassisGearset, {{wheelDiameter, chassisWidth}, imev5GreenTPR}).withLogger(logger).build();
Controller masterController;
Motor adjuster(3); //green zip ties
Motor lift(11); // white zip ties
MotorGroup intake({-12,13}); //black zip ties

shared_ptr<AsyncPositionController<double, double>> liftController =
AsyncPosControllerBuilder().withMotor(lift).withMaxVelocity(200).withLogger(logger).build();

shared_ptr<AsyncPositionController<double, double>> intakeController =
AsyncPosControllerBuilder().withMotor(intake).withMaxVelocity(200).withLogger(logger).build();

shared_ptr<AsyncPositionController<double, double>> adjusterController =
AsyncPosControllerBuilder().withMotor(adjuster).withMaxVelocity(200).withLogger(logger).build();


//PID Controllers for gyro rotates
const double kP = 0.0065;
const double kI = .001;
const double kD = .00001;
IterativePosPIDController RotateController = IterativeControllerFactory::posPID( kP,  kI, kD);
okapi::SettledUtil rotateSettledUtil(TimeUtilFactory::createDefault().getTimer(), 1, 5, 250_ms);

std::shared_ptr<pros::Imu> imu = std::make_shared<pros::Imu>(6);

std::shared_ptr<RotateControllerInput> gyroInput = std::make_shared<RotateControllerInput>(imu);
std::shared_ptr<RotateControllerOutput> rotateOutput = std::make_shared<RotateControllerOutput>(drive->getModel());

GyroRotateController gyroRotate(gyroInput, rotateOutput);
//motion profiling for tray up
std::int16_t traySpeed(int target) {

float startingAcceleration = 0.8;
std::int16_t outputSpeed = 0;
int acceleration = 15;
std::int16_t endSpeed = sqrt(-acceleration*(adjuster.getPosition()-target));

float inverseEndSpeed = -((pow(200,2)-acceleration*target)/acceleration);
float startSpeed = startingAcceleration*adjuster.getPosition()+50;

outputSpeed = endSpeed;
if (outputSpeed > 150) {
  return 150;
}
else if (outputSpeed < -200) {
  return -200;
} else{
  return outputSpeed;
}

}

//auton tray speed
std::int16_t trayautoSpeed(int target) {

float startingAcceleration = 0.8;
std::int16_t outputSpeed = 0;
int acceleration = 6;
std::int16_t endSpeed = sqrt(-acceleration*(adjuster.getPosition()-target));

float inverseEndSpeed = -((pow(200,2)-acceleration*target)/acceleration);
float startSpeed = startingAcceleration*adjuster.getPosition()+50;

outputSpeed = endSpeed;
if (outputSpeed > 150) {
  return 150;
}
else if (outputSpeed < -200) {
  return -200;
} else{
  return outputSpeed;
}

}

void stack(int target) {
  adjuster.moveAbsolute(target, trayautoSpeed());
  pros::delay(500);
  while (adjuster.getActualVelocity() > 0) {
    adjuster.modifyProfiledVelocity(trayautoSpeed());
  }
}
