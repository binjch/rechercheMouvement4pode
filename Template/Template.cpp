#include <Arduino.h>
#include "VarSpeedServo.h"
#include <NeoSWSerial.h>

VarSpeedServo myservo4;
VarSpeedServo myservo5;
VarSpeedServo myservo6;
VarSpeedServo myservo7;
VarSpeedServo myservo8;
VarSpeedServo myservo9;
VarSpeedServo myservo10;
VarSpeedServo myservo11;

void setup() {

	//Serial.begin(115200);

	myservo4.attach(4);
	myservo5.attach(5);

	myservo6.attach(6);
	myservo7.attach(7);

	myservo8.attach(8);
	myservo9.attach(9);

	myservo10.attach(10);
	myservo11.attach(11);
}

void loop() {

	int maxiPos = 12;
	int miniPos = 0;

	/////////////////////////

	int maxiAh = 140;
	int miniAh = 40;

	int maxiAv = 140;
	int miniAv = 50;

	int posHT = miniAv + (maxiAv - miniAv)/2;

	int SPEED1 = 150;
	int SPEED2 = 150;

	/////////////////////////////////////////////////////////////////

	myservo6.write(maxiAh, SPEED1);
	myservo7.write(map(maxiAv,0,180,180,0), SPEED1);
	myservo6.wait();
	myservo7.wait();

	myservo4.write(map(maxiAh,0,180,180,0), SPEED1);
	myservo5.write(maxiAv, SPEED1);
	myservo4.wait();
	myservo5.wait();


	myservo10.write(map(maxiAh,0,180,180,0), SPEED1);
	myservo11.write(miniAv, SPEED1);
	myservo10.wait();
	myservo11.wait();

	myservo8.write(maxiAh, SPEED1);
	myservo9.write(map(miniAv,0,180,180,0),SPEED1);
	myservo8.wait();
	myservo9.wait();


	/////////////////////////////////////////////////////////////////

	myservo6.write(maxiAh, SPEED1);
	myservo7.write(map(maxiAv,0,180,180,0), SPEED1);
	myservo6.wait();
	myservo7.wait();

	myservo4.write(map(maxiAh,0,180,180,0), SPEED1);
	myservo5.write(maxiAv, SPEED1);
	myservo4.wait();
	myservo5.wait();

	myservo10.write(map(maxiAh,0,180,180,0), SPEED1);
	myservo11.write(posHT, SPEED1);
	myservo10.wait();
	myservo11.wait();

	myservo8.write(maxiAh, SPEED1);
	myservo9.write(posHT, SPEED1);
	myservo8.wait();
	myservo9.wait();

	/////////////////////////////////////////////////////////////////

	myservo6.write(miniAh, SPEED1);
	myservo7.write(map(miniAv,0,180,180,0), SPEED1);
	myservo6.wait();
	myservo7.wait();

	myservo4.write(map(miniAh,0,180,180,0), SPEED1);
	myservo5.write(miniAv, SPEED1);
	myservo4.wait();
	myservo5.wait();

	myservo10.write(map(miniAh,0,180,180,0), SPEED1);
	myservo11.write(posHT, SPEED1);
	myservo10.wait();
	myservo11.wait();

	myservo8.write(miniAh, SPEED1);
	myservo9.write(posHT, SPEED1);
	myservo8.wait();
	myservo9.wait();

	/////////////////////////////////////////////////////////////////

	myservo6.write(miniAh, SPEED1);
	myservo7.write(map(miniAv,0,180,180,0), SPEED1);
	myservo6.wait();
	myservo7.wait();

	myservo4.write(map(miniAh,0,180,180,0), SPEED1);
	myservo5.write(miniAv, SPEED1);
	myservo4.wait();
	myservo5.wait();

	myservo10.write(map(miniAh,0,180,180,0), SPEED1);
	myservo11.write(miniAv, SPEED1);
	myservo10.wait();
	myservo11.wait();

	myservo8.write(miniAh, SPEED1);
	myservo9.write(map(miniAv,0,180,180,0),SPEED1);
	myservo8.wait();
	myservo9.wait();



	//////////////////////////////////////////////////////////////////


	myservo7.write(posHT, SPEED1);

	myservo7.wait();


	myservo5.write(posHT, SPEED1);

	myservo5.wait();

	myservo11.write(miniAv, SPEED1);

	myservo11.wait();

	myservo9.write(map(miniAv,0,180,180,0), SPEED1);

	myservo9.wait();

	//////////////////////////////////////////////////////////////////

	delay(500);

}

/*
 attach(pin )  - Attaches a servo motor to an i/o pin.
 attach(pin, min, max  ) - Attaches to a pin setting min and max values in microseconds
 default min is 544, max is 2400

 write(value)     - Sets the servo angle in degrees.  (invalid angle that is valid as pulse in microseconds is treated as microseconds)
 write(value, speed) - speed varies the speed of the move to new position 0=full speed, 1-255 slower to faster
 write(value, speed, wait) - wait is a boolean that, if true, causes the function call to block until move is complete

 writeMicroseconds() - Sets the servo pulse width in microseconds
 read()      - Gets the last written servo pulse width as an angle between 0 and 180.
 readMicroseconds()  - Gets the last written servo pulse width in microseconds. (was read_us() in first release)
 attached()  - Returns true if there is a servo attached.
 detach()    - Stops an attached servos from pulsing its i/o pin.

 slowmove(value, speed) - The same as write(value, speed), retained for compatibility with Korman's version

 stop() - stops the servo at the current position

 sequencePlay(sequence, sequencePositions); // play a looping sequence starting at position 0
 sequencePlay(sequence, sequencePositions, loop, startPosition); // play sequence with number of positions, loop if true, start at position
 sequenceStop(); // stop sequence at current position
 wait(); // wait for movement to finish
 isMoving()  // return true if servo is still moving
 */
