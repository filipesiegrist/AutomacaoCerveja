#include <Leds.h>
#include <SensorTemperatura.h>

Leds leds;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  leds.set_red();
  delay(150);
  leds.set_yellow();
  delay(150);
  leds.set_green();
  delay(150);
}
