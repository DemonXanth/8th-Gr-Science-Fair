const int p1 = A4;
const int p2 = A5;

int h;
int m;
int s;
int ms;

int v1;
int v2;

void setup(){
	Serial.begin(9600);
}

void time(int h,int m,int s,int ms){
	delay(100);
	ms += 100;
	
	if(ms == 1000){
		ms = 0;
		s++;
	}
	
	if(s == 60){
		s = 0;
		m++;
	}
	
	if(m == 60){
		m = 0;
		h++;
	}
	
	Serial.print(h);
	Serial.print(":");
	Serial.print(m);
	Serial.print(":");
	Serial.print(s);
	Serial.print(":");
	Serial.print(ms);
	
	v1 = analogRead(p1);
	v2 = analogRead(p2);
	Serial.print("  Middle:");
	Serial.print(v1);
	Serial.print("  Pinky:");
	Serial.print(v2);
	Serial.println(" ");
}

void loop(){
	v1 = analogRead(p1);
	v2 = analogRead(p2);
	Serial.print("  Middle:");
	Serial.print(v1);
	Serial.print("  Pinky:");
	Serial.print(v2);
	Serial.println(" ");
}