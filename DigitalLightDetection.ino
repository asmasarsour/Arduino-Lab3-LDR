
void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
}

void loop() {
  int ao = analogRead(A0);
  int dout = digitalRead(3);
  Serial.print("AO: ");
  Serial.print(ao);
  Serial.print("  DO: ");
  Serial.println(dout);
  delay(300);
}
