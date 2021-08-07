#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include "Timer.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;




/*
 * Given two arrays of integers and a target value, write a function to return true
 *    if there is a combination of integers in the given arrays so the sum of these integers
 *    is the target value
 */

/*
 * Just brute force the two vectors, bad time complexity (O(n^2))
 */
bool sumOfTwo_intuitive(std::vector<int> a, std::vector<int> b, int target_value);

/*
 * Just brute force the two vectors, bad time complexity (O(n^2)), but only one calculation per elements in a
 */
bool sumOfTwo_complementFirst(std::vector<int> a, std::vector<int> b, int target_value);

/*
 * Trading bad time complexity for space complexity, worst case time complexity (O(n+n))
 */
bool sumOfTwo_complementFirst_Hash(std::vector<int> a, std::vector<int> b, int target_value);

void print_average(std::vector<long> a);

int main() {
    Timer t;

    std::cout << std::endl  << "First, Intuitive: " << std::endl;
    std::cout << "sumOfTwo_intuitive" << std::endl;

    int how_often = 100;
    std::vector<long> time;
    for(int i = 0; i < how_often; i++)
    {
        t.startTimer();
        {
            std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
            std::vector<int> b = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
            int target_value = 116;

            bool return_value = sumOfTwo_intuitive(a, b, target_value);
            //std::cout << return_value << std::endl;

            a = {0, 0, -5, 30212};
            b = {-10, 40, -3, 9};
            target_value = -8;

            return_value = sumOfTwo_intuitive(a, b, target_value);
            //std::cout << return_value << std::endl;
        }
        t.endTimer();
        time.push_back(t.gettime());
    }
    print_average(time);
    time.clear();




    std::cout << std::endl << "Second, A little better: " << std::endl;
    std::cout << "sumOfTwo_complementFirst " << std::endl;
    for(int i = 0; i < how_often; i++)
    {
        t.startTimer();
        {
            std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
            std::vector<int> b = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
            int target_value = 116;


            bool return_value = sumOfTwo_complementFirst(a, b, target_value);
            //std::cout << return_value << std::endl;

            a = {0, 0, -5, 30212};
            b = {-10, 40, -3, 9};
            target_value = -8;

            return_value = sumOfTwo_complementFirst(a, b, target_value);
            //std::cout << return_value << std::endl;
        }
        t.endTimer();
        time.push_back(t.gettime());
    }
    print_average(time);
    time.clear();


    std::cout << std::endl  << "Third, HashSet calculation first: " << std::endl;
    std::cout << "sumOfTwo_complementFirst_Hash" << std::endl;

    for(int i = 0; i < how_often; i++)
    {
        t.startTimer();
        {
            std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
            std::vector<int> b = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
            int target_value = 116;


            bool return_value = sumOfTwo_complementFirst_Hash(a, b, target_value);
            //std::cout << return_value << std::endl;

            a = {0, 0, -5, 30212};
            b = {-10, 40, -3, 9};
            target_value = -8;

            return_value = sumOfTwo_complementFirst_Hash(a, b, target_value);
            //std::cout << return_value << std::endl;
        }
        t.endTimer();
        time.push_back(t.gettime());
    }
    print_average(time);
    time.clear();



    return 0;
}

void print_average(std::vector<long> a)
{
    int sum = 0;
    int j = 0;
    for(auto i : a){
        sum += i;
        j++;
    }
    std::cout << "Average: " << sum/j << " nano seconds on " << j << " runs" << std::endl;
}

bool sumOfTwo_complementFirst_Hash(std::vector<int> a, std::vector<int> b, int target_value)
{
    std::unordered_set<int> set;
    for(auto i : a){
        int complement = target_value - i;
        set.insert(complement);
    }
    for(auto i : b)
    {
        if(set.contains(i)){
            return true;
        }
    }
    return false;
}

bool sumOfTwo_complementFirst(std::vector<int> a, std::vector<int> b, int target_value) {
    for(auto i : a){
        int complement = target_value - i;
        for(auto j : b)
        {
            if(complement == j){
                return true;
            }
        }
    }
    return false;
}

bool sumOfTwo_intuitive(std::vector<int> a, std::vector<int> b, int target_value) {
    for(auto i : a){
        for(auto j : b)
        {
            if(i+j == target_value){
                return true;
            }
        }
    }
    return false;
}

