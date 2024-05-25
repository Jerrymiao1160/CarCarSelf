#include "DHT.h"
#define DHTPIN 7 
#define DHTTYPE DHT11
//#define DHTTYPE DHT22   // DHT 22 如果用的是DHT22，就用這行
//#define DHTTYPE DHT21   // DHT 21
DHT dht(DHTPIN, DHTTYPE);
int INA = 9; 

int INB = 8;

int power = A0;

int water = 6;
void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();  //初始化DHT

  pinMode(INA,OUTPUT);

  pinMode(INB,OUTPUT);

  pinMode(power,OUTPUT);

  pinMode(water,OUTPUT);
  
} // setup()

int speed = 255;
int wateropen = 1;
void loop()
{
  delay(1000);
  float h = dht.readHumidity();   //取得濕度
  float t = dht.readTemperature();  //取得溫度C

  //顯示在監控視窗裡
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  digitalWrite(INA,LOW);

  digitalWrite(INB,HIGH);
  digitalWrite(water, HIGH);

  analogWrite(power,speed);
  speed = speed-50;
  if(speed<50) speed = 255;

  if(h>75) speed = 0;

  delay(1000);
 
} // loop()