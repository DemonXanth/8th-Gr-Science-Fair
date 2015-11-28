const int p1 = A4;
const int p2 = A5;

int h = 0;
int m = 0;
int s = 0;
int ms = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  time(h,m,s,ms);
}

void time(int hr,int mn,int sc,int mls){
  delay(100);
  mls = mls + 100;
  
  if(mls == 1000){
    mls = 0;
    sc++;
  }
  
  if(sc == 60){
    sc = 0;
    mn++;
  }
  
  if(mn == 60){
    mn = 0;
    hr++;
  }
  
  Serial.print(hr);
  Serial.print(":");
  Serial.print(mn);
  Serial.print(":");
  Serial.print(sc);
  Serial.print(":");
  Serial.print(mls);
  
  int v1 = analogRead(p2);
  int v2 = analogRead(p1);
  Serial.print("  Pinky:");
  Serial.print(v1);
  Serial.print("  Middle:");
  Serial.print(v2);
  Serial.println(" ");
}
