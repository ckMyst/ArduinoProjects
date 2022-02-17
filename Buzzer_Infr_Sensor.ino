int buzzer = 13; 
int sensor = 12;


int commenceTime = 10;
long unsigned int lstate;

long unsigned int halt = 5000;


bool low = true;
bool lowtime;
// Before commencing, test to see if buzzer still works


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(sensor, LOW);
  Serial.begin(9600);

  Serial.print("Loading sensor");
    for(int i = 0; i < commenceTime; i++){
      Serial.print("-");
      delay(1000);
    }
  Serial.println("Sensor now active");
  delay(50);
}

void loop() {
  int val = digitalRead(sensor);
      if (val == HIGH) {
        digitalWrite(buzzer, HIGH);
        if (low) {
          low = false;
          Serial.println("There is motion: ");
          Serial.print(millis()/1000);
          Serial.println(" seconds");
          delay(50);
        }
        lowtime = true;
      }
      
    if (val == LOW) {
      digitalWrite(buzzer, LOW);

    if (lowtime){
      lstate = millis();
      lowtime = false;
    }
    if (!low && millis() - lstate > halt){

      low = true;
      Serial.print("There is no motion: ");
      Serial.print(millis() - halt/1000);
      Serial.println(" seconds");
      delay(50);
      
    }
  }
}
