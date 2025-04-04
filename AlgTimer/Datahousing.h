//========================
// DATAHOUSING.H
//========================
#ifndef DATAHOUSING_H
#define DATAHOUSING_H

//========================
// INCLUDES
//========================
#include "StopWatch.h"
#include <iostream>

//========================
// DATA HOUSING CLASS
//========================
class DataHousing {
private:
    // Helper Methods
    void copyArrayToTemp();                    // Copy main array to temp
    void bubbleSort   (int* arrayToSort) const;// Bubble sort algorithm
    void selectionSort(int* arrayToSort) const;// Selection sort algorithm
    void insertionSort(int* arrayToSort) const;// Insertion sort algorithm

    // Data Members
    int* data;                // Main data array
    int* tempArray;           // Working copy array
    int arraySize;            // Current array size
    StopWatch timer;          // Timer for sorts

    // Time Storage
    double bubbleSortTime;    // Bubble sort timing
    double selectionSortTime; // Selection sort timing
    double insertionSortTime; // Insertion sort timing

public:
    // Core Operations
    DataHousing();                               // Initialize members
    ~DataHousing();                              // Clean up memory
    bool readDataFromFile(const char* filename); // Read data file
    void runSortingTests();                      // Run all sorts

    // Getters
    double getBubbleSortTime()    const { return bubbleSortTime; }
    double getSelectionSortTime() const { return selectionSortTime; }
    double getInsertionSortTime() const { return insertionSortTime; }
};
#endif