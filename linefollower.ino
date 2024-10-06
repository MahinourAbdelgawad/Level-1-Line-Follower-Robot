int ENL = 11; //enable left
int leftWheel1 = 10;
int leftWheel2 = 9;

int ENR = 6; //enable right
int rightWheel1 = 8;
int rightWheel2 = 7;

//Add the pin numbers and uncomment
// int sensorLeft =
// int sensorRight =
// int sensorMid = 

void setup() {
  pinMode(ENL, OUTPUT);
  pinMode(leftWheel1, OUTPUT);
  pinMode(leftWheel2, OUTPUT);

  pinMode(ENR, OUTPUT);
  pinMode(rightWheel1, OUTPUT);
  pinMode(rightWheel2, OUTPUT);

  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);
  pinMode(sensorMid, INPUT);

}

//FOR TESTING FUNCTIONS. REMOVE FUNCTION WHEN DONE AND MOVE TO MAIN LOOP
void loop() {
  forward();
  delay(5000);

  backward();
  delay(5000);

  right();
  delay(5000);

  sharp_right();
  delay(5000);

  left();
  delay(5000);

  sharp_left();
  delay(5000);

  stop();
}


//THIS IS THE MAIN LOOP. UNCOMMENT AFTER TESTING ALL THE FUNCTIONS SEPARATELY. ONLY WORKS ON TRACK
// void loop() {
//   bool sensorVL = digitalRead(sensorLeft); //sensor value left
//   bool sensorVR = digitalRead(sensorRight); //sensor value right
//   bool sensorVM = digitalRead(sensorMid); //sensor value middle

//   if ((sensorVL == 1 && sensorVM == 0 && sensorVR == 1) || (sensorVL == 0 && sensorVR == 0))
//     forward();

//   else if (sensorVL == 0 && sensorVM == 0 && sensorVR == 1)
//     left();
//   else if (sensorVL == 0 && sensorVM == 1 && sensorVR == 1)
//     sharp_left();
  
//   else if (sensorVL == 1 && sensorVM == 0 && sensorVR == 0)
//     right();
//   else if (sensorVL == 1 && sensorVM == 1 && sensorVR == 0)
//     sharp_right();

//   else if (sensorVL == 1 && sensorVM == 1 && sensorVR == 1)
//     stop();
// }


void forward() {
  analogWrite(ENL, 255);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 255);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void backward() {
  analogWrite(ENL, 255);
  digitalWrite(leftWheel1, LOW);
  digitalWrite(leftWheel2, HIGH);

  analogWrite(ENR, 255);
  digitalWrite(rightWheel1, HIGH);
  digitalWrite(rightWheel2, LOW);
}

void right() {
  analogWrite(ENL, 255);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 180);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void sharp_right() {
  analogWrite(ENL, 255);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 90);
  digitalWrite(rightWheel1, HIGH);
  digitalWrite(rightWheel2, LOW);

} 


void left() {
  analogWrite(ENL, 180);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 255);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void sharp_left() {
  analogWrite(ENL, 90);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 255);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void stop() {
  analogWrite(ENL, 0);
  analogWrite(ENR, 0);
}

