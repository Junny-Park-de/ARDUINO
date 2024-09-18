#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);
const int potPin = A0;
const int ledPin = 6;

void setup(){
  mylcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  mylcd.setCursor(0,0);
  mylcd.print("Pot Value: ");
  mylcd.setCursor(0,1);
  mylcd.print("LED Bright: ");
}
void loop(){
  int potValue = analogRead(potPin);
  int ledValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, ledValue);

  mylcd.clear();
  mylcd.setCursor(0,0);
  mylcd.print("Pot Value: ");
  mylcd.print(potValue);

  mylcd.setCursor(0,1);
  mylcd.print("LED Bright: ");
  mylcd.print(ledValue);
  delay(1000);
}

// //BONUS
// #include <LiquidCrystal.h>

// const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
// LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);
// const int potPin = A0;
// const int ledPin = 6;
// int brightness = 0;
// int potValue =0;  


// void setup()
// {
//   Serial.begin(9600);
//   mylcd.begin(16, 2);

//   pinMode(ledPin, OUTPUT);
//   mylcd.setCursor(0,0);
//   mylcd.print("Pot Value: ");
//   mylcd.setCursor(0, 1);    // Move to the second row
//   mylcd.print("LED Bright: ");
// }
// void loop()
// {
//   //   Check if data is available in the serial buffer
//   if (Serial.available() > 0) 
//   {
//     // Read the value entered in the terminal
//     int inputValue = Serial.parseInt();  // Parse the input as an integer

//     // Constrain the input to be between 0 and 255 (valid PWM range)
//     potValue = constrain(inputValue, 0, 1023);
//     brightness = map(potValue, 0, 1023, 0, 255);
//     int newBrightness = Serial.parseInt();
//     newBrightness = constrain(newBrightness, 0, 255);

//     // Set the brightness of the LED
//     analogWrite(ledPin, brightness);
//     mylcd.clear();
//     // Display the brightness on the LCD
//     mylcd.setCursor(0,0);
//     mylcd.print("Pot Value:");
//     mylcd.print(potValue);
//     mylcd.setCursor(0, 1);    // Move to the second row
//     mylcd.print("LED Bright: ");
//     mylcd.print(brightness);  // Print the new brightness value

//     // Send the brightness value back to the serial monitor
//     Serial.print("LED Brightness set to: ");
//     Serial.println(brightness);
//   }
//   delay(100);  // Add a small delay for stability
// }
