#include "api.h"
#include "main.h"

#ifndef PIDH
#define PIDH

extern void driveStraight(int target);
extern void driveTurn(int target);
extern void driveTurn2(int target);
extern void driveStraight2(int target);
extern void driveStraightC(int target);

extern void driveArcL(double theta, double radius, int timeout);
extern void driveArcR(double theta, double radius, int timeout);

extern void driveArcLF(double theta, double radius, int timeout);
extern void driveArcRF(double theta, double radius, int timeout);

extern double calcPID(double target, double input, int integralKi, int maxIntegral);
extern double calcPID2(double target, double input, int integralKi, int maxIntegral);

extern void setConstants(double kp, double ki, double kd);

extern void chasMove(int voltageLF, int voltageLB, int voltageLM, int voltageRF, int voltageRM, int voltageRB);

extern int time2;



#define STRAIGHT_KP 1.75
#define STRAIGHT_KI 0.01
#define STRAIGHT_KD 7

#define STRAIGHT_INTEGRAL_KI 40
#define STRAIGHT_MAX_INTEGRAL 14.5

#define TURN_KP 5
#define TURN_KI 0.01
#define TURN_KD 43

#define TURN_INTEGRAL_KI 30
#define TURN_MAX_INTEGRAL 25

#define ARC_CORRECTION_KP 30

#define HEADING_KP 4
#define HEADING_KI 0
#define HEADING_KD 0

#define HEADING_INTEGRAL_KI 0
#define HEADING_MAX_INTEGRAL 0

#define ARC_HEADING_KP 4
#define ARC_HEADING_KI 0
#define ARC_HEADING_KD 0

#define ARC_HEADING_INTEGRAL_KI 0
#define ARC_HEADING_MAX_INTEGRAL 0

#endif