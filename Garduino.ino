//Here is my code which I copied from the file:
const int sensor_pin = A0;
#include <dht.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;
#define DHTTYPE DHT11  
#define DHT_PIN 9
int LED_GREEN = 12;
int LED_YELLOW = 6;
int LED_RED = 7;

void setup()
{
 Serial.begin(9600);
lcd.begin(16, 2);
pinMode(LED_GREEN, OUTPUT);
pinMode(LED_YELLOW, OUTPUT);
pinMode(LED_RED, OUTPUT);

}
void loop()
{
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
 int t =  DHT.temperature;
 int h = DHT.humidity;
 int chk = DHT.read11(DHT_PIN);
 // LCD output
if (moisture_percentage < 20){
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}
if (moisture_percentage < 50){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, LOW);
}
if(moisture_percentage>=50){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, HIGH);
}


for (int positionCounter = 0; positionCounter < 29; positionCounter++) 
{
lcd.scrollDisplayLeft();
lcd.setCursor(0, 0);
lcd.print(" Garduino");
 lcd.setCursor(0,1);
 lcd.print("Moist:");
lcd.print(moisture_percentage);
lcd.print("%");
lcd.print(" Temp:");
lcd.print(DHT.temperature);
lcd.print(char(223));
lcd.print("C ");
 lcd.print("Humi: ");
 lcd.print(DHT.humidity);
 lcd.println("%");
// Serial Monitor Output
  Serial.print("Temperature = ");
 Serial.print(DHT.temperature);
 Serial.println("*C");
 Serial.print("Humidity = ");
 Serial.print(DHT.humidity);
 Serial.println("%");
 Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%");
 delay(1000);
  }
}
