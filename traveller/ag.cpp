#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <thread>

#include "ag.h"
#include "types.h"
#include <unistd.h>

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
    std::srand(time(NULL));

    /* generate secret number between 1 and 10: */
    return std::rand() % to + from;
}

int AG::getRandom(unsigned int to)
{
    return getRandom(0,to);
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
    max = 0;
    min = m_chromosonVector.at(0).distance();
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
    std::cout << "GENERACJA: "<<iteration << std::endl;
    std::cout << "usunieta sciezka: " ;
    maxPos->print();
    std::cout << max<< std::endl;

    std::cout << "najlepsza trasa ma " << min << "km - ";
    minPos->print();
    std::cout << std::endl <<bestChromo.distance() << " : "<< minPos->distance()<< std::endl;

    if (bestChromo.distance() > minPos->distance()){
        std::cout  << "przypisuje " << minPos->distance()<< std::endl;
        bestChromo.list = minPos->list;
        bestChromo_generation = iteration;
    }

    m_chromosonVector.erase(maxPos);
}

void AG::mutation()
{
    int m_sleep = 500000;
    int randomNumberPath = getRandom(m_chromosonVector.size()-1);
    std::this_thread::sleep_for(std::chrono::microseconds(m_sleep));
    int randomNumberElement1 = getRandom(m_chromosonVector.at(0).list.size()-1);
    std::this_thread::sleep_for(std::chrono::microseconds(m_sleep));
    int randomNumberElement2 = getRandom(m_chromosonVector.at(0).list.size()-1);
    while (randomNumberElement1 == randomNumberElement2){
        randomNumberElement2 = getRandom(m_chromosonVector.at(0).list.size()-1);
    }
    std::cout << "mutujemy " << randomNumberPath <<" sciezka ";
    m_chromosonVector.at(randomNumberPath).print();
    std::cout << " element1 "<< randomNumberElement1<< std::endl;
    std::cout << " element2 "<< randomNumberElement2<< std::endl;

    CHROMOSON temp =  m_chromosonVector.at(randomNumberPath);
    temp.print();
    temp.printDistance();
    auto e1 = temp.list.at(randomNumberElement1);
    auto e2 = temp.list.at(randomNumberElement2);
    temp.list.at(randomNumberElement1) = e2;
    temp.list.at(randomNumberElement2) = e1;

    temp.print();
    temp.printDistance();

    m_chromosonVector.push_back(temp);
}

void AG::printBest()
{
    bestChromo.print();
    std::cout << "dystans : " << bestChromo.distance()<< " zapisany w generacji " << bestChromo_generation << std::endl;

}

void AG::init()
{

    bestChromo = m_chromosonVector.at(0);
}
