#include "Arduino.h"

#include <Servo.h>
#include <math.h>

Servo leftFrontLegServo;
Servo rightFrontLegServo;
Servo headServo;
Servo leftBackLegServo;
Servo rightBackLegServo;
int pos1, pos2, pos3, pos4, pos5;

int get_distance(int analogInput)
{
  float volts = 0;
  if (analogInput == 3)
  {
    volts = analogRead(A3) * 0.0048828125; // value from sensor * (5/1024)
  }
  else if (analogInput == 4)
  {
    volts = analogRead(A4) * 0.0048828125; // value from sensor * (5/1024)
  }
  else if (analogInput == 5)
  {
    volts = analogRead(A5) * 0.0048828125; // value from sensor * (5/1024)
  }
  else if (analogInput == 6)
  {
    volts = analogRead(A6) * 0.0048828125; // value from sensor * (5/1024)
  }
  else if (analogInput == 7)
  {
    volts = analogRead(A7) * 0.0048828125; // value from sensor * (5/1024)
  }

  int distance = 13 * pow(volts, -1); // worked out from datasheet graph
  return distance;
}

double counter;
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pos1 = 40;  // bein links vorne
  pos2 = 90;  // bein rechts vorne
  pos3 = 60;  // kopf
  pos4 = 40;  // bein links hinten
  pos5 = 140; // bein rechts hinten

  leftFrontLegServo.attach(11);
  rightFrontLegServo.attach(10);
  headServo.attach(9);
  leftBackLegServo.attach(6);
  rightBackLegServo.attach(5);

  counter = 0;
}

void loop()
{
  double angle1 = 20 * sin(counter);
  double angle2 = 20 * cos(counter);

  leftFrontLegServo.write(pos1 + angle1);
  rightFrontLegServo.write(pos2 + angle1);
  headServo.write(pos3 + angle1);
  leftBackLegServo.write(pos4 + angle2);
  rightBackLegServo.write(pos5 + angle2);

  counter = counter + 0.002;
}
