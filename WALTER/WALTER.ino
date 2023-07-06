#include <NewPing.h>

#define IN1 3  // direita frente
#define IN2 5  // direita tras
#define IN3 10 // esquerda frente
#define IN4 11 // esquerda tras
#define IRD 13
#define IRE 2
#define TRIGGER 9
#define ECHO 8

bool flag;
const int calibra = 5, vel_car = 60;

NewPing sonar (TRIGGER, ECHO, 200);

void setup() {
  Serial.begin(9600);
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(IRD, INPUT);
  pinMode(IRE, INPUT);
}

void loop() {
  if (digitalRead(IRE) && digitalRead(IRD)){
    frente(vel_car);
    flag = true;
    }
  else if (!digitalRead(IRE) && digitalRead(IRD)){
    if (flag)
      freiar(100);
    direita(vel_car);
    flag = false;
    }
  else if (digitalRead(IRE) && !digitalRead(IRD)){
    if (flag)
      freiar(100);
    esquerda(vel_car);
    flag = false;
    }
  else{
    frente(vel_car);
    }
  Serial.println(sonar.ping_cm());
  while (sonar.ping_cm() < 5) {
    tras(vel_car);
    }
  }
void frente(int v){
  analogWrite(IN1, v);
  analogWrite(IN2, 0);
  analogWrite(IN3, v - calibra);
  analogWrite(IN4, 0);
  }
void tras(int v){
  analogWrite(IN1, 0);
  analogWrite(IN2, v);
  analogWrite(IN3, 0);
  analogWrite(IN4, v - calibra);
  }
void esquerda(int v){
  analogWrite(IN1, 0);
  analogWrite(IN2, 255);
  analogWrite(IN3, v - calibra);
  analogWrite(IN4, 0);
  }
void direita(int v){
  analogWrite(IN1, v);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 255);
  }
void freiar(int t){
  analogWrite(IN1, 255);
  analogWrite(IN2, 255);
  analogWrite(IN3, 255);
  analogWrite(IN4, 255);
  delay(t);
  }
void girarnoeixo(char lado, int graus){
  int tempo = map (graus, 0, 359, 0, 2500);
  switch (lado) {
    case 'e':
      analogWrite(IN1, 0);
      analogWrite(IN2, 50);
      analogWrite(IN3, 50);
      analogWrite(IN4, 0);
      delay(tempo);
    break;
    case 'd':
      analogWrite(IN1, 50);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 50);
      delay(tempo);
    break;
    default:
      analogWrite(IN1, 0);
      analogWrite(IN2, 50);
      analogWrite(IN3, 50);
      analogWrite(IN4, 0);
      delay(tempo);
    break;
    }
  }
