#include <AFMotor.h>
AF_DCMotor motor(1);
void setup() 
{
  motor.setSpeed(200);
  motor.run(RELEASE);
}
void loop() 
{
  uint8_t i;

  motor.run(FORWARD);
  
  // Acelera de zero à velocidade máxima
  for (i=0; i<255; i++) 
  {
    motor.setSpeed(i);  
    delay(10);
  }
  
  // Desacelera da velocidade máxima para zero
  for (i=255; i!=0; i--) 
  {
    motor.setSpeed(i);  
    delay(10);
  }
  
  motor.run(BACKWARD);
  
  for (i=0; i<255; i++) 
  {
    motor.setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) 
  {
    motor.setSpeed(i);  
    delay(10);
  }
  motor.run(RELEASE);
  delay(1000);
}
