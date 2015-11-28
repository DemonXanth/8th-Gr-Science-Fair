import processing.serial.*;
Serial myport;
Table datatable

int numReadings = 1000;
int readingCounter = 0;

String SFairData;

void setup(){
  String portname = Serial.list()[1];
  
  myport = new Serial(this, portName, 9600);
  
  table.addColumn("id");
  table.addColumn("hour");
  table.addColumn("minute");
  table.addColumn("second");
  table.addColumn("millisecond");
  table.addColumn("Pinky");
  table.addColumn("Middle");
}

void serialEvent(Serial myport){
  val = myport.readStringUntil('\n');
  if(val != null){
    val = trim(val);
    println(val);
    float sensorVals[] = float(split(val, ' '));
    
    TableRow newRow = dataTable.addRow();
    newRow.setInt("id", table.lastRowIndex());
    
    newRow.setInt("hour", hour());
    newRow.setInt("minute", minute());
    newRow.setInt("second", second());
    newRow.setInt("millisecond", millisecond());
    newRow.setFloat("Pinky", sensorVals[0]);
    newRow.setFloat("Middle", sensorVals[1]);
    
    readingCounter++;
    
    if(readingCounter % numReadings == 0){
      saveTable(dataTable, fileName);
    }
  }
}
