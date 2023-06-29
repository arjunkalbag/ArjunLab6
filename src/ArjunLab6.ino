SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void setup()
{
  display.setup();
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}

void loop()
{

  uint64_t reading = analogRead(A4);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  double ftemp = (temperature * 1.8) + 32;
  display.printf("%f C \n", temperature);
  display.println(" ");
  display.printf("%f F \n", ftemp);
  display.println(" ");
  display.display();
}