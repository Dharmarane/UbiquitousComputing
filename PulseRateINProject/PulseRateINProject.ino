#include <PeakDetection.h>
#include <SoftwareSerial.h>

//for bluetooth module
SoftwareSerial EEBlue(6, 5); // RX | TX

bool DEBUG=0;
int sensorPin = 0;
PeakDetection peakDetection;


/*Define the Pins*/
int red=3, ir=10, select=8;

/*This variable will store the string datatype of pulse rate, which is originally float*/
char sBPM[8]; // Buffer big enough for 7-character float

void setup() {
   Serial.begin(9600);
   EEBlue.begin(38400);  
   peakDetection.begin(30, 3, 0.2);
   pinMode(select, OUTPUT);
   
}
void loop (){

  if(DEBUG){
    //measure_prsr();
    debughr();
    //hr();
    //delay(2000);
    //Serial.println("Calculating Hb:");
    //hb2rx();  
  }
  
  else{
    if (EEBlue.available()){
      int ble_input = EEBlue.read();
      Serial.println(":Welcome To Two Touch Doctor:\n");
      EEBlue.write(":Welcome To Two Touch Doctor:\n");
      
      
      delay(5000);  //wait for some seconds for the user to stabilize
      hr();      //this function calculates the BPM and prints it in the Serial Monitor.  
      delay(1000);
      //hb2rx();
      //spo2();
      //pi();
      //bp();
      Serial.print("*****\n");
      
    }
  
  }
   
} 
