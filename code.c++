//#include<LiquidCrystal_I2C.h>
#define led_pin 13
int smokeA0 = A0;
int buzzer = 11;

float sensorValue;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  Serial.println("Gas Sensor Warming up!");
  delay(2000);//Allow MQ2 to warm up
  noTone(buzzer);
}

void loop() {
  sensorValue = analogRead(smokeA0);//read analog pin
  if(sensorValue > 385)
  {
    //tone(buzzer, 1000,2000);
    Serial.print("Smoooke\n");
    digitalWrite(led_pin,HIGH);
   // delay(100);
    //digitalWrite(led_pin,LOW); 
    //delay(100);
  }
  else {
    noTone(buzzer);
    Serial.print("No smoke\n");
    digitalWrite(led_pin, LOW);
  }
 
}
