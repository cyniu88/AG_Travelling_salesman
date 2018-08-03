#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <map>
#include <vector>


enum CITY{
    A=1,
    B,C,D,E,F,G,H,I,J
};

struct CITY_AND_DISTANCE{
    CITY_AND_DISTANCE(CITY name){
        cityName = name;
    }
    CITY cityName;
    std::map <CITY, unsigned int> distanceMap;
    void setDistance(CITY c, unsigned int d)
    {
        if(c == cityName) return;
        distanceMap[c] = d;
    }

    unsigned int getDistance(CITY name){
        return distanceMap[name];
    }
    bool operator ==( const CITY_AND_DISTANCE & v )
    {
        if( this->cityName == v.cityName )
             return true;
        else
             return false;

    }
};

struct CHROMOSON
{
    unsigned int generation = 0;
    std::vector <CITY_AND_DISTANCE> list;
    CHROMOSON& operator=(const CHROMOSON& other) // copy assignment
    {
        if (this != &other) {
            this->generation = other.generation;
            this->list = other.list;
        }
    return *this;
    }
    void print(){
        for(auto n : list)
        {
            std::cout << cityEnumToString(n.cityName) << "-";
        }
        std::cout << "    ";
    }
    void printDistance(){
        std::cout  << distance()<<std::endl;
    }
    std::string cityEnumToString(CITY e){
        switch (e){
        case  CITY::A:                return "A";
        case  CITY::B:                return "B";
        case  CITY::C:                return "C";
        case  CITY::D:                return "D";
        case  CITY::E:                return "E";
        case  CITY::F:                return "F";
        case  CITY::G:                return "G";
        case  CITY::H:                return "H";
        case  CITY::I:                return "I";
        case  CITY::J:                return "J";
        }
    }

    unsigned int distance(){
        unsigned int dist = 0;
        if (list.empty() == false)
        {
            for(std::vector<CITY_AND_DISTANCE>::iterator it = list.begin(); it != list.end()-1; ++it) {
                dist += it->getDistance((it+1)->cityName);
            }
        }
        return dist;
    }
};



#endif // TYPES_H
