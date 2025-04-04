//========================
// STOPWATCH.H
//========================
#ifndef STOPWATCH_H
#define STOPWATCH_H

//========================
// INCLUDES
//========================
#include <iostream>
#include <time.h>
using namespace std;

//========================
// STOPWATCH CLASS
//========================
class StopWatch {
private:
    clock_t startTime;  // Holds start time of timer
    clock_t endTime;    // Holds end time of timer
    bool isTicking;     // Tracks if timer is running

public:
    // Core Operations
    StopWatch();                    // Constructor to initialize timer
    bool Start();                   // Start the timer
    bool Stop();                    // Stop the timer
    bool Reset();                   // Reset timer to initial state
    bool IsTicking() const;         // Check if timer is running
    void DisplayTimerInfo() const;  // Display current timer info
    double GetElapsedTime() const;  // Calculate elapsed time
};
#endif