const int led1 = 10;
const int led2 = 9;
const int T_DIM = 550;
const int T_DARK = 700;
int lastLevel = -1;   

int readLdrAverage(int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(A0);
    delay(1);
  }
  return sum / n;
}
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int v = readLdrAverage(10);
  int level;
  if (v <= T_DIM) {
    level = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else if (v <= T_DARK) {
    level = 1;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    level = 2;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  if (level != lastLevel) {         
    if (level == 0) Serial.println("Bright");
    if (level == 1) Serial.println("Dim");
    if (level == 2) Serial.println("Dark");
    lastLevel = level;
  }
  delay(100);
}
