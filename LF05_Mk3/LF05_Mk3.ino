const int l_in1 = 7;
const int l_in2 = 8;
const int r_in1 = 10;
const int r_in2 = 9;

int l_sensor;
int c_sensor;
int r_sensor;

unsigned int counter;

const int l_s = 820;

void setup() {
  //Serial.begin(115200);

  // IR sensor
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  // motor
  pinMode(l_in1, OUTPUT);
  pinMode(l_in2, OUTPUT);
  pinMode(r_in1, OUTPUT);
  pinMode(r_in2, OUTPUT);

  delay(2000);
}

void loop() {
  l_sensor = analogRead(A6);
  c_sensor = analogRead(A5);
  r_sensor = analogRead(A4);

if((l_sensor < l_s)&&(c_sensor > l_s)&&(r_sensor < l_s)){forword();}      //直進


if((l_sensor < l_s)&&(c_sensor > l_s)&&(r_sensor > l_s)){turnRight();}    //右旋回
if((l_sensor < l_s)&&(c_sensor < l_s)&&(r_sensor > l_s)){turnRight();}


if((l_sensor > l_s)&&(c_sensor > l_s)&&(r_sensor < l_s)){turnLeft();}     //左旋回
if((l_sensor > l_s)&&(c_sensor < l_s)&&(r_sensor < l_s)){turnLeft();}


if((l_sensor < l_s)&&(c_sensor < l_s)&&(r_sensor < l_s)){ninetyDeg();}         //90度ターン用
}

void forword() {
  counter = 0;
  digitalWrite(l_in2, HIGH);
  digitalWrite(r_in2, HIGH);
  digitalWrite(l_in1, LOW);
  digitalWrite(r_in1, LOW);
}

void turnRight() {
  counter = 0;
  digitalWrite(l_in2, HIGH);
  digitalWrite(r_in2, HIGH);
  digitalWrite(l_in1, LOW);
  digitalWrite(r_in1, HIGH);
}

void turnLeft() {
  counter = 0;
  digitalWrite(l_in2, HIGH);
  digitalWrite(r_in2, HIGH);
  digitalWrite(l_in1, HIGH);
  digitalWrite(r_in1, LOW);
}

void ninetyDeg() {
  if(++counter > 8000) {
    digitalWrite(l_in2, HIGH);
    digitalWrite(r_in2, LOW);
    digitalWrite(l_in1, LOW);
    digitalWrite(r_in1, HIGH);
  } else {
    digitalWrite(l_in2, LOW);
    digitalWrite(r_in2, HIGH);
    digitalWrite(l_in1, HIGH);
    digitalWrite(r_in1, LOW);
  }
}
