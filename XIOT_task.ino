
// Golabl Variables decelration
volatile bool flag = true;
unsigned long lastmillis = 0;

// Pins decelration 
int switch_output = 3;
int button_input = 2;
int temp_sensor = A0;

 
void setup()
{

pinMode(button_input,INPUT); // input for the 
pinMode(switch_output,OUTPUT); // output pim

digitalWrite(switch_output,LOW); // inital state of the LED

// The LED will be OFF while the push button is not pressed and will be ON only during the duration of PRESS
// THE Push button used in this example is a ON OFF whith no hold state 

attachInterrupt(digitalPinToInterrupt(button_input), sensorISR, CHANGE); // pin2 

Serial.begin(9600);

}

void loop(){

  float temp_value = analogRead(temp_sensor);

  if (millis() - lastmillis >= 3000) // send the temperature sensor every 3 second
  {
    Serial.println(temp_value);
    lastmillis = millis(); // Uptade lasmillis
  }

  }

void sensorISR()
{ 

  if(flag)
  {
      flag = false;
      Serial.println("pressed");  
  }
  
  delay(20); // for debouncing 

  if(digitalRead(button_input) == HIGH)
  digitalWrite(switch_output , HIGH);

  else if(digitalRead(button_input) == LOW)
  digitalWrite(switch_output, LOW) ;
}
