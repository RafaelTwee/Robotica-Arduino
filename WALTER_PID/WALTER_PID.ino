#include <NewPing.h>
/*motores*/
#define IN1 3  // direita frente
#define IN2 5  // direita tras
#define IN3 10 // esquerda frente
#define IN4 11 // esquerda tras
const int calibra = 5, vel_car = 60;

/*infravermelhos contados da esquerda pra direita visto de cima*/
#define IR0 A0
#define IR1 A1
#define IR2 A2
#define IR3 A3
const uint8_t pinosIR[] = {IR0, IR1, IR2, IR3};

/*ultrassonico*/
#define TRIGGER 9
#define ECHO 8
NewPing sonar (TRIGGER, ECHO, 200);

bool flag;

void setup() {
  Serial.begin(9600);
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  for (int i = 0; i < 4; i++)
    pinMode(pinosIR[i], INPUT);
}

void loop() {
  for (int i = 0; i < 4; i++){
    Serial.print(analogRead(pinosIR[i]));
    Serial.print(" | ");
    }
  Serial.println();
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
