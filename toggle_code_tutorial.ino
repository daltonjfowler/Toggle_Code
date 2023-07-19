int buttonPin = 2; //button plugged into D2
int ledPin = 3; //LED plugged into D3

int buttonState = 0; //hold if a button is pressed or not. 0 = not press, 1 = press!
int toggle = 0; //flip 0 to 1 depending on LED state

void setup()
{
  Serial.begin(9600);       //refresh rate for our board
  pinMode(ledPin, OUTPUT);  //output for LED
  pinMode(buttonPin, INPUT); //input for our button
}

void loop()
{
  buttonState = digitalRead(buttonPin); //what is the button state? Pressed or not?
  if (buttonState == 1) //is button pressed?
  {
    if (toggle == 0) //flip value or LED on OR off
    {
      digitalWrite(ledPin, HIGH); //led is on!
      toggle = 1; //next time the button is pressed, go to turn LED off.
    }
    else
    {
      digitalWrite(ledPin, LOW); //led is off!
      toggle = 0; //next time the button is pressed, go to turn LED on.
    }
    delay(250); //quarter second delay for human reaction time
  }
}
