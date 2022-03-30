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




// ~~~ Averaging Methods ~~~




// Averaging Methods
void dataObject::addDataPoint(int16_t dataPoint) {
  for (int i = 0; i < (SAMPLE_HISTORY - 1) ; i++) {
    g_data_array[i] = g_data_array[i + 1];
  }
  g_data_array[SAMPLE_HISTORY - 1] = dataPoint;
}



int16_t dataObject::returnMean(int16_t dataArray[SAMPLE_HISTORY]) {
  int32_t M = 0;
  for (int i = 0; i < SAMPLE_HISTORY; i++) {
    M = M + dataArray[i];
  }
  float f_average = float(M) / float(SAMPLE_HISTORY);
  // Serial.print(f_average);
  //  Serial.print(", \n");
  M = int(f_average + 0.5);
  //  Serial.print(M);
  //  Serial.print(", \n");
  return M;
}

int16_t dataObject::calcMean() {
  int16_t meanAverage;
  meanAverage = dataObject::returnMean(g_data_array);
  return meanAverage;
}


// Plotting and Printing Methods
void dataObject::plotHeadings() {
  Serial.println("last_data_point, rolling_mean, ");
}

void dataObject::plotMean(int16_t last_data_point, int16_t rolling_mean) {
  char buffer[32];
  sprintf(buffer, "%i, %i,", last_data_point, rolling_mean);
  Serial.println(buffer);
}

void dataObject::printArray(int16_t dataArray[SAMPLE_HISTORY]) {
  for (int i = 0; i < SAMPLE_HISTORY; i++) {
    Serial.print(dataArray[i]);
    Serial.print(", ");
  }
  Serial.print("\n");
}