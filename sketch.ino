#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2
#define WARNING_LED 13

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const float TEMP_LIMIT = 30.0;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  rtc.begin();
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(WARNING_LED, OUTPUT);
  
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  DateTime now = rtc.now();

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  if (now.hour() < 10) lcd.print('0');
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) lcd.print('0');
  lcd.print(now.minute());

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C   ");

  if (tempC > TEMP_LIMIT) {
    digitalWrite(WARNING_LED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("**TEMP WARNING**");
  } else {
    digitalWrite(WARNING_LED, LOW);
  }

  delay(1000);
}
