#ifndef AG_H
#define AG_H
#include <iostream>
#include <vector>

#include "types.h"

class AG
{
    std::vector <CHROMOSON> m_chromosonVector;
    CHROMOSON bestChromo;
    unsigned int bestChromo_generation = 0;

    unsigned int max = 0;
    unsigned int min = 0;
    std::vector<CHROMOSON>::iterator maxPos ;
    std::vector<CHROMOSON>::iterator minPos ;

public:
    AG();
    ~AG();

    int getRandom(unsigned int from, unsigned int to);
    int getRandom(unsigned int to);
    void insertChromoson(CHROMOSON ch);
    int getVecotrSize();

    void deleteWorst(unsigned int iteration);
    void mutation();
    void mutationOX();
    void printBest();
    void init();

};

#endif // AG_H
