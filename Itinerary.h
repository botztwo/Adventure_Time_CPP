#ifndef _Itinerary_H_
#define _Itinerary_H_
#include "Date.h"
#include "Day.h"
#include <iostream>
#include <iomanip> 
#include <cstring>
#include"../react.h"
#include <sstream>
using namespace std;


class Itinerary{
    string destination;
    Date startDate;
    Date endDate;
    string startDateStr;
    string endDateStr;
    int triplength;
    Day**dailyPlan;
    int plannedDays;
    int gm_size;
    const char *tempDest;
    int actCount;


    public:
    Itinerary(int sm,int sd,int sy, int em,int ed,int ey); 
    int getTripLength();
    void planNewDay();
    Day& operator[](int i);
    void getDay(int i);
    void put_in_global_mem(int offset);
    void get_from_global_mem(int offset);
};
#endif

