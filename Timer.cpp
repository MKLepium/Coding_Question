//
// Created by Maxi on 07.08.2021.
//

#include "Timer.h"


void Timer::startTimer() {
    this->start_time = std::chrono::high_resolution_clock::now();

}

void Timer::endTimer() {
    this->end_time = std::chrono::high_resolution_clock::now();
}

long Timer::gettime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(this->end_time - this->start_time).count();
}
