//
// Created by Maxi on 07.08.2021.
//

#ifndef CODING_QUESTION_TIMER_H
#define CODING_QUESTION_TIMER_H

#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class Timer {
public:
    Timer() = default;

    void startTimer();


    void endTimer();

    long gettime();
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;


};


#endif //CODING_QUESTION_TIMER_H
