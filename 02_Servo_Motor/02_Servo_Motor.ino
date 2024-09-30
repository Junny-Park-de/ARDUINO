#include <Servo.h>
#include <LiquidCrystal.h>

Servo myServo;
Servo myServo2;


const int servoPin = 2; 
const int servoPin2 = 11;
const int photoLeftPin = A2;  // Left photoresistor
const int photoCenterPin = A1;  // Center photoresistor
const int photoRightPin = A0;  // Right photoresistor
const int leds = 8;
const int rs = 9, en = 10, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  myServo.attach(servoPin);  // Attach the servo motor
  myServo2.attach(servoPin2);
  myServo.write(90);  // Start the servo at the center position
  myServo2.write(90);
  Serial.begin(9600);  // Begin serial communication for debugging
  pinMode(leds, OUTPUT);
  mylcd.begin(16, 2);
	mylcd.setCursor(5, 0);
	mylcd.print("START");
}

void loop()
{
  // Read the light values from the three photoresistors
  int lightLeft = analogRead(photoLeftPin);
  int lightCenter = analogRead(photoCenterPin);
  int lightRight = analogRead(photoRightPin);
  
  digitalWrite(leds, HIGH);
  delay(200);
  digitalWrite(leds, LOW);
  delay(200);
  // Print light readings for debugging
  Serial.print("Left: ");
  Serial.print(lightLeft);
  Serial.print(" | Center: ");
  Serial.print(lightCenter);
  Serial.print(" | Right: ");
  Serial.println(lightRight);

  // mylcd.clear();
 	// mylcd.setCursor(2, 0);
	// mylcd.print("Turning left");
  // mylcd.setCursor(3, 1);
	// mylcd.print("Turning up")
 	// mylcd.print(lightLeft);
	
  // mylcd.clear();
  // mylcd.setCursor(1, 0);
	// mylcd.print("Turning right");
	// mylcd.setCursor(2, 1);
	// mylcd.print("Turning down");

 	// mylcd.print(lightRight);
	// mylcd.setCursor(6, 1);
	// mylcd.print("C : ");
 	// mylcd.print(lightCenter);

  // Get the current servo position
  int currentPos = myServo.read();
  int currentPos2 = myServo2.read();

  // Determine which side has the most light and move the servo accordingly
  if (lightLeft > lightCenter && lightLeft > lightRight) 
  {
    // Move left if the left photoresistor detects more light
    if (currentPos > 0 && currentPos2 > 0)
    {  // Make sure the servo doesn't go below 0°
      myServo.write(currentPos - 10);  // Slowly move left
      myServo2.write(currentPos2 - 10);
    }
    mylcd.clear();
 	  mylcd.setCursor(2, 0);
    mylcd.print("Turning left");
    mylcd.setCursor(3, 1);
	  mylcd.print("Turning up");
  } 
  else if (lightRight > lightCenter && lightRight > lightLeft) 
  {
    // Move right if the right photoresistor detects more light
    if (currentPos < 180 && currentPos2 < 180) 
    {  // Make sure the servo doesn't go above 180°
      myServo.write(currentPos + 10);  // Slowly move right
      myServo2.write(currentPos2 + 10);
    }
    mylcd.clear();
    mylcd.setCursor(1, 0);
	  mylcd.print("Turning right");
	  mylcd.setCursor(2, 1);
	  mylcd.print("Turning down");
  } 
  else 
  {
    // Center the servo if the center photoresistor detects the most light
    if (currentPos > 90 && currentPos2 > 90) 
    {
      myServo.write(currentPos - 10);  // Move toward the center
      myServo2.write(currentPos2 - 10);
    } 
    else if (currentPos < 90 && currentPos2 < 90) 
    {
      myServo.write(currentPos + 10);  // Move toward the center
      myServo2.write(currentPos2 + 10);
    }
    mylcd.clear();
 	  mylcd.setCursor(4, 0);
    mylcd.print("Centering");
  }
  delay(10);
}