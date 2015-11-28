import processing.serial.*;
Serial mySerial;
PrintWriter output;
void setup(){
  mySerial =new Serial( this, Serial.list()[0],9600);
  output = createWriter("data.txt");
}
void draw(){
  if(mySerial.available() > 0){
    output.println(value);
