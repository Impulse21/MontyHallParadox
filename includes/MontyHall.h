#ifndef MONTY_HALL_H
#define MONTY_HALL_H

struct SResults
{
    int wins;
    int losses;

    SResults()
    {
        clear();
    }

    void clear()
    {
        wins = 0;
        losses = 0;
    }
};

class MontyHall
{
public:
    MontyHall() {};

    void simulateMontyHall(int iterations, bool chooseSameDoor, SResults& results);

private:
    int otherDoor(int doorA, int doorB);
};

#endif //MONTY_HALL_H
