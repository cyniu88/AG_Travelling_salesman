#include <algorithm>
#include <iostream>

#include "ag.h"

std::vector <CITY_AND_DISTANCE> genereteCityMap()
{
    std::vector <CITY_AND_DISTANCE> mapsOfCity;
    CITY_AND_DISTANCE cityA(CITY::A);
    CITY_AND_DISTANCE cityB(CITY::B);
    CITY_AND_DISTANCE cityC(CITY::C);
    CITY_AND_DISTANCE cityD(CITY::D);
    CITY_AND_DISTANCE cityE(CITY::E);
    CITY_AND_DISTANCE cityF(CITY::F);
    CITY_AND_DISTANCE cityG(CITY::G);
    CITY_AND_DISTANCE cityH(CITY::H);
    CITY_AND_DISTANCE cityI(CITY::I);
    CITY_AND_DISTANCE cityJ(CITY::J);

    cityA.setDistance(CITY::B, 10);
    cityA.setDistance(CITY::C, 13);
    cityA.setDistance(CITY::D, 29);
    cityA.setDistance(CITY::E, 100);
    cityA.setDistance(CITY::F, 60);
    cityA.setDistance(CITY::G, 143);
    cityA.setDistance(CITY::H, 189);
    cityA.setDistance(CITY::I, 400);
    cityA.setDistance(CITY::J, 256);

    cityB.setDistance(CITY::A, 10);
    cityB.setDistance(CITY::C, 33);
    cityB.setDistance(CITY::D, 234);
    cityB.setDistance(CITY::E, 14);
    cityB.setDistance(CITY::F, 565);
    cityB.setDistance(CITY::G, 133);
    cityB.setDistance(CITY::H, 177);
    cityB.setDistance(CITY::I, 345);
    cityB.setDistance(CITY::J, 156);

    cityC.setDistance(CITY::A, 10);
    cityC.setDistance(CITY::B, 33);
    cityC.setDistance(CITY::D, 55);
    cityC.setDistance(CITY::E, 120);
    cityC.setDistance(CITY::F, 44);
    cityC.setDistance(CITY::G, 133);
    cityC.setDistance(CITY::H, 159);
    cityC.setDistance(CITY::I, 410);
    cityC.setDistance(CITY::J, 206);

    cityD.setDistance(CITY::A, 29);
    cityD.setDistance(CITY::B, 234);
    cityD.setDistance(CITY::C, 55);
    cityD.setDistance(CITY::E, 100);
    cityD.setDistance(CITY::F, 60);
    cityD.setDistance(CITY::G, 103);
    cityD.setDistance(CITY::H, 179);
    cityD.setDistance(CITY::I, 110);
    cityD.setDistance(CITY::J, 156);

    cityE.setDistance(CITY::A, 100);
    cityE.setDistance(CITY::B, 14);
    cityE.setDistance(CITY::C, 120);
    cityE.setDistance(CITY::D, 100);
    cityE.setDistance(CITY::F, 60);
    cityE.setDistance(CITY::G, 143);
    cityE.setDistance(CITY::H, 189);
    cityE.setDistance(CITY::I, 200);
    cityE.setDistance(CITY::J, 69);

    cityF.setDistance(CITY::A, 60);
    cityF.setDistance(CITY::B, 565);
    cityF.setDistance(CITY::C, 44);
    cityF.setDistance(CITY::D, 60);
    cityF.setDistance(CITY::E, 60);
    cityF.setDistance(CITY::G, 143);
    cityF.setDistance(CITY::H, 189);
    cityF.setDistance(CITY::I, 20);
    cityF.setDistance(CITY::J, 79);

    cityG.setDistance(CITY::A, 143);
    cityG.setDistance(CITY::B, 133);
    cityG.setDistance(CITY::C, 133);
    cityG.setDistance(CITY::D, 103);
    cityG.setDistance(CITY::E, 143);
    cityG.setDistance(CITY::F, 143);
    cityG.setDistance(CITY::H, 90);
    cityG.setDistance(CITY::I, 150);
    cityG.setDistance(CITY::J, 100);

    cityH.setDistance(CITY::A, 189);
    cityH.setDistance(CITY::B, 177);
    cityH.setDistance(CITY::C, 159);
    cityH.setDistance(CITY::D, 179);
    cityH.setDistance(CITY::E, 189);
    cityH.setDistance(CITY::F, 189);
    cityH.setDistance(CITY::G, 90);
    cityH.setDistance(CITY::I, 130);
    cityH.setDistance(CITY::J, 111);

    cityI.setDistance(CITY::A, 400);
    cityI.setDistance(CITY::B, 345);
    cityI.setDistance(CITY::C, 410);
    cityI.setDistance(CITY::D, 110);
    cityI.setDistance(CITY::E, 200);
    cityI.setDistance(CITY::F, 20);
    cityI.setDistance(CITY::G, 150);
    cityI.setDistance(CITY::H, 130);
    cityI.setDistance(CITY::J, 123);

    cityJ.setDistance(CITY::A, 256);
    cityJ.setDistance(CITY::B, 156);
    cityJ.setDistance(CITY::C, 206);
    cityJ.setDistance(CITY::D, 156);
    cityJ.setDistance(CITY::E, 69);
    cityJ.setDistance(CITY::F, 79);
    cityJ.setDistance(CITY::G, 100);
    cityJ.setDistance(CITY::H, 111);
    cityJ.setDistance(CITY::I, 123);

    mapsOfCity.push_back(cityA);
    mapsOfCity.push_back(cityB);
    mapsOfCity.push_back(cityC);
    mapsOfCity.push_back(cityD);
    mapsOfCity.push_back(cityE);
    mapsOfCity.push_back(cityF);
    mapsOfCity.push_back(cityG);
    mapsOfCity.push_back(cityH);
    mapsOfCity.push_back(cityI);
    mapsOfCity.push_back(cityJ);

    return mapsOfCity;
}


int main()
{

    std::vector <CITY_AND_DISTANCE> mapsOfCity = genereteCityMap();

    CHROMOSON ch1;
    ch1.list = mapsOfCity;
    std::random_shuffle(ch1.list.begin(), ch1.list.end());
    ch1.print();
    ch1.printDistance();
    CHROMOSON ch2;
    ch2.list = mapsOfCity;
    std::random_shuffle(ch2.list.begin(), ch2.list.end());
    ch2.print();
    ch2.printDistance();
    CHROMOSON ch3;
    ch3.list = mapsOfCity;
    std::random_shuffle(ch3.list.begin(), ch3.list.end());
    ch3.print();
    ch3.printDistance();
    CHROMOSON ch4;
    ch4.list = mapsOfCity;
    std::random_shuffle(ch4.list.begin(), ch4.list.end());
    ch4.print();
    ch4.printDistance();
    CHROMOSON ch5;
    ch5.list = mapsOfCity;
    std::random_shuffle(ch5.list.begin(), ch5.list.end());
    ch5.print();
    ch5.printDistance();
    CHROMOSON ch6;
    ch6.list = mapsOfCity;
    std::random_shuffle(ch6.list.begin(), ch6.list.end());
    ch6.print();
    ch6.printDistance();
    CHROMOSON ch7;
    ch7.list = mapsOfCity;
    std::random_shuffle(ch7.list.begin(), ch7.list.end());
    ch7.print();
    ch7.printDistance();
    CHROMOSON ch8;
    ch8.list = mapsOfCity;
    std::random_shuffle(ch8.list.begin(), ch8.list.end());
    ch8.print();
    ch8.printDistance();

    AG traveler;

    traveler.insertChromoson(ch1);
    traveler.insertChromoson(ch2);
    traveler.insertChromoson(ch3);
    traveler.insertChromoson(ch4);
    traveler.insertChromoson(ch5);
    traveler.insertChromoson(ch6);
    traveler.insertChromoson(ch7);
    traveler.insertChromoson(ch8);


    std::cout << "vektor size przed usunieciem: " << traveler.getVecotrSize()<< std::endl;
    traveler.deleteWorst(1);
    traveler.mutation();
    std::cout << "vektor size po usunieciu: " << traveler.getVecotrSize()<< std::endl;

    traveler.printBest();
    return 0;
}
