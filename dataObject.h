/* ~~~~~~~~~~~~~ dataObject.h ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   Library to implement data sorting & filtering algorithms

   Data Filtering Algorithms:

   - Recursive Filter

   - Averaging Values


    Data Sorting:


    Started by

    Imogen Wren

    01.11.2020

*/



#ifndef dataObject_h
#define dataObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#define basicFilter recursiveFilter   // Synonyms for basic methods

#define DATA_ARRAY_SIZE 128

#define SAMPLE_HISTORY 128

// 15/03/2022 GETTING WEIRD COMPILER WARNINGS
/*
   'float dataObject::w' [-Wreorder]

     float w;             // bias value for recursive filter



*/
// SOLUTION MAY BE:?
//The key takeaway: initializer list members "should appear in the same order as they appear in the class definition".
// THINK THAT WORKED

class dataObject
{

  public:
    // Constructor

    dataObject(float filterBias = 0.9, bool serialMonitor = false):
      printSerial(serialMonitor),
      w(filterBias)
    {
    }

    void begin(uint32_t baudrate = 115200);    // Serial Comms

    // Filter Variables

    // Filter Methods
    int32_t recursiveFilter(int32_t Xn);


    //Averaging Variables
    int16_t g_data_array[SAMPLE_HISTORY];

    // Averaging Methods
    void addDataPoint(int16_t dataPoint);
    int16_t returnMean(int16_t g_data_array[SAMPLE_HISTORY]);  // Takes Data From anywhere
    int16_t calcMean();                                      // Uses global array

    // Plotting and Printing Methods
    void plotHeadings();
    void plotMean(int16_t last_data_point, int16_t rolling_mean);
    void printArray(int16_t dataArray[SAMPLE_HISTORY]);





    // Variables


    //   int16_t data_array[DATA_ARRAY_SIZE];    // Used for averaging methods

    private:

    int32_t Ypre;   //Y(n-1) Variable used for recursive filter

    bool printSerial;

    float w;             // bias value for recursive filter



};




#endif