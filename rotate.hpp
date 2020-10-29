#ifndef ROTATE_HPP
#define ROTATE_HPP

#include "main.h"

class RotateControllerOutput : public ControllerOutput<double> { // controller output class for controll over chassis
public:
  std::shared_ptr<ChassisModel> chassisModel; // shared pointer to a chassis model

  RotateControllerOutput(const std::shared_ptr<ChassisModel> chassisModel); // constructor taking a shared
                                                                            // pointer to a chassis model

  void controllerSet(double ivalue) override; // function PID controller calls to move the chassis
};

class RotateControllerInput : public ControllerInput<double> { // controller input for reading from the inertial sensor
public:
  std::shared_ptr<pros::Imu> inputImu; // shared pointer to an inertial sensor

  RotateControllerInput(const std::shared_ptr<pros::Imu> inertialSensor); // constructor taking a shared
                                                                          // pointer to an inertial sensor

  double controllerGet(void) override; // function PID controller calles to read from the inertial sensor
};

class GyroRotateController { // class to hande gyro rotate PID controller
private:
  // PID constants for gyro rotate
  double kP = 0.006;      // kP was .0065// kp was .00625
  double kI = 0.005;      // kI
  double kD = 0.1 / 1000; // kD was .00001 //kd was .00002

  double zeroPosition = 0; // offset from zero

  // controller input
  std::shared_ptr<RotateControllerInput> controllerInput; // shared pointer to a controller input

  // controller output
  std::shared_ptr<RotateControllerOutput> controllerOutput; // shared pointer to a controller output

  // gyro turning pid controller
  IterativePosPIDController rotateController;

  // utility to determine if the controller has settled
  SettledUtil rotateSettledUtility;
  SettledUtil rotateSettledUtilityAccurate;

public:
  // class constructor
  GyroRotateController(std::shared_ptr<RotateControllerInput> input, std::shared_ptr<RotateControllerOutput> output);

  void setGains(const okapi::IterativePosPIDController::Gains &igains);

  void resetGains(void);

  // function to set zero position
  void tareHeading(void);

  // function to set heading offset
  void setHeadingOffset(double offset);

  // function to return heading with offset
  double getHeading();

  // rotates to an absolute target
  void rotateAbsolute(double idegTarget, bool accurate = false);

  // rotates to a target realative to the robots current position
  void rotateRelative(double idegTarget);
};

#endif
