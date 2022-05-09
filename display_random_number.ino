#include <Arduino.h>
#include <TM1637TinyDisplay.h>

//define pins below
#define CLK 5
#define DIO 6

const int buttonPin = 3;

int buttonState = 0;
int count_value = 0;
int prestate = 0;

int count = 0;

//Initialize TM1637TinyDisplay
TM1637TinyDisplay display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f);

  pinMode(buttonPin, INPUT);
}

void loop() {

buttonState = digitalRead(buttonPin);

//random number code below
  if (buttonState == HIGH && prestate == 0) {
    count = random(100);
    display.showNumber(count);
  } else {
    prestate = 0;
  }
}
