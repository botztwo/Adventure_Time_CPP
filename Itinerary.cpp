#include "Date.h"
#include "Day.h"
#include "Itinerary.h"
#include <iostream>
#include <iomanip> 
using namespace std;


Itinerary::Itinerary(int sm,int sd,int sy, int em,int ed,int ey):startDate(sm,sd,sy), endDate(em,ed,ey){
    triplength = getTripLength( );
   // cout << triplength << endl;
    dailyPlan = new Day*[triplength];
    for(int i=0;i<triplength; ++i){
        dailyPlan[i]=0;
    }
}

void Itinerary::planDay(){ // this method in incomplete used for testing purposes. 
    int plannedDays=0;
    while(1){
    dailyPlan[plannedDays]= new Day;
    dailyPlan[plannedDays]->addActivity("ski");// stopped here this is test code 
    dailyPlan[plannedDays]->display();
    ++plannedDays;
    //p;lan until you get to trip.
    }
}

int countLeapYears(int m, int y){  
     int years = y;
    if (m <= 2){
        years--;
        }
    return years / 4 - years / 100 + years / 400;
}

int Itinerary::getTripLength(){// all days(year * 365) + day of month + month + leap days added on
    const int monthDays[12]= {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    long int n1 = startDate.getYear()* 365 + startDate.getDay();
    for (int i = 0; i < startDate.getMonth() - 1; i++){
        n1 += monthDays[i];}
    n1 += countLeapYears( startDate.getMonth(), startDate.getYear() );
   
    long int n2 = endDate.getYear() * 365 + endDate.getDay();
    for (int i = 0; i < endDate.getMonth() - 1; i++){
        n2 += monthDays[i];}
    n2 += countLeapYears(endDate.getMonth(),endDate.getYear());
    return (n2 - n1);
}