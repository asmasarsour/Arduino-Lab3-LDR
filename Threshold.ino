const int led = 10;
const int threshold = 632;   // (250 + 1015) / 2
const int sample = 10;
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
  Serial.begin(9600);
}
void loop() {
  int ldrValue = readLdrAverage(sample);
  if (ldrValue > threshold) {
    digitalWrite(led, HIGH);   
  } else {
    digitalWrite(led, LOW);    
  }
  Serial.print("ldr:");
  Serial.print(ldrValue);
  Serial.print(",threshold:");
  Serial.println(threshold);
  delay(100);
}
