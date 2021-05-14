#include <Arduino.h>

#define enA 9
#define in1 6
#define in2 7
#define button 4

void setup() {
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	// Set initial rotation direction
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	analogWrite(enA, 5);
	Serial.begin(115200);
}

void loop() {
	if (Serial.available() > 0) {
		char pwm = Serial.read();
		Serial.println(pwm);
		pwm -= '0';
		pwm = map(pwm, 0, 9, 0, 255);
		analogWrite(enA, pwm);
	}
}