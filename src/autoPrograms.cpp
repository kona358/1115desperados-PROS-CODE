#include "autoPrograms.hpp"
#include "okapi/api.hpp"
#include "rotate.hpp"
#include "subsystems.hpp"
using namespace okapi;



 void onepoint(void){
   drive->moveDistance(-30_cm);
   drive->moveDistance(35_cm);
   drive->waitUntilSettled();
   flip();



 }
void blue2(void){//6 unprotected
  gyroRotate.tareHeading();

  intakeController->setMaxVelocity(200);
  liftController->setMaxVelocity(200);
  drive->setMaxVelocity(70);
  liftController->setTarget(420);
  drive->moveDistanceAsync(100_cm);
  intakeController->setTarget(14500);
  drive->setMaxVelocity(140);
  drive->waitUntilSettled();
  gyroRotate.rotateRelative(25);
  drive->setMaxVelocity(80);
drive->moveDistanceAsync(25_cm);
intakeController->setTarget(15200);
drive->waitUntilSettled();
drive->moveDistance(-25_cm);
drive->setMaxVelocity(130);
  gyroRotate.rotateRelative(-174);
  drive->moveDistance(81_cm);
  intakeController->setTarget(15100);
  intakeController->waitUntilSettled();
  liftController->setTarget(150);
  stack();
  drive->setMaxVelocity(60);
  drive->moveDistanceAsync(-50_cm);//6 stacked
  intakeController->setTarget(13000);
  liftController->setTarget(0);

}

void blue1(void){//tileside
  gyroRotate.tareHeading();
   drive->setMaxVelocity(90);
   intakeController->setMaxVelocity(200);
   liftController->setMaxVelocity(200);
   // flip();
 liftController->setTarget(420);
   drive->moveDistanceAsync(48_cm);
   intake.moveVelocity(200);
   drive->waitUntilSettled();
   drive->setMaxVelocity(120);
   pros::delay(600);
 gyroRotate.rotateRelative(-89);
 drive->setMaxVelocity(90);
 drive->moveDistance(55_cm);
 intake.moveVelocity(-20);
 drive->moveDistance(-53_cm);
 intake.moveVelocity(0);
 drive->setMaxVelocity(100);
 gyroRotate.rotateRelative(-120);
 drive->setMaxVelocity(90);
 drive->moveDistance(28_cm);
 liftController->waitUntilSettled();
 stack();
 pros::delay(200);
 drive->moveDistanceAsync(-30_cm); //use above for match autonomous
 intakeController->setTarget(0);
}

void red1(void){ // tileside

  gyroRotate.tareHeading();
   drive->setMaxVelocity(90);
   intakeController->setMaxVelocity(200);
   liftController->setMaxVelocity(200);
   // flip();
  liftController->setTarget(450);
   drive->moveDistanceAsync(48_cm);
   intake.moveVelocity(200);
   drive->waitUntilSettled();
   drive->setMaxVelocity(120);
   pros::delay(600);
  gyroRotate.rotateRelative(89);
  drive->setMaxVelocity(90);
  drive->moveDistance(55_cm);
  intake.moveVelocity(-20);
  drive->moveDistance(-53_cm);
  intake.moveVelocity(0);
  drive->setMaxVelocity(100);
  gyroRotate.rotateRelative(120);
  drive->setMaxVelocity(90);
  drive->moveDistance(28_cm);
  liftController->waitUntilSettled();
  stack();
  pros::delay(200);
  drive->moveDistanceAsync(-30_cm); //use above for match autonomous
  intakeController->setTarget(0);
}

void red2(void){
// 6 point unprotected
gyroRotate.tareHeading();

intakeController->setMaxVelocity(200);
liftController->setMaxVelocity(200);
drive->setMaxVelocity(70);
liftController->setTarget(450);
drive->moveDistanceAsync(100_cm);
intakeController->setTarget(14500);
drive->setMaxVelocity(140);
drive->waitUntilSettled();
gyroRotate.rotateRelative(-25);
drive->setMaxVelocity(80);
drive->moveDistanceAsync(25_cm);
intakeController->setTarget(15200);
drive->waitUntilSettled();
drive->moveDistance(-25_cm);
drive->setMaxVelocity(130);
gyroRotate.rotateRelative(174);
drive->moveDistance(81_cm);
intakeController->setTarget(15100);
intakeController->waitUntilSettled();
liftController->setTarget(150);
stack();
drive->setMaxVelocity(60);
drive->moveDistanceAsync(-50_cm);//8 stacked
intakeController->setTarget(13000);
liftController->setTarget(0);
}

void skills(void){ //blue unprotected
/*  gyroRotate.tareHeading();

  intakeController->setMaxVelocity(200);
  liftController->setMaxVelocity(200);
  drive->setMaxVelocity(70);
  liftController->setTarget(425);
  drive->moveDistanceAsync(100_cm);
  intakeController->setTarget(14500);
  drive->setMaxVelocity(140);
  drive->waitUntilSettled();
  gyroRotate.rotateRelative(25);
  drive->setMaxVelocity(80);
  intakeController->setTarget(14000);
  drive->moveDistanceAsync(26_cm);
  intakeController->setTarget(15100);
  drive->waitUntilSettled();
  drive->moveDistance(-26_cm);
  drive->setMaxVelocity(130);
  gyroRotate.rotateRelative(-173);
  drive->moveDistance(81_cm);
  intakeController->setTarget(14500);
  intakeController->waitUntilSettled();
  liftController->setTarget(150);
  liftController->waitUntilSettled();*/
  gyroRotate.tareHeading();

  intakeController->setMaxVelocity(200);
  liftController->setMaxVelocity(200);
  drive->setMaxVelocity(70);
  liftController->setTarget(420);
  drive->moveDistanceAsync(100_cm);
  intakeController->setTarget(14500);
  drive->setMaxVelocity(140);
  drive->waitUntilSettled();
  gyroRotate.rotateRelative(25);
  drive->setMaxVelocity(80);
drive->moveDistanceAsync(25_cm);
intakeController->setTarget(15200);
drive->waitUntilSettled();
drive->moveDistance(-25_cm);

drive->setMaxVelocity(60);
  gyroRotate.rotateRelative(-172);
  drive->moveDistance(81_cm);
  intakeController->setTarget(14800);
  liftController->setTarget(150);
  liftController->waitUntilSettled();
  stack();
pros::delay(1000);
drive->moveDistance(2_cm);
drive->setMaxVelocity(60);
drive->moveDistanceAsync(-23_cm);//8 stacked
intakeController->setTarget(14200);
liftController->setTarget(425);
adjusterController->setTarget(0);
drive->waitUntilSettled();
drive->setMaxVelocity(200);
gyroRotate.rotateRelative(-116);
drive->getModel()->tank(-.5, -.5);
pros::delay(1000);
drive->getModel()->tank(0,0);
drive->setMaxVelocity(70);
drive->moveDistanceAsync(126_cm);
intake.moveVelocity(200);
pros::delay(200);
drive->waitUntilSettled();
drive->getModel()->resetSensors();
intake.moveVelocity(-150);
pros::delay(400);
intake.moveVelocity(0);
drive->moveDistance(-5.5_cm);
adjuster.moveVelocity(200);
pros::delay(380);
adjuster.moveVelocity(0);
pros::delay(10);
liftController->setTarget(3000);
liftController->waitUntilSettled();
intakeController->setTarget(16000); // during a full run
intakeController->waitUntilSettled();
// back up against the wall and align
/*gyroRotate.rotateRelative(-90);
liftController->setTarget(420);
drive->getModel()->tank(-.5, -.5);
pros::delay(960);
drive->getModel()->tank(0, 0);
drive->moveDistanceAsync(76_cm);
intakeController->setTarget(18000);
drive->waitUntilSettled();
gyroRotate.rotateRelative(-90);
*/}
//this is RED 2
//drive->setMaxVelocity(70);
//liftController->setMaxVelocity(200);
//intakeController->setMaxVelocity(200);
//flip();
//drive->waitUntilSettled();
//liftController->setTarget(85);
///drive->moveDistanceAsync(113_cm);
//intakeController->setTarget(4600);
//drive->waitUntilSettled();
//gyroRotate.rotateRelative(145);
//drive->waitUntilSettled();
//drive->setMaxVelocity(110);
//drive->moveDistance(92_cm);
//intakeController->setTarget(4200);
//drive->waitUntilSettled();
//drive->setMaxVelocity(70);
//intakeController->waitUntilSettled();
//liftController->setTarget(0);
//stack();
//drive->moveDistance(1_cm);
//drive->moveDistanceAsync(-30_cm);// use above for match autonomous
//intakeController->setTarget(4200);
//intakeController->setTarget(0);


//this is 1 point and flip out
/*drive->moveDistance(-30_cm);
drive->moveDistance(35_cm);
drive->waitUntilSettled();
flip();*/
