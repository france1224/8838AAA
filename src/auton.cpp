#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
#include "odometry.h"

using namespace std;
using namespace pros;

void autonomous() {

	//example of lb macro thingy
	lbmove==1; //picks position

			driveStraight2(-700);
			delay(500);
			driveTurn2(-21);
			delay(500);
			driveStraight2(-400, 25);
			delay(700);
			mogo.set_value(true);
			delay(500);
			// driveStraight2(300);
			// delay(500);
			// driveStraight2(-300);
			// delay(500);
			CONVEYOR.move(127);
			delay(1000);
			CONVEYOR.brake();
			delay(500);
			driveTurn2(-112);
			delay(500);
		    CONVEYOR.move(110);
			delay(100);
			driveStraight(600);
			delay(500);
			CONVEYOR.move(110); 
			delay(2000);
			CONVEYOR.brake();
			delay(500);
			// driveTurn2(-180);
			// delay(700);
			// driveStraight2(5000);



			// driveTurn2(30);
			// driveStraight2(-1160, 25);
			// delay(500);
			// //driveStraight2(-200, 25);
			// delay(500);
			// mogo.set_value(true);
			// delay(500);
			// driveStraight2(300);
			// delay(500);
			// driveStraight2(-300);
			// delay(500);
			// CONVEYOR.move(127);
			// delay(1000);
			// CONVEYOR.brake();
			// delay(500);
			// driveTurn2(110);
			// delay(500);
		    // CONVEYOR.move(110);
			// delay(100);
			// driveStraight(600);
			// delay(500);
			// CONVEYOR.move(110); 
			// delay(2000);
			// CONVEYOR.brake();
			// delay(500);
			// driveTurn2(-90);
			// driveStraight2(1000);

    // if(atn==0){

    // }else if(atn == 1){

    // }else if(atn == 2){//redl
    // 		mogo.set_value(false);
	// 		doinker.set_value(true);
	// 		delay(1000);
	// 		driveStraight2(-580);
	// 		delay(700);
	// 		driveTurn2(44);
	// 		delay(800);
	// 		driveSlow(-800, 80);
	// 		delay(700);
	// 		mogo.set_value(true);
	// 		delay(700);
	// 		CONVEYOR.move(127);   
	// 	 	delay(700);			
	// 		driveTurn2(-96);
	// 		delay(700);
	// 		driveStraight2(2000);

    // // }else if(atn == 3){//redr
    // 		mogo.set_value(true);
	// 		doinker.set_value(true);
	// 		delay(1000);
	// 		driveStraight2(-580);
	// 		delay(700);
	// 		driveTurn2(-44);
	// 		delay(800);
	// 		driveSlow(-800, 80);
	// 		delay(700);
	// 		mogo.set_value(false);
	// 		delay(700);
	// 		CONVEYOR.move(127);
	// 	 	delay(700);			
	// 		driveTurn2(96);
	// 		delay(700);
	// 		driveStraight2(2000);

    // }else if(atn == 4){//bluel
    		// mogo.set_value(false);
			// doinker.set_value(true);
			// delay(1000);
			// driveStraight2(-580);
			// delay(700);
			// driveTurn2(-44);
			// delay(800);
			// driveSlow(-780 , 80);
			// delay(700);
			// mogo.set_value(true);
			// delay(700);
			// CONVEYOR.move(127);
		 	// delay(700);			
			// driveTurn2(-96);
			// delay(700);
			// driveStraight2(2000);

    // }else if(atn == 5){
			// mogo.set_value(false);
			// doinker.set_value(true);
			// delay(1000);
			// driveStraight2(-580);
			// delay(700);
			// driveTurn2(-44);
			// delay(800);
			// driveSlow(-800, 80);
			// delay(700);
			// mogo.set_value(true);
			// delay(700);
			// CONVEYOR.move(127);
		 	// delay(700);			
			// driveTurn2(96);
			// delay(700);
			// driveStraight2(2000);
   // }


    // driveTurn2(90);

    // driveStraight(1000);

    // driveTurn(45);

    // driveStraight2(6000  );


    // driveStraight2(2000);
    // driveTurn2(-90);
    // driveStraight2(1500);
    // driveTurn2(90);
    // driveStraight2(1500);
    // driveTurn2(180);
    // driveStraight2(1900);
}