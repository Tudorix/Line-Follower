// Motor Pins
int ena = 5;
int inA = 6;
int inB = 7;

int enb = 10;
int inC = 11;
int inD = 12;

#define ir1 A1
#define ir2 A2
#define ir3 A3
#define ir4 A4
#define ir5 A5

// PID parameters
float Kp = 20; 
float Ki = 0;
float Kd = 5;

float lastError = 0;
float integral = 0;

float error;

int speed = 220;

void powerMotors(int speed1, int speed2){
  digitalWrite(inC , LOW);
  digitalWrite(inD , HIGH);
  analogWrite(enb , speed1);
  digitalWrite(inA , HIGH);
  digitalWrite(inB , LOW);
  analogWrite(ena , speed2);
}

int getLine(){
  int s1 = digitalRead(ir1);
  int s2 = digitalRead(ir2);
  int s3 = digitalRead(ir3);
  int s4 = digitalRead(ir4);
  int s5 = digitalRead(ir5);
  int sum = 0;

  if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1){
    return -1;
  }

  if(s1 == 0){
    sum = -2;
  }

  if(s2 == 0){
    sum = -1;
  }

  if(s3 == 0){
    sum = 0;
  }

  if(s4 == 0){
    sum = 1;
  }

  if(s5 == 0){
    sum = 2;
  }

  return sum;
}

void setup() {
  Serial.begin(9600);

  pinMode(ena,OUTPUT);
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);

  pinMode(enb,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  digitalWrite(inA , LOW);
  digitalWrite(inB , LOW);
  digitalWrite(inC , LOW);
  digitalWrite(inD , LOW);
  delay(2000);
}

void loop() {
  int position = getLine();
  if(position >= 0){
     error = 0 - position;// target is 0 (centered)
  }
    
  if(position == 0){
    powerMotors(255,255);
  }else if(position == 2){
    powerMotors(255,0);
  }else if(position == -2){
    powerMotors(0,255);
  }
}
