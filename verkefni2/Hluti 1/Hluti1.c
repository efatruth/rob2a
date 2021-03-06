
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/
const int BASETIME = 850;

void drive(int time,bool fb){
	int dir = (fb) ? (-1):(1);
	motor[rightMotor] = dir*50;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = dir*50;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(time);
}

void stop(int time){
	motor[rightMotor] = 0;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 0;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(time);
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	stop(30000);
	for (int i = 1; i<5;i++){
		drive(BASETIME*i,true);
		stop(3500);
		drive(BASETIME*i,false);
		stop(3500);
	}

}												        // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
