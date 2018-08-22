#include <algorithm>
#include <iostream>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "ag.h"

int myrandom (int i) { return std::rand()%i;}

int main()
{
    std::srand ( unsigned ( std::time(0) ) );

    std::vector<CITY> orginal;
    orginal.push_back(CITY::BIALYSTOK);
    orginal.push_back(CITY::BYDGOSZCZ);
    orginal.push_back(CITY::GDANSK);
    orginal.push_back(CITY::GORZOW_WIELKOPOLSKI);
    orginal.push_back(CITY::KATOWICE);
    orginal.push_back(CITY::KIELCE);
    orginal.push_back(CITY::KRAKOW);
    orginal.push_back(CITY::LODZ);
    orginal.push_back(CITY::LUBLIN);
    orginal.push_back(CITY::OLSZTYN);
    orginal.push_back(CITY::OPOLE);
    orginal.push_back(CITY::POZNAN);
    orginal.push_back(CITY::RZESZOW);
    orginal.push_back(CITY::SZCZECIN);
    orginal.push_back(CITY::WARSZAWA);
    orginal.push_back(CITY::WROCLAW);

    CHROMOSON ch1;
    ch1.list = orginal;
    std::random_shuffle(ch1.list.begin(), ch1.list.end(), myrandom);
    ch1.print();
    ch1.printDistance();
    CHROMOSON ch2;
    ch2.list = orginal;
    std::random_shuffle(ch2.list.begin(), ch2.list.end(), myrandom);
    ch2.print();
    ch2.printDistance();
    CHROMOSON ch3;
    ch3.list = orginal;
    std::random_shuffle(ch3.list.begin(), ch3.list.end(), myrandom);
    ch3.print();
    ch3.printDistance();
    CHROMOSON ch4;
    ch4.list = orginal;
    std::random_shuffle(ch4.list.begin(), ch4.list.end(), myrandom);
    ch4.print();
    ch4.printDistance();
    CHROMOSON ch5;
    ch5.list = orginal;
    std::random_shuffle(ch5.list.begin(), ch5.list.end(), myrandom);
    ch5.print();
    ch5.printDistance();
    CHROMOSON ch6;
    ch6.list = orginal;
    std::random_shuffle(ch6.list.begin(), ch6.list.end(), myrandom);
    ch6.print();
    ch6.printDistance();
    CHROMOSON ch7;
    ch7.list = orginal;
    std::random_shuffle(ch7.list.begin(), ch7.list.end(), myrandom);
    ch7.print();
    ch7.printDistance();
    CHROMOSON ch8;
    ch8.list = orginal;
    std::random_shuffle(ch8.list.begin(), ch8.list.end(), myrandom);
    ch8.print();
    ch8.printDistance();


    // return 0;
    AG traveler;

    traveler.insertChromoson(ch1);
    traveler.insertChromoson(ch2);
    traveler.insertChromoson(ch3);
    traveler.insertChromoson(ch4);
    traveler.insertChromoson(ch5);
    traveler.insertChromoson(ch6);
    traveler.insertChromoson(ch7);
    traveler.insertChromoson(ch8);


    traveler.init();

    std::cout << "vektor size przed usunieciem: " << traveler.getVecotrSize()<< std::endl;
    for ( int i = 1 ; i < 20000; ++i)
    {
        traveler.deleteWorst(i);
        //traveler.deleteBest(i);
        //traveler.mutation();
        traveler.mutationOX();
    }

    std::cout << "vektor size po usunieciu: " << traveler.getVecotrSize()<< std::endl;
    std::cout << " -----------------------------------------------------------" << std::endl;
    traveler.printBest();

    return 0;
}
