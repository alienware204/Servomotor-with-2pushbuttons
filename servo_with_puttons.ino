
#include <Servo.h>

Servo arm; // Create a "Servo" object called "arm"
float pos = 0.0; // Variable where the arm's position will be stored (in degrees)
float step = 1.0; // Variable used for the arm's position step

void setup()
{
  pinMode(A1, INPUT_PULLUP); // Set the A1 pin to a pushbutton in pullup mode
  pinMode(A2, INPUT_PULLUP); // Set the A1 pin to a pushbutton in pullup mode

  arm.attach(2); // Attache the arm to the pin 2
  arm.write(pos); // Initialize the arm's position to 0 (leftmost)
}

void loop()
{

  if (!digitalRead(A1)) // Check for the yellow button input
  {
    if (pos>0) // Check that the position won't go lower than 0°
    {
      arm.write(pos); // Set the arm's position to "pos" value
      pos-=step; // Decrement "pos" of "step" value
      delay(5); // Wait 5ms for the arm to reach the position
    }
  }

  if (!digitalRead(A2)) // Check for the blue button input
  {
    if (pos<180) // Check that the position won't go higher than 180°
    {
      arm.write(pos); // Set the arm's position to "pos" value
      pos+=step; // Increment "pos" of "step" value
      delay(5); // Wait 5ms for the arm to reach the position
    }
  }

}
