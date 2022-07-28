#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#define ONE_WIRE_BUS 4

int fSensor=7;          
int buttonState = 1;   
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;

 
void setup(void)
{ 
  pinMode(A0, INPUT);
  Serial.begin(9600);
  sensors.begin();
  pinMode(fSensor, INPUT_PULLUP);
}

void temperature()
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000);
}

void floatSensor() 
{ 
buttonState = digitalRead(fSensor); 
  if (buttonState == LOW) 
  { 
    Serial.println( "WATER LEVEL - HIGH"); 
  } 
  else 
  { 
    Serial.println( "WATER LEVEL - LOW" ); 
  } 
delay(1000); 
}

void turbidity(){
  int sensorValue = analogRead(A0);// read the input on analog pin A0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage);
  
  delay(500);
}
  
void loop(void){
  temperature();
  floatSensor();
  turbidity();
}
