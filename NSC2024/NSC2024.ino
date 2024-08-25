// Motors
const int lMotFwd=4;
const int rMotFwd=2;
const int lMotRev=5;
const int rMotRev=3;

// Line following sensors
const int LL_pin=8;
const int L_pin=9;
const int M_pin=10;
const int R_pin=11;
const int RR_pin=12;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(LL_pin,INPUT);  //extreme left sensor
  pinMode(L_pin,INPUT);  //left
  pinMode(M_pin,INPUT);  // middle sensor
  pinMode(R_pin,INPUT);   // right
  pinMode(RR_pin,INPUT);  // extreme right sensor
    
  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

}

int followLine(int LL, int L, int M, int R, int RR)
{
  if (LL==0 && RR==0) {moveForward();}
  else if (LL==0) {turnLeft();}
  else if (RR==0) {turnRight();}
  else {moveForward();}

}

void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
  Serial.print("\nForward\n");
}

void moveBackward()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,LOW);
  digitalWrite(rMotRev,HIGH);
  digitalWrite(lMotRev,HIGH);
  Serial.print("\nBackward\n");
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
  Serial.print("\nLeft\n");
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,LOW);
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
  Serial.print("\nRight\n");
}

void turnCircle()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void Stop()
{

  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,LOW);
  digitalWrite(lMotRev,LOW);
  digitalWrite(rMotRev,LOW);
  
}

void loop() {
  
  int LL=digitalRead(LL_pin);
  int L=digitalRead(L_pin);
  int M=digitalRead(M_pin);
  int R=digitalRead(R_pin);
  int RR=digitalRead(RR_pin);

  Serial.print(LL);
  Serial.print("\t");
  Serial.print(L);
  Serial.print("\t");
  Serial.print(M);
  Serial.print("\t");
  Serial.print(R);
  Serial.print("\t");
  Serial.print(RR);
  Serial.print("\n");

  followLine(LL, L, M, R, RR);

}

void testLoop(){
  moveForward();
  delay(1000);
  moveBackward();
  delay(1000);
  turnLeft();
  delay(1000);
  turnRight();
  delay(1000);
}