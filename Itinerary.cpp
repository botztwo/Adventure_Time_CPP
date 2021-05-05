#include "Date.h"
#include "Day.h"
#include "Itinerary.h"
#include <iostream>
#include <iomanip> 
#include <string> 
using namespace std;


Itinerary::Itinerary(int sm,int sd,int sy, int em,int ed,int ey):startDate(sm,sd,sy), endDate(em,ed,ey){
    triplength = getTripLength( );
    int plannedDays = 1;
    // cout << triplength << endl;
    dailyPlan = new Day*[triplength];
    for(int i=0;i<triplength; ++i){
        dailyPlan[i]=0;
    }
}

void Itinerary::planNewDay(){ // this method in incomplete used for testing purposes. //Maybe you should just do this for one day(save the day) call function every tiem add new day. 
    for(int i=0; i<triplength; ++i){
        dailyPlan[i]= new Day;
        bool running=1;
        int actCount =1;
        plannedDays +=i;
        while (running){
            std::string activity;
            cout << "Enter Activity number ("<< actCount<< ") for day " << plannedDays << ":";
            cin >> activity;
            dailyPlan[i]->addActivity(activity);// stopped here this is test code 
            int yes=0;
            cout << "add another activity? Yes(1)/No(0): ";
            cin >> yes;
            if (yes==0){
                running=0;
            }
            ++actCount;
    }
    displayDayPlan(i);
    }
}

                     //dailyPlan[i]->display();}
    
    

int countLeapYears(int m, int y ){  
     int years = y;
    if (m <= 2){
        years--;
        }
    return years / 4 - years / 100 + years / 400;
}

int Itinerary::getTripLength( ){// all days(year * 365) + day of month + month + leap days added on
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

void Itinerary::displayDayPlan(int i){

cout<< "Day "<< i+1 << " schedule"<< endl;
dailyPlan[i]->display();

}