const int led = 10;
const int button = 2;
const int threshold = 650;
const int sample = 10;

bool armed = false;      
int lastButton = HIGH;   

int readLdrAverage(int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(A0);
    delay(1);
  }
  return sum / n;
}
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("DISARMED");
}
void loop() {
  int Button = digitalRead(button);
  if (Button == LOW && lastButton == HIGH) {  
    armed = !armed;                            
    if (armed) Serial.println("ARMED");
    else Serial.println("DISARMED");
    delay(50);
  }
  lastButton = Button;  
  int ldrValue = readLdrAverage(sample);
  if (armed && ldrValue > threshold) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(50);
}
