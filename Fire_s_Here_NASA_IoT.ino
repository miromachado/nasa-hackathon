#include <dht.h>
#define dht_pin A0
#define LED 2
#define Buzzer 3

dht DHT;
int temp;

void setup() {
      Serial.begin(9600);
      pinMode(LED,OUTPUT);
      pinMode(Buzzer, OUTPUT);
      Serial.println("Test of the temperature sensor...");
}

void loop() {
      Serial.print("Temperature: ");
      Serial.print(MedTemp());
      Serial.print(" C°\n");
      if(temp > 40){
        digitalWrite(Buzzer,HIGH);
        digitalWrite(LED,HIGH);
      }else{
        digitalWrite(Buzzer,LOW);
        digitalWrite(LED,LOW);
      }
      delay(2000);
}

String MedTemp()
{
  DHT.read11(dht_pin);
  temp = DHT.temperature;
  return String(temp);
}
