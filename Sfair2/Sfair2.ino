const int p1 = A4;
const int p2 = A5;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int v1 = analogRead(p2);
  int v2 = analogRead(p1);
  Serial.print("  Pinky:");
  Serial.print(v1);
  Serial.print("  Middle:");
  Serial.print(v2);
  Serial.println(" ");

}
