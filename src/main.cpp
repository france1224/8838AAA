#include "main.h"
#include "robot.h"
#include "pid.h"
#include "auton.h"
#include "odometry.h"
#include "api.h"

using namespace pros;
using namespace std;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	OpticalC.set_led_pwm(100);
}

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

int color = 0;
int atn = 0; //decides everything!!
int pressed = 0;
string autstr; //to print
bool forward;
bool backward;


void competition_initialize() {

	while(true){

		if(selec.get_value() == true){
			pressed++;
		}

		if(selec.get_value() == false){
			pressed = 0;
		}

		if(pressed == 1){
			atn++;
		}

		if (atn == 0){
			autstr = "Skills";
			con.print(0,0, "Aut 0: %s       ", autstr);

		} else if (atn == 1){
			autstr = "NONE";
			con.print(0,0, "Aut 1: %s       ", autstr);

	} else if (atn == 2){
			autstr = "REDL";
			con.print(0,0, "Aut 2: %s       ", autstr);
} else if (atn == 3){
			autstr = "REDR";
			con.print(0,0, "Aut 3: %s       ", autstr);
} else if (atn == 4){
			autstr = "BLUEL";
			con.print(0,0, "Aut 4: %s       ", autstr);
		} else if (atn == 5){
			autstr = "BLUER";
			con.print(0,0, "Aut 5: %s       ", autstr);

		}else if (atn == 6){
			atn = 0;
		}

		con.clear();
	}
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	double ladybrown_angle = 0;
	int time = 0;
	double prev_imu = 0;
	double curr_imu = 0;
	int backward = 0;
	int forward;
	bool mogo_toggle;
	bool doinker_toggle;
	bool ladybrown_toggle = false;
	int macro = 0;
	double LBPos = 0;



    while(true) {

		color=0;

	// delay(5000);
	// driveStraightC(960);
	// driveArcLF(30, 14, 500);
	// driveStraight2(400);
	// delay(10);
	// doinker.set_value(true);
	// delay(9);
	// driveStraight2(-800);
	// doinker.set_value(false);
	// driveTurn2(150);
	// driveStraight2(-500);
	// mogo.set_value(true);
	// CONVEYOR.move(127);
	// delay(100);
	// driveTurn2(180);
	// driveStraight2(660);
	// driveTurn2(270);
	// driveStraight2(1400);
	// driveTurn2(180);
	// driveStraight2(-500);
	// mogo.set_value(true);
	// driveTurn2(90);
	// driveStraight2(600);


		//if(selec.get_value() == true){
		// 	pressed++;
		// }

		// switch(atn){
		// 	case 0:
		// 	autstr = "Skills";
		// 	break;


		// 	case 1:
		// 	autstr = "NONE";
		// 	break;


		// 	case 2:
		// 	autstr = "REDL";
		// 	break;


		// 	case 3:
		// 	autstr = "REDR";
		// 	break;

		// 	case 4:
		// 	autstr = "BLUEL";
		// 	break;

		// 	case 5:
		// 	autstr = "BLUER";
		// 	break;

		// 	case 6:
		// 	atn = 0;
		// 	break;

		// }


		if(selec.get_value() == false){
			pressed = 0;
		}

		if(pressed == 1){
			atn++;
		}

		if (atn == 0){
			autstr = "NONE";

		} else if (atn == 1){
			autstr = "Skills";

		} else if (atn == 2){
			autstr = "REDL";

		} else if (atn == 3){
			autstr = "REDR";

		} else if (atn == 4){
			autstr = "BLUEL";

		} else if (atn == 5){
			autstr = "BLUER";

		}else if (atn == 6){
			atn = 0;
		}

	
		prev_imu = curr_imu;
		curr_imu = imu.get_rotation();
		if(time %50 == 0 && time %100 != 0 && time % 150 != 0){
			con.print(0, 0, "Auton: %s      ", autstr);
		} else if (time % 50 == 0 && time % 100 != 0){
			con.print(1, 0, "Imu: %f       ", float(imu.get_heading()));
		} else if (time % 50 == 0){
			con.print(2,0, "time: %f     ", int(time2));
		}
		int power = con.get_analog(ANALOG_LEFT_Y);
		int RX = con.get_analog(ANALOG_RIGHT_X);

		//curve - if joystick moves a little, then the robot moves a little. (vice versa for big :D)
		//int turn = int(abs(RX) * RX / 75);
		int turn = int(pow(RX,3)/15000);
		//int turn = int(RX);

		int left = power+turn;
		int right = power-turn;

		LF.move(left);
		LM.move(left);
		LB.move(left);
		RF.move(right);
		RM.move(right);
		RB.move(right);
		
		//tank

		// LF.move(con.get_analog(ANALOG_LEFT_Y));
		// LM.move(con.get_analog(ANALOG_LEFT_Y));
		// LB.move(con.get_analog(ANALOG_LEFT_Y));
		// RF.move(con.get_analog(ANALOG_LEFT_Y));
		// RM.move(con.get_analog(ANALOG_LEFT_Y));
		// RB.move(con.get_analog(ANALOG_LEFT_Y));

		// if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
		// 	//driveStraight2(2000);
		// 	//driveTurn(165);
		// 	//driveStraightC(1000);
		// 	//driveArcL(90, 650, 30000);
		// 	mogo_toggle = !mogo_toggle;
		// 	mogo.set_value(mogo_toggle);
		// 	delay(100);

		// 	driveStraight2(-700);
		// 	delay(120);
		// 	driveTurn2(-25);
		// 	delay(150);
		// 	driveSlow(-500, 70);
		// 	delay(600);
		// 	mogo_toggle = !mogo_toggle;
		// 	mogo.set_value(mogo_toggle);
		// 	delay(1000);
		// 	driveStraight2(1000);
		// 	CONVEYOR.move(127);
		// 	delay(1000);
		// 	CONVEYOR.brake();
			

			
			//while (true){
			//	odometry();
			//	delay(1);
			//}

			if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)){
				ladybrown_toggle = true;
				// macro++;
				//ladybrown_toggle = false;
				LADYBROWN.move_relative(240, 127);
			}

		if(con.get_digital(E_CONTROLLER_DIGITAL_R1)){
			LADYBROWN.move(127);
			ladybrown_toggle = false;
			ladybrown_angle = LadyBrown1.get_position();
		} 
		else if(con.get_digital(E_CONTROLLER_DIGITAL_R2)){
			LADYBROWN.move(-127);
			ladybrown_toggle = false;
			ladybrown_angle = LadyBrown1.get_position();
		}else if(ladybrown_toggle){
			LBPos = roto.get_angle();

			if(LBPos > 30000){
				LBPos -= 36000; //wont go all the way around
			}

			// if(macro == 0){
			// 	setConstants(LADYBROWN_KP, LADYBROWN_KI, LADYBROWN_KD); //set the target!! for all
			// 	LADYBROWN.move(calcPID(910, roto.get_position(), 0, 0)); //resting position
			// }	else if (macro == 1){
			// 	setConstants(LADYBROWN_KP2, LADYBROWN_KI2, LADYBROWN_KD2);
			// 	LADYBROWN.move(calcPID(11680, roto.get_position(), 0, 0)); //picking up position
			// }	else if(macro == 2){
			// 	setConstants(LADYBROWN_KP2,LADYBROWN_KI2, LADYBROWN_KD2);
			// 	LADYBROWN.move(calcPID(34470, roto.get_position(), 0, 0)); //scoring position
			// }	else{
			// 	macro = 0; //turns macro off for manual control
			// }
			} else {
				setConstants(LADYBROWNHOLD_KP, LADYBROWNHOLD_KI, LADYBROWNHOLD_KD);
				LADYBROWN.move(calcPID(ladybrown_angle, LadyBrown1.get_position(), 0, 0)); //holds so it doesnt go down
			 }


			

		if(con.get_digital(E_CONTROLLER_DIGITAL_L1)){
			CONVEYOR.move(127);
			forward = 1;
		} else {
			forward = 2;
		}


		if(con.get_digital(E_CONTROLLER_DIGITAL_L2)){
			CONVEYOR.move(-127);
			backward = 1;
		  }else{
			backward = 2;
		  }

		if(forward + backward == 4){
			CONVEYOR.move(0);
		}

		if (con.get_digital(E_CONTROLLER_DIGITAL_X)){
			//driveTurn2(45);
			//driveStraight2(1500);
			driveStraightC(840);
			driveArcLF(30, 14, 500);
			driveStraight2(400);
			delay(10);
			doinker.set_value(true);
			delay(500);
			driveStraight2(-800);

		}


		if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
			mogo.set_value(mogo_toggle);
			mogo_toggle = !mogo_toggle;
		}
		
		if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
			doinker.set_value(doinker_toggle);
			doinker_toggle = !doinker_toggle;
		}
	}

	time++;
	pros::delay(1);	
	}