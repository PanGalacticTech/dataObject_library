/* ~~~~~~~~~~~~~ dataObject.cpp ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   Library to implement data sorting & filtering algorithms
      
   Data Filtering Algorithms:

   - Recursive Filter


    Data Sorting:


    Started by

    Pan Galactic Tech

    01.11.2020

*/


/* ~~~~~~~~~~~~~ dataObject.h ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Data Filtering Algorithms

   Library to store various data filtering
   & sorting algorithms



*/

#include "dataObject.h"








void dataObject::begin(uint32_t baudrate) {
  if (printSerial) {
    Serial.begin(baudrate);
  }
}





//~~~~~~~~~~~~~~~~~~ RECURSIVE FILTER METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
   The last filter is a recursive filter. A recursive filter is just one that calculates a new, smoothed value (Yn) by using the last smoothed value (Y(n – 1)) and a new measurement (xn):

  yn = w × xn + (1 – w) × yn – 1
  The amount of smoothing is controlled by a weighting parameter (w).

  The weight is a value between 0% and 100%. When the weight is high (say 90%),
  the filter doesn’t smooth the measurements very much but responds quickly to changes.
  If the weight is low (say 10%), the filter smooths the measurements a lot but doesn’t respond very quickly to changes.

  This is my favorite filter because:

  it doesn’t need much memory (just enough to store the last measurement)
  you can control how much filtering is applied with a single parameter (the weight)
  it works well in battery powered applications because you don’t need to make many measurements at once
*/


int32_t dataObject::recursiveFilter(int32_t Xn) {

  int32_t Yn;

  Yn = (w * Xn) + ((1 - w) * Ypre);

  if (printSerial) {
    Serial.print("Input: ");
    Serial.print(Xn);
    Serial.print("  Previous: ");
    Serial.print(Ypre);
    Serial.print("  Output: ");
    Serial.println(Yn);
  }

  Ypre = Yn;

  return Yn;
}
