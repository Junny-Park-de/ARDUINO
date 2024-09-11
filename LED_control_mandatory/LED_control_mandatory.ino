int buttonPin = 4;
int green = 11;
int yellow = 10;
int red = 9;
int lastButtonState = 0;
int buttonState = 0;

int counter = 0;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == LOW && lastButtonState == HIGH)
  {
    counter++;
  }
  lastButtonState = buttonState;
  // Serial.print("Sensor value is: "); //print a message to the serial monitor
  // Serial.println(lastButtonState);
 
  if (counter % 2 == 0)
  {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
  }
  else
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH); //blink
    digitalWrite(yellow, HIGH);
    delay(200);
    digitalWrite(red, LOW); //wait
    digitalWrite(yellow, LOW);
    delay(800);
  }
}
