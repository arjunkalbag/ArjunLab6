SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

uint64_t reading = analogRead(A4);
double voltage = (reading * 3.3) / 4095.0;
double temperature = (voltage - 0.5) * 100;
double ftemp = (temperature * (9 / 5)) + 32;

void setup()
{
  display.setup();
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("%f C \n", temperature);
  display.println(" ");
  display.printf("%f F", ftemp);
  display.display();
}

void loop()
{

  uint64_t reading = analogRead(A4);
}