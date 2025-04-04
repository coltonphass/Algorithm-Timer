//========================
// DATAHOUSING.CPP
//========================
#include "DataHousing.h"
#include <fstream>
#include <iostream>
using namespace std;

//========================
// CONSTRUCTOR/DESTRUCTOR
//========================
DataHousing::DataHousing() {
    // Initialize pointers to null
    data              = nullptr;
    tempArray         = nullptr;
    arraySize         = 0;
    // Initialize timing storage
    bubbleSortTime    = 0;
    selectionSortTime = 0;
    insertionSortTime = 0;
}

DataHousing::~DataHousing() {
    // Clean up dynamic memory
    delete[] data;
    delete[] tempArray;
}

//========================
// FILE OPERATIONS
//========================
bool DataHousing::readDataFromFile(const char* filename) {
    // Open file
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Couldn't open file" << endl;
        return false;
    }

    // Count elements in file
    int count = 0;
    int temp = 0;
    while (inFile >> temp) {
        count++;
    }

    // Update array size
    arraySize = count;

    // Clean up old arrays if they exist
    if (data != nullptr) {
        delete[] data;
    }
    if (tempArray != nullptr) {
        delete[] tempArray;
    }

    // Allocate new arrays
    data      = new int[arraySize];
    tempArray = new int[arraySize];

    // Reset file and read data
    inFile.clear();  // Clear any errors
    inFile.seekg(0); // Go to beginning of file
    for (int i = 0; i < arraySize; i++) {
        inFile >> data[i];
    }

    inFile.close();
    return true;
}

//========================
// SORTING ALGORITHMS
//========================
void DataHousing::bubbleSort(int* arrayToSort) const {
    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0; i <= arraySize - 2; i++) {
            int j = i + 1;
            if (arrayToSort[i] > arrayToSort[j]) {
                // Swap elements
                int temp = arrayToSort[j];
                arrayToSort[j] = arrayToSort[i];
                arrayToSort[i] = temp;
                swap = true;
            }
        }
    }
}

void DataHousing::selectionSort(int* arrayToSort) const {
    for (int i = 0; i < arraySize - 1; i++) {
        // Find minimum element
        int currentMin = i;
        for (int j = i + 1; j < arraySize; j++) {
            if (arrayToSort[j] < arrayToSort[currentMin])
                currentMin = j;
        }
        // Swap with current position
        int tempNum = arrayToSort[i];
        arrayToSort[i] = arrayToSort[currentMin];
        arrayToSort[currentMin] = tempNum;
    }
}

void DataHousing::insertionSort(int* arrayToSort) const {
    for (int i = 1; i < arraySize; i++) {
        int j = i - 1;
        int currentValue = arrayToSort[i];
        // Shift elements right
        while (arrayToSort[j] > currentValue && j >= 0) {
            arrayToSort[j + 1] = arrayToSort[j];
            j--;
        }
        arrayToSort[j + 1] = currentValue;
    }
}

//========================
// HELPER METHODS
//========================
void DataHousing::copyArrayToTemp() {
    for (int i = 0; i < arraySize; i++) {
        tempArray[i] = data[i];
    }
}

//========================
// TESTING OPERATIONS
//========================
void DataHousing::runSortingTests() {
    // Save original data
    int* originalData = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        originalData[i] = data[i];
    }

    // Run and time bubble sort
    copyArrayToTemp();
    timer.Reset();
    timer.Start();
    bubbleSort(tempArray);
    timer.Stop();
    bubbleSortTime = timer.GetElapsedTime();

    // Restore data and run selection sort
    for (int i = 0; i < arraySize; i++) {
        data[i] = originalData[i];
    }
    copyArrayToTemp();
    timer.Reset();
    timer.Start();
    selectionSort(tempArray);
    timer.Stop();
    selectionSortTime = timer.GetElapsedTime();

    // Restore data and run insertion sort
    for (int i = 0; i < arraySize; i++) {
        data[i] = originalData[i];
    }
    copyArrayToTemp();
    timer.Reset();
    timer.Start();
    insertionSort(tempArray);
    timer.Stop();
    insertionSortTime = timer.GetElapsedTime();

    // Clean up
    delete[] originalData;
}