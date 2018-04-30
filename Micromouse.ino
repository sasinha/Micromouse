
# include "headers/motorLogic.hpp"
# include "headers/sensors.hpp"


void setup() {
  // put your setup code here, to run once:
  sensorSetup();
  motorSetup();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorTestPrint();
  straight();
  motorRun();

  delay(500);
  

}
