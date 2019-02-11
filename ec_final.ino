#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>





#include "DHT.h"

#define DHTPIN 7 // what digital pin we're connected to
int lm393 = 5;
int kg003 = A2;
int output;
int relay1 = 14;
int relay2 = 15;
int relay3 = 16;

// Uncomment whatever type you're using!

#define DHTTYPE DHT11 // DHT 11

//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {

Serial.begin(9600);

dht.begin();
pinMode(lm393,INPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);

}

void loop() {

// Wait a few seconds between measurements.

delay(2000);

output=analogRead(kg003);
output=map(output,1021,505,0,100);

// Reading temperature or humidity takes about 250 milliseconds!

int h = dht.readHumidity();

// Read temperature as Celsius (the default)

int t = dht.readTemperature();

Serial.print("Humidity: ");

Serial.print(h);

Serial.print("\t"); // for splitting

Serial.print("Temperature: ");

Serial.print(t);

Serial.print("\t");

Serial.print("  Moisture: ");
Serial.print(output);

Serial.print("\n"); // for new line




if(t>20||h>60)
  {digitalWrite(relay1,HIGH);}
  else
  {digitalWrite(relay1,LOW);}

if(output<20)
  {digitalWrite(relay3,HIGH);}
  else
  {digitalWrite(relay3,LOW);}
  

int ldr = digitalRead (lm393);
  if(ldr==1)
  {
    digitalWrite(relay2,HIGH);
  }
  else
  {
    digitalWrite(relay2,LOW);
  }


  
  delay(2000);


}
