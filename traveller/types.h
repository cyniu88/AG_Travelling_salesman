#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <map>
#include <vector>

enum CITY{
    WROCLAW = 0,
    BYDGOSZCZ,
    LUBLIN,
    GORZOW_WIELKOPOLSKI,
    LODZ,
    KRAKOW,
    WARSZAWA,
    OPOLE,
    RZESZOW,
    BIALYSTOK,
    GDANSK,
    KATOWICE,
    KIELCE,
    OLSZTYN,
    POZNAN,
    SZCZECIN,
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
        case  CITY::WROCLAW:                return "WROCLAW";
        case  CITY::BYDGOSZCZ:              return "BYDGOSZCZ";
        case  CITY::LUBLIN:                 return "LUBLIN";
        case  CITY::GORZOW_WIELKOPOLSKI:    return "GORZOW_WIELKOPOLSKI";
        case  CITY::LODZ:                   return "LODZ";
        case  CITY::KRAKOW:                 return "KRAKOW";
        case  CITY::WARSZAWA:               return "WARSZAWA";
        case  CITY::OPOLE:                  return "OPOLE";
        case  CITY::RZESZOW:                return "RZESZOW";
        case  CITY::BIALYSTOK:              return "BIALYSTOK";
        case  CITY::GDANSK:                 return "GDANSK";
        case  CITY::KATOWICE:               return "KATOWICE";
        case  CITY::KIELCE:                 return "KIELCE";
        case  CITY::OLSZTYN:                return "OLSZTYN";
        case  CITY::POZNAN:                 return "POZNAN";
        case  CITY::SZCZECIN:               return "SZCZECIN";
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
