#ifndef _Itinerary_H_
#define _Itinerary_H_
#include "Date.h"
#include "Day.h"
#include <iostream>
#include <iomanip> 
using namespace std;


class Itinerary{
    Date startDate;
    Date endDate;
    int triplength;
    Day**dailyPlan;
    int plannedDays;


    public:
    Itinerary(int sm,int sd,int sy, int em,int ed,int ey); 
    int getTripLength();
    void planNewDay();
    void displayDayPlan(int i);
    Day& operator[](int i);
    void getDay(int i);

};
#endif

