#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <map>
#include <vector>
/*
    Wroclaw	bydgoszcz	lublin	gorzow	lodz	krakow	warszawa	opole	rzeszow	bialystok	gdansk	katowice	kielce	olsztyn	poznan	szczecin
    WROCLAW 	0	234	386	219	204	268	402	86	433	532	432	199	300	442	178	371
    BYDGOSZCZ,	234	0	421	214	205	430	255	318	516	389	157	391	348	217	129	267
    LUBLIN,     386	421	0	594	284	269	161	382	170	260	500	323	167	370	465	683
GORZOW_WIELKI,	219	214	594	0	341	529	260	354	643	603	511	454	480	431	129	105
    LODZ,       204	205	284	341	0	220	134	181	306	322	340	196	143	281	212	446
    KRAKOW,     268	430	269	529	220	0	295	182	165	477	565	75	114	500	403	634
    WARSZAWA,	402	255	161	260	134	295	0	319	303	347	339	297	181	213	310	522
    OPOLE,      86	318	382	354	181	182	319	0	347	507	485	113	220	452	261	459
    RZESZOW,	433	516	170	643	306	165	303	347	0	430	642	244	163	516	517	751
    BIALYSTOK,	532	389	260	603	322	477	347	507	430	0	379	485	363	223	491	656
    GDANSK,     432	157	500	511	340	565	339	485	642	379	0	545	483	156	296	348
    KATOWICE,	199	391	323	454	196	75	297	113	244	485	545	0	156	479	335	561
    KIELCE,     300	348	167	480	143	114	181	220	163	363	483	156	0	34	354	585
    OLSZTYN,	442	217	370	431	281	500	213	452	516	223	156	479	394	0	232	484
    POZNAN,     178	129	465	129	212	403	310	261	517	491	296	335	354	232	0	234
    SZCZECIN,	371	267	683	105	446	634	522	459	751	656	348	561	585	484	234	0

 */
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

const int cityMatrix [16][16] = {
    {0,234,386,219,204,268,402,86,433,532,432,199,300,442,178,371},
    {234,0,421,214,205,430,255,318,516,389,157,391,348,217,129,267},
    {386,421,0,594,284,269,161,382,170,260,500,323,167,370,465,683},
    {219,214,594,0,341,529,260,354,643,603,511,454,480,431,129,105},
    {204,205,284,341,0,220,134,181,306,322,340,196,143,281,212,446},
    {268,430,269,529,220,0,295,182,165,477,565,75,114,500,403,634},
    {402,255,161,260,134,295,0,319,303,347,339,297,181,213,310,522},
    {86,318,382,354,181,182,319,0,347,507,485,113,220,452,261,459},
    {433,516,170,643,306,165,303,347,0,430,642,244,163,516,517,751},
    {532,389,260,603,322,477,347,507,430,0,379,485,363,223,491,656},
    {432,157,500,511,340,565,339,485,642,379,0,545,483,156,296,348},
    {199,391,323,454,196,75,297,113,244,485,545,0,156,479,335,561},
    {300,348,167,480,143,114,181,220,163,363,483,156,0,34,354,585},
    {442,217,370,431,281,500,213,452,516,223,156,479,394,0,232,484},
    {178,129,465,129,212,403,310,261,517,491,296,335,354,232,0,234},
    {371,267,683,105,446,634,522,459,751,656,348,561,585,484,234,0}
};

struct CHROMOSON
{
    unsigned int generation = 0;
    std::vector <CITY> list;
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
            std::cout << cityEnumToString(n) << "-";
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
            for(unsigned int it = 0; it < list.size()-1; ++it)
            {
                int i = list.at(it);
                int j = list.at(it+1);
                dist += cityMatrix[i][j];
            }
        }
        return dist;
    }
};



#endif // TYPES_H
