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


dataObject dataLib;    // Create instance of Data library

#define BAUDRATE 115200


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
