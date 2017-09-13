#include "MontyHall.h"
#include <random>
#include <string>

void MontyHall::simulateMontyHall(int iterations, bool chooseSameDoor, SResults& results)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distributor(1,3);
    
    auto doorSelector = std::bind(distributor, gen);
    
    for(auto i = 0; i < iterations; i++)
    {
        const auto winningDoor = doorSelector();
        
        const auto orignalDoor = doorSelector();
        
        const auto openDoor = otherDoor(winningDoor, orignalDoor);
        
        const auto selectedDoor = chooseSameDoor ?
        orignalDoor : otherDoor(orignalDoor, openDoor);
        
        if(winningDoor == selectedDoor)
        {
            results.wins++;
        }
        else
        {
            results.losses++;
        }
    }
}

int MontyHall::otherDoor(int doorA, int doorB)
{
    int doorC = 1;
    if(doorA == doorB)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distributor(1,2);
        
        doorC = distributor(gen);
        
        if(doorC == doorA)
        {
            doorC++;
        }
    }
    else
    {
        while(doorC == doorA || doorC == doorB)
        {
            doorC++;
        }
    }
    
    return doorC;
}
