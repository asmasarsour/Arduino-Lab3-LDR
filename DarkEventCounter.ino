
const int threshold = 650;
int count = 0;
bool lastDark = false;

int readLdrAverage(int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(A0);
    delay(1);
  }
  return sum / n;
}
void setup() {
  Serial.begin(9600);
}
void loop() {
  int v = readLdrAverage(10);
  bool dark = (v > threshold);

  if (dark && !lastDark) {    
    count++;
    Serial.print("Count: ");
    Serial.println(count);
  }
  lastDark = dark;
  delay(200);
}
