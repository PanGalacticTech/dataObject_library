/* ~~~~~~~~~~~~~ dataObject - Example ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   Library to implement data sorting & filtering algorithms
      
   Data Filtering Algorithms:

   - Recursive Filter


    Data Sorting:


    Started by

    Pan Galactic Tech

    01.11.2020

*/



#include "dataObject.h"


#define BAUDRATE 115200
#define FILTER_BIAS 0.7  // 0 to 1: Higher numbers = faster response less filtering // Lower numbers = Slower response, more filtering
#define SERIAL_MONITOR false;

dataObject dataLib(FILTER_BIAS, SERIAL_MONITOR);    // Create instance of Data library




void begin(){


dataLib.begin(BAUDRATE);     // Starts serial comms
  
}







int32_t input = 0;

int32_t output;



void loop(){


// Collect Some Data Here
  

output = dataLib.recursiveFilter(input);


Serial.println(output);


  
}
