//========================
// MAIN.CPP (Driver)
//========================
#pragma warning(disable:6031)
#include "Datahousing.h"
#include "StopWatch.h"
#include <conio.h>
#include <windows.h>

//========================
// DISPLAY MESSAGES PROTO 
// TO AVOID REPEATING MYSELF
//========================
void displaySortResults(DataHousing& sorter, int elementCount);

int main() {
    DataHousing sorter;

    //========================
    // TEST WITH 500 ELEMENTS
    //========================
    if (sorter.readDataFromFile("NumFile500.txt")) {
        displaySortResults(sorter, 500);
    }

    //========================
    // TEST WITH 5000 ELEMENTS
    //========================
    if (sorter.readDataFromFile("NumFile5k.txt")) {
        displaySortResults(sorter, 5000);
    }

    //========================
    // TEST WITH 25000 ELEMENTS
    //========================
    if (sorter.readDataFromFile("NumFile25k.txt")) {
        displaySortResults(sorter, 25000);
    }

    //========================
    // TEST WITH 100000 ELEMENTS
    //========================
    if (sorter.readDataFromFile("NumFile100k.txt")) {
        displaySortResults(sorter, 100000);
    }

    //========================
    // EXIT
    //========================
    cout << "\nANALYSIS COMPLETE... PRESS ANY KEY TO CONTINUE." << endl;
    _getch();
    return 0;
}

//========================
// DISPLAY MESSAGES
//========================
void displaySortResults(DataHousing& sorter, int elementCount) {
    cout << "\nPopulating Arrays... (" << elementCount << " elements)" << endl;
    cout << "Sorting";

    // Animation
    for (int i = 0; i < 5; i++) {
        _putch('.');
        Sleep(1000);
    }
    sorter.runSortingTests();
    cout << "\nSORTS COMPLETE!" << endl;
    cout << "Elapsed Time (Bubble Sort)    : " << sorter.getBubbleSortTime()    << " milliseconds" << endl;
    cout << "Elapsed Time (Selection Sort) : " << sorter.getSelectionSortTime() << " milliseconds" << endl;
    cout << "Elapsed Time (Insertion Sort) : " << sorter.getInsertionSortTime() << " milliseconds" << endl;
}