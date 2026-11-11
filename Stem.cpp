#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (or 0x3F for some models) with a 16x2 configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pins
const int rainAnalogPin = A0;  // Connects to AO on rain sensor
const int alertLed = LED_BUILTIN; // Built-in LED on Pin 13

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  
  // Initialize the LCD display
  lcd.init();                      
  lcd.backlight(); // Turn on backlight
  
  pinMode(alertLed, OUTPUT);

  // Splash screen startup message
  lcd.setCursor(0, 0);
  lcd.print("Eco-Tech Station");
  lcd.setCursor(0, 1);
  lcd.print("System Initializing");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read the analog wetness level (0 to 1023)
  int sensorValue = analogRead(rainAnalogPin);
  
  // Print to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Clear previous text line cleanly on row 0
  lcd.setCursor(0, 0);
  lcd.print("Water Val: ");
  lcd.print(sensorValue);
  lcd.print("   "); // Clear trailing digits

  // Condition logic based on your requested states
  lcd.setCursor(0, 1);
  
  if (sensorValue == 0) {
    // NORMAL STATUS (Explicitly when sensor value is 0)
    lcd.print("STATUS: NORMAL  ");
    digitalWrite(alertLed, LOW);
    delay(1000);
  }
  else if (sensorValue > 0 && sensorValue < 500) {
    // WARNING STATUS
    lcd.print("STATUS: WARNING ");
    digitalWrite(alertLed, HIGH);
    delay(500);
    digitalWrite(alertLed, LOW);
    delay(500);
  } 
  else {
    // DANGER STATUS (High values or dry/threshold exceeded depending on your sensor setup)
    lcd.print("STATUS: DANGER! ");
    digitalWrite(alertLed, HIGH);
    delay(150);
    digitalWrite(alertLed, LOW);
    delay(150);
  }
}
