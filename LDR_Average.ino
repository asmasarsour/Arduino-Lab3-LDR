const int ldr = A0;
const int SAMPLES = 10;  
int readLdrAverage(int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(ldr);
    delay(1);
  }
  return sum / n;
}

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println(readLdrAverage(SAMPLES));
  delay(200);
}
