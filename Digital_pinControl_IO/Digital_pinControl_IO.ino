/*
Digital Pin Control:  Writen by Mark Meeuwneoord 2022
*/

const int offSet = 2; // start at pinNo
const int maxPins = 54; // change to your needs and boardtype

void setup()
{
  Serial.begin(9600);

  for (int i = offSet; i <= maxPins ; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  while (Serial.available() > 0) {
    int pinNo = Serial.parseInt();  // look for the next valid integer in serialstream: This is your pin nummber.
    int pinValue = Serial.parseInt(); // do it again: This is the pin state (high / low)

  if (Serial.read() == '\n') {
     if (pinNo >= offSet && pinNo <= maxPins)
      {
        digitalWrite (pinNo, pinValue);
        }
    }
  }
}
