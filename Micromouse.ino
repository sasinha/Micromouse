
# include "headers/motorLogic.hpp"
# include "headers/sensors.hpp"
# include "headers/encoders.hpp"

void setup() {
  // put your setup code here, to run once:
//  sensorSetup();
  motorSetup();

  setupEncoders();
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  sensorTestPrint();
  straight();
  motorRun();

  findFirstForward();
  delay(1000);
  

}
