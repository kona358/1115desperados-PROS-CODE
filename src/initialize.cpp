#include "main.h"
#include "okapi/api.hpp"
#include "subsystems.hpp"
#include "display.hpp"
#include "pros/misc.h"
using namespace okapi;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize(){ /*{
	pros::lcd::initialize();
	pros::lcd::set_text(1, "how's that 75 now?");
	masterController.setText(0,0,"  75 ");
	pros::delay(20);
}*/
lift.setGearing(AbstractMotor::gearset::red);
intake.setGearing(AbstractMotor::gearset::green);
adjuster.setReversed(true);
pros::delay(20);
//displayInit(); initializes the display, ask austin/ learn from display.hpp and display.cpp

displayInit();
	pros::delay(20);
		masterController.rumble(" ... . ...- . -. - -.-- ..-. .. ...- ."); //75
		pros::delay(20);
//resets imu, waits for (time) until imu is finished reseting
imu->reset();
	const uint32_t calibrationStartTime = pros::millis();
	bool successfullyCalibrated = true;
	while(imu->is_calibrating()) {
		if (pros::millis()- calibrationStartTime > 6000) {
			successfullyCalibrated = false;
			break;
		}
	}
pros::delay(20);

	}


	//pros::lcd::register_btn1_cb(on_center_button);


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

}
