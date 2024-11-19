#include <Arduino.h>
#define BUTTON_PIN 22 //Set ESP22 pin to input pull-up mode GIOP22 
#define LED_PIN 23 //Set ESP23 pin to output mode GIOP23

int led_state = HIGH; //The corrent state of LED
int button_state; //The corrent state of the button
int last_button_state; //The previous state of button

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  //pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  button_state = digitalRead(BUTTON_PIN); //HIGH
}

void loop() {
  last_button_state = button_state; //Save the last state
  Serial.println(last_button_state); //HIGH
  button_state = digitalRead(BUTTON_PIN); //Read new state
  Serial.println(button_state); //HIGH

  if(last_button_state == HIGH && button_state == LOW){
    Serial.println(button_state);
    Serial.println(last_button_state);
    Serial.println("The button is pressed");
    led_state = !led_state; //Toggle state of LED
    digitalWrite(LED_PIN, led_state); //Control LED arcording to the 
  }
}