#ifndef _Itinerary_H_
#define _Itinerary_H_
#include "Date.h"
#include "Day.h"
#include <iostream>
#include <iomanip> 
#include <cstring>
#include "../react.h"
#include <sstream>
using namespace std;


class Itinerary{
  // string destination;
    /*string startDateStr;
    string endDateStr;*/
    Date startDate;
    Date endDate;
    Day**dailyPlan;
    //int plannedDays;
    int gm_size;
    const char *tempDest;
    //int actCount;
   
    public:
    int triplength;
    string destination;
    string startDateStr;
    string endDateStr;
     int plannedDays;
     int actCount;
    Itinerary(int sm,int sd,int sy, int em,int ed,int ey); 
    Itinerary(int offset);
    int getTripLength();
    void planNewDay();
    Day& operator[](int i);
    void getDay(int i);
    void put_in_global_mem(int offset);
    void get_from_global_mem(int offset);
    void get_and_start_trip(int offset);
    int getDayInt(string day);
    int getMonthInt(string month);
    int getYearInt(string year);
    string InttoStr(int as);
    void get_activities_from_global_mem();
    int StrtoInt(string as);
    void put_strings_in_global_mem(int offset);
};
#endif

