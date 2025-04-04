//========================
// STOPWATCH.CPP
//========================
#include "StopWatch.h"

//========================
// CONSTRUCTOR
//========================
StopWatch::StopWatch() {
    startTime = 0;
    endTime   = 0;
    isTicking = false;
}

//========================
// TIMER OPERATIONS
//========================
// Start timer if not already running
bool StopWatch::Start() {
    if (isTicking) {
        return false;
    }
    startTime = clock();
    isTicking = true;
    return true;
}

// Stop timer if currently running
bool StopWatch::Stop() {
    if (!isTicking) {
        return false;
    }
    endTime = clock();
    isTicking = false;
    return true;
}

// Reset all timer values
bool StopWatch::Reset() {
    startTime = 0;
    endTime = 0;
    isTicking = false;
    return true;
}

// Check timer status
bool StopWatch::IsTicking() const {
    return isTicking;
}

//========================
// TIME CALCULATIONS
//========================
// Calculate and return elapsed time
double StopWatch::GetElapsedTime() const {
    if (isTicking) {
        return double(clock() - startTime);  // Current time if running
    }
    return double(endTime - startTime);      // Final time if stopped
}

// Display timer information
void StopWatch::DisplayTimerInfo() const {
    double elapsedTime = GetElapsedTime();
    cout << "Elapsed time: " << elapsedTime << " milliseconds";
}