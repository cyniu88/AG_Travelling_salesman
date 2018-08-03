#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <thread>
#include <algorithm>

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
    std::cout << std::endl << bestChromo.distance() << " : "<< minPos->distance()<< std::endl;

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

void AG::mutationOX()
{
    std::cout << " ---------------------------------------------- " << std::endl;
    CHROMOSON father, child;
    int m_sleep = 500000;
    int randomNumberPath = getRandom(m_chromosonVector.size()-1);
    std::this_thread::sleep_for(std::chrono::microseconds(m_sleep));
    int randomNumberElement1 = getRandom(m_chromosonVector.at(0).list.size()-1);
    std::this_thread::sleep_for(std::chrono::microseconds(m_sleep));
    int randomNumberElement2 = getRandom(m_chromosonVector.at(0).list.size()-1);
    while (randomNumberElement1 == randomNumberElement2){
        randomNumberElement2 = getRandom(m_chromosonVector.at(0).list.size()-1);
    }


    if (randomNumberElement1 > randomNumberElement2){
        int temp = randomNumberElement1;
        randomNumberElement1 = randomNumberElement2;
        randomNumberElement2 = temp;
    }

//    randomNumberElement1 = 0;
//    randomNumberElement2 = 5;
    std::cout << " od " << randomNumberElement1 << " do " << randomNumberElement2 << std::endl;

    father =  m_chromosonVector.at(randomNumberPath);


//    for (int i = randomNumberElement1 ; i < randomNumberElement2 ; ++i)
//    {
//        std::cout << "subvector father " << father.cityEnumToString(father.list.at(i).cityName)<<std::endl;
//    }
    child = father;

    //    auto temp = father.list.at(randomNumberElement);
    //    child.list.at(randomNumberElement) = father.list.at(randomNumberElement);

    //    std::vector<CITY_AND_DISTANCE>::iterator pos = std::find(std::begin(mother.list), std::end(mother.list), temp);
    //    int posInt = std::distance( mother.list.begin(), pos ) ;
    //    std::cout << " w mamie " << child.cityEnumToString(temp.cityName)
    //              << " jest na pozycji " << posInt<< std::endl;



    CHROMOSON temp;

    for ( int i = 0 ; i < randomNumberElement1; ++i)
    {
        temp.list.push_back(father.list.at(i));
    }
    for ( int i = randomNumberElement2 ; i < father.list.size(); ++i)
    {
        temp.list.push_back(father.list.at(i));
    }

    //    for (auto it : temp.list)
    //    {
    //        std::cout << "subvector1 " << father.cityEnumToString(it.cityName)<<std::endl;
    //    }

    std::random_shuffle(temp.list.begin(), temp.list.end());


//    for (auto it : temp.list)
//    {
//        std::cout << "subvector1 " << father.cityEnumToString(it.cityName)<<std::endl;
//    }

    for ( int i = 0 ; i < randomNumberElement1; ++i)
    {
       // std::cout <<i<< " for " << temp.cityEnumToString(temp.list.at(i).cityName) << std::endl;
        child.list.at(i) = temp.list.at(i);
    }

    //    for (int i = randomNumberElement1 ; i < randomNumberElement2 ; ++i)
    //    {
    //       child.list.push_back(father.list.at(i));
    //    }

    for ( int i = randomNumberElement2 ; i < father.list.size(); ++i)
    {
     //   std::cout  << " last " << temp.cityEnumToString(temp.list.at(i-(randomNumberElement2-randomNumberElement1)).cityName) << std::endl;
        child.list.at(i) = temp.list.at(i-(randomNumberElement2-randomNumberElement1));
    }


    std::cout << " wylosownao ojca: ";
    father.print();

    std::cout<<std::endl;

    std::cout << "         dziecko: ";
    child.print();
    std::cout << std::endl;
    std::cout << " dzieciak ma rozmiar: " << child.list.size() << std::endl;

    m_chromosonVector.push_back(child);
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
