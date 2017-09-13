#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "MontyHall.h"


float calculateWinRate(int wins, int iterations)
{
    return ((float) wins/ (float) iterations) * 100.0f;
}
int main(int argc, char* argv[]) 
{
    int iterations = 100000;

    if(argc == 2)
    {
        try
        {
            iterations = std::stoi(argv[1], nullptr);
        }
        catch(std::exception& e)
        {
            printf("Invalid iteration, using default:%d\n", iterations);
        }
    }

    MontyHall hallSim;
    SResults results;

    hallSim.simulateMontyHall(iterations, true, results);
    printf("Results for keeping originally selected door over %d iterations [wins=%d, losses=%d, Win Rate=%f]\n", 
        iterations, results.wins, results.losses, calculateWinRate(results.wins, iterations));

    results.clear();
    hallSim.simulateMontyHall(iterations, false, results);
    printf("Results for switching originally selected door over %d iterations [wins=%d, losses=%d, Win Rate=%f]\n", 
        iterations, results.wins, results.losses, calculateWinRate(results.wins, iterations));

    return 0;
}