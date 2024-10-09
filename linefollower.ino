int ENL = 11; //enable left
int leftWheel1 = 10;
int leftWheel2 = 9;

int ENR = 6; //enable right
int rightWheel1 = 8;
int rightWheel2 = 7;

int sensorLeft = 5;
int sensorRight = 3;
int sensorMid = 4;

int backCount = 0;
int lastRead = 000;

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

void loop() {
   int SL = digitalRead(sensorLeft); //sensor value left
   int SR = digitalRead(sensorRight); //sensor value right
   int SM = digitalRead(sensorMid); //sensor value middle

   // 0 represents black and 1 represents white 

  if(SL == 1 && SM == 1 && SR == 1) {
    if (backCount <= 4) {
      backward();
      backCount++;
    }
    else {
      if ((lastRead == 110) || (lastRead == 100))
        sharp_right();
      else if ((lastRead == 011) || (lastRead == 001))
        sharp_left();
      else
        forward();

      backCount = 0;
    }
    delay(20);
  } 

  else if (SL == 0 && SM == 0 && SR == 0) {
    forward(); 
    delay(50);  
  } 
  else if (SL == 1 && SM == 0 && SR == 1) {
    forward();
    delay(50);
  }
  else if (SL == 0 && SM == 1 && SR == 0) {
    forward();
    delay(50);
  }

  else if(SL == 1 && SM == 1 && SR == 0) {
    sharp_right(); 
    delay(100); 
  }  

  else if(SL == 0 && SM == 1 && SR == 1) {
    left(); 
    delay(100); 
  }

  else if(SL == 1 && SM == 0 && SR == 0) {
    right(); 
    delay(100); 
  }  

  else if(SL == 0 && SM == 0 && SR == 1) {
    left(); 
    delay(100); 
  }  

  else {
    stop();
  }
  
} 

void forward() {
  analogWrite(ENL, 170);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 150);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void backward() {
  analogWrite(ENL, 100);
  digitalWrite(leftWheel1, LOW);
  digitalWrite(leftWheel2, HIGH);

  analogWrite(ENR, 100);
  digitalWrite(rightWheel1, HIGH);
  digitalWrite(rightWheel2, LOW);
}

void right() {
  analogWrite(ENL, 150);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 0);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void sharp_right() {
  analogWrite(ENL, 255);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 100);
  digitalWrite(rightWheel1, HIGH);
  digitalWrite(rightWheel2, LOW);

} 

void left() {
  analogWrite(ENL, 0);
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);

  analogWrite(ENR, 130);
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
}

void sharp_left() {
  analogWrite(ENL, 80);
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