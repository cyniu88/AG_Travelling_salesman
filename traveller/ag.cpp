#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "ag.h"
#include "types.h"

AG::AG()
{
    std::cout << "AG::AG()"<< std::endl;
}

AG::~AG()
{
    std::cout << "AG::~AG()"<< std::endl;
}

int AG::getRandom(unsigned int from, unsigned int to)
{
    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    return rand() % to + from;
}

int AG::getRandom(unsigned int to)
{
    return getRandom(1,to);
}

void AG::insertChromoson(CHROMOSON ch)
{
    m_chromosonVector.push_back(ch);
}

int AG::getVecotrSize()
{
    return m_chromosonVector.size();
}

void AG::deleteWorst(unsigned int iteration)
{
    min = m_chromosonVector.at(0).distance();
    bestChromo = m_chromosonVector.at(0);
    for(std::vector<CHROMOSON>::iterator it = m_chromosonVector.begin(); it != m_chromosonVector.end(); ++it) {
        unsigned int m_d = it->distance();
        std::cout << "dystans: " << m_d << std::endl;
        if (m_d > max){
            max = m_d;
            maxPos = it;
        }
        if(m_d < min){
            min = m_d;
            minPos = it;
        }
    }
    std::cout << "usunieta sciezka: " ;
    maxPos->print();
    std::cout << max<< std::endl;

    std::cout << "najlepsza trasa ma " << min << "km - ";
    minPos->print();
    std::cout << std::endl <<bestChromo.distance() << " : "<< minPos->distance()<< std::endl;

    if (bestChromo.distance() > minPos->distance()){
        bestChromo = *minPos;
        bestChromo_generation = iteration;
    }

    m_chromosonVector.erase(maxPos);
}

void AG::mutation()
{
    int randomNumber = getRandom(m_chromosonVector.size());
    std::cout << "mutujemy " << randomNumber <<" sciezka ";
    m_chromosonVector.at(randomNumber).print();
    std::cout << std::endl;

}

void AG::printBest()
{
    bestChromo.print();
    std::cout << "dystans : " << bestChromo.distance()<< " zapisany w generacji " << bestChromo_generation << std::endl;

}
