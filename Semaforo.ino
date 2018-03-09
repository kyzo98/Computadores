#define INTERVAL_E1 20000;
#define INTERVAL_SWAP 15000;
#define INTERVAL_E2 3000;
#define INTERVAL_E3 1000;
#define INTERVAL_E4 10000;
#define INTERVAL_E5 1000;
#define INTERVAL_EF 5000;

#define LED_CAR_RED 2;
#define LED_CAR_ORANGE 3;
#define LED_CAR_GREEN 4;

#define LED_PIPOL_RED 5;
#define LED_PIPOL_GREEN 6;

unsigned long previousTime;
unsigned long time;
int status;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_CAR_RED, OUTPUT);
  pinMode(LED_CAR_ORANGE, OUTPUT);
  pinMode(LED_CAR_GREEN, OUTPUT);
  pinMode(LED_PIPOL_RED, OUTPUT);
  pinMode(LED_PIPOL_GREEN, OUTPUT);
  status = 0;
}

void loop()
{
  time = millis(); 
  switch(status){
    case 0:
      digitalWrite(LED_CAR_RED, LOW);
      digitalWrite(LED_CAR_ORANGE, LOW);
      digitalWrite(LED_CAR_GREEN, LOW);
      digitalWrite(LED_PIPOL_RED, LOW);
      digitalWrite(LED_PIPOL_GREEN, LOW);
      status = 1;
      break;
    case 1:
      digitalWrite(LED_CAR_RED, LOW);
      if(time - previousTime >= INTERVAL_E1){
        status = 2;
      }
    if(time - previousTime >= INTERVAL){
      previousTime = time;
      status = !status;
    }
    if(status){
       digitalWrite(2, HIGH);
    }else{
      digitalWrite(2, LOW);
    }
  }
}
