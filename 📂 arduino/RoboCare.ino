#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

// Objects
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int heartRatePin = A0;
const int relayPin = 4;

void setup() {
  Serial.begin(9600);

  // LCD init
  lcd.init();
  lcd.backlight();

  // Servo Driver init
  pwm.begin();
  pwm.setPWMFreq(60);

  // RTC init
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Relay init
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Robo_Care Start");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  // Read heart rate (dummy analog)
  int heartValue = analogRead(heartRatePin);

  // Display info
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());

  lcd.setCursor(0, 1);
  lcd.print("HR:");
  lcd.print(heartValue);

  // Example: control fan via relay if HR too high
  if (heartValue > 600) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  delay(1000);
}
