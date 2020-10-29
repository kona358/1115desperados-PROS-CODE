#include "main.h"
#include "subsystems.hpp"
#include "okapi/api.hpp"
#include "display.hpp"
#include "rotate.hpp"
using namespace okapi;
int lowtower = 2200;
int hightower = 2700;
//fucky stuff
int rand50()
{
    // rand() function will generate odd or even
    // number with equal probability. If rand()
    // generates odd number, the function will
    // return 1 else it will return 0.
    return rand() & 1;
}
//calculates constantly with a 25% chance fail rate and a 75% succsess rate
bool rand75(){
	return rand50() | rand50();
}
//end fucky stuff
// by deleting "&& rand75()", rumble() or setText()
void opcontrol(){

	while(true){
		display();
			drive->getModel()->tank(masterController.getAnalog(ControllerAnalog::leftY), masterController.getAnalog(ControllerAnalog::rightY));
   	drive->setMaxVelocity(200);
		drive->getModel()->setBrakeMode(AbstractMotor::brakeMode::brake);
if(masterController.getDigital(ControllerDigital::left))
{// if left is pressed, stop all wheels from moving
  drive->getModel()->setBrakeMode(AbstractMotor::brakeMode::hold);

}

		//adjuster
if(masterController.getDigital(ControllerDigital::X))
{//traySpeed(); is defined in subs.cpp
	adjuster.moveVelocity(traySpeed());

}
else if(masterController.getDigital(ControllerDigital::B))
{
	adjuster.moveVelocity(-500);

}//if lift is going up, set tray to target where arms move freely
else if(masterController.getDigital(ControllerDigital::L1)){
  adjuster.moveAbsolute(2000, 200);

}
//if intaking, set tray target
else if(masterController.getDigital(ControllerDigital::R1)){
  adjuster.moveAbsolute(0, 200);

}
else{
	adjuster.moveVelocity(0);
}

//lift
	 if(masterController.getDigital(ControllerDigital::L1)){ //l1 is lift up
  lift.moveVelocity(200);

}else if (masterController.getDigital(ControllerDigital:: L2)){ // l2 is lift down
	 lift.moveVelocity(-200);

}// if intaking, set lift target
 else if(masterController.getDigital(ControllerDigital::R1)){
   liftController->setTarget(430);
 }
 else{
	 lift.moveVelocity(0);
	 lift.setBrakeMode(AbstractMotor::brakeMode::hold);
	}

	//intake
	if(masterController.getDigital(ControllerDigital::R1)){//r1 button intakes
	intake.moveVelocity(200);

}else if (masterController.getDigital(ControllerDigital::R2)){// r2 button extakes
	intake.moveVelocity(-150);
}

else{//brake function to hold the intake in place
	intake.moveVelocity(0);
	intake.setBrakeMode(AbstractMotor::brakeMode::brake);
}


//tray position for towers




//SetCattemp() displays .getTemperature() value on screen(sometimes?)
setCatTemp(lift.getTemperature());
setDriveTemp(leftDrive.getTemperature()+rightDrive.getTemperature()/4);
setIntakeTemp(intake.getTemperature()/2);
setAngleTemp(adjuster.getTemperature());





}//end while
}//end void
