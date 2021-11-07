
// initialize needed variables
unsigned long Timer;
int RawData[5] = {0,0,0,0,0}; // array for raw ECG data
int i = 0; // variable to keep track of the array index
int sum = 0;
int val = 0;
int incomingByteR = 0;
int incomingByteL = 0;
int direction = 0; //1 is right -1 left 

float FilteredEOG = 0; // averaged value, output to serial monitor

void setup()
{
 Serial.begin(9600); // initialize serial interface
 Timer = 0;

}

void loop()
{
 if(millis() - Timer >= 500) //event timer set to occur 100 ms
 {
  sum = sum - RawData[i]; 
  val = analogRead(A3); //read the value of pin A3
  RawData[i] = val; //add the newest reading to val
  sum = sum + val; //add the newest value to sum
  i = (i+1) / 5; //increment the index
  FilteredEOG = sum / 5; //divide the sum by 5, to get the moving average filter

 // print to serial monitor or plotter
 //Serial.println(FilteredEOG);
 
 Timer += 500;
 }
 
 //delay(25);

 if (FilteredEOG > 72)
 {
    // read the incoming byte:
  incomingByteL = Serial.read();

    // say what you got:
  Serial.println("L ");
  delay(500);
  direction = -1;
 // Serial.println(incomingByteL, DEC);
  }

else if (FilteredEOG < 52)
 {
    // read the incoming byte:
  incomingByteR = Serial.read();

    // say what you got:
  Serial.println("R ");
  delay(500);
  direction = 1;
 // Serial.println(incomingByteR, DEC);
  }
}


/*
// initialize needed variables
unsigned long Timer;
int RawData[5] = {0,0,0,0,0}; // array for raw ECG data
int i = 0; // variable to keep track of the array index
int sum = 0;
int val = 0;
int incomingByteR = 0;
int incomingByteL = 0;
int direction = 0; //1 is right -1 left 

float FilteredEOG = 0; // averaged value, output to serial monitor

void setup()
{
 Serial.begin(9600); // initialize serial interface
 Timer = 0;

}

void loop()
{
 if(millis() - Timer >= 500) //event timer set to occur 100 ms
 {
  sum = sum - RawData[i]; 
  val = analogRead(A3); //read the value of pin A3
  RawData[i] = val; //add the newest reading to val
  sum = sum + val; //add the newest value to sum
  i = (i+1) / 5; //increment the index
  FilteredEOG = sum / 5; //divide the sum by 5, to get the moving average filter

 // print to serial monitor or plotter
 //Serial.println(FilteredEOG);
 
 Timer += 500;
 }
 
 //delay(25);

 if (FilteredEOG > 68)
 {
    // read the incoming byte:
  incomingByteL = Serial.read();

    // say what you got:
  Serial.println("L");
  delay(500);
  direction = -1;
 // Serial.println(incomingByteL, DEC);
  }

else if (FilteredEOG < 62)
 {
    // read the incoming byte:
  incomingByteR = Serial.read();

    // say what you got:
  Serial.println("R");
  delay(500);
  direction = 1;
 // Serial.println(incomingByteR, DEC);
  }
}
*/
