#include "Date.h"
#include "Day.h"
#include "Itinerary.h"
#include <iostream>
#include <iomanip> 
#include <string> 
#include"../react.h"
using namespace std;

//itinerary obj
Itinerary::Itinerary(int offset):actCount(0){ // creates a itinerary object from what the user inputs. gets from correct location in global mem.
    string startDay;
    string startMonth;
    string startYear;
    string endDay;
    string endMonth;
    string endYear;
    plannedDays = 0;
    cerr <<plannedDays<< endl;
    destination = _global_mem + offset;
    startDay = _global_mem + offset + 25;
    startMonth = _global_mem + offset + 25 +3;
    startYear = _global_mem + offset + 25 + 3 + 3;
    endDay = _global_mem + offset + 25 + 3 + 3 + 5;
    endMonth = _global_mem + offset + 25 + 3 + 3 + 5 + 3;
    endYear =_global_mem + offset + 25 + 3 + 3 + 5 + 3 + 3;
    cerr<< getDayInt(startDay) << endl;
    cerr<< getMonthInt(startMonth) << endl;
    cerr<< getYearInt(startYear) << endl;
    cerr<< getDayInt(endDay) << endl;
    cerr<< getMonthInt(endMonth) << endl;
    cerr<< getYearInt(endYear) << endl;
    startDate =Date(getDayInt(startDay) ,getMonthInt(startMonth), getYearInt(startYear));
    endDate= Date(getDayInt(endDay),getMonthInt(endMonth),getYearInt(endYear));
    startDateStr = startDate.makeStrDate();
    endDateStr = endDate.makeStrDate();
    triplength = getTripLength( );
    cerr << destination <<endl;
    cerr << triplength <<endl;
    plannedDays = 0;
    dailyPlan = new Day*[triplength];
    for(int i=0;i<triplength; ++i){
        dailyPlan[i]=0;
    }
}

Itinerary::Itinerary(int sm,int sd,int sy, int em,int ed,int ey):startDate(sm,sd,sy), endDate(em,ed,ey),actCount(0){ // you can create your own Itinerary obj here, input dates.
    startDateStr = startDate.makeStrDate();
    endDateStr = endDate.makeStrDate();
    cerr<<startDateStr<<endl;
    triplength = getTripLength( );
    plannedDays = 0;
    dailyPlan = new Day*[triplength];
    for(int i=0;i<triplength; ++i){
        dailyPlan[i]=0;
    }
}
void Itinerary::planNewDay(){ // this will plan one day of your trip, it creates a new Day, an object of an class
        ++plannedDays;
        dailyPlan[plannedDays]= new Day;// new day object, holds the activities for a day
        bool running=1;
        cerr<<"Planning day "<<plannedDays<< "! " <<endl;
        while (running){
            std::string activity;
            cerr << "Enter Activity number ("<< actCount+1<< ") for day " << plannedDays << ":";
            cin >> activity;
            dailyPlan[plannedDays]->addActivity(activity);
            int yes=0;
            cerr << "add another activity? Yes(1)/No(0): ";
            cin >> yes;
            if (yes==0){
                running=0;
            }
            ++actCount;    
        }
  }
  
int countLeapYears(int m, int y ){  
     int years = y;
    if (m <= 2){
        years--;
        }
    return years / 4 - years / 100 + years / 400;
}

int Itinerary::getTripLength(){//gets the trip length 
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

Day& Itinerary:: operator[](int i) { // used to view certain days, you can see the activites in that speciifc day.
        if((i-1)< 0) {
            std::cerr << "warning not a vaild index" << std::endl; 
            dailyPlan[0]->display();
    }
    
        else if (i > triplength) {
            std::cerr << "warning not a vaild index" << std::endl; 
        }
         return *(dailyPlan[i]);
    }



void Itinerary::put_in_global_mem(int offset) { // server puts information into global mem,(an itinerary obj)
    int len_dest = destination.length()+1;
    int len_startDateStr = startDateStr.length()+1;
    int len_endDateStr = endDateStr.length()+1;
    _put_raw(offset+4, destination.c_str());
    _put_raw(offset+4+ len_dest, startDateStr.c_str());
    _put_raw(offset+4+ len_dest+ len_startDateStr ,endDateStr.c_str());
    _put_int(offset+4+ len_dest+ len_startDateStr+len_endDateStr,triplength);
    _put_int(offset+4+len_dest+ len_startDateStr+len_endDateStr+triplength, actCount);
    int setOff= 0;
    for(int i = 0; i< triplength; ++i){
        for(int j=0; j< 4;++j){
            setOff+=20;
            _put_raw(offset+4+ len_dest+ len_startDateStr + len_endDateStr + triplength+ actCount +setOff, (dailyPlan[i]->getActivity(j)).c_str());
        }
    }
    gm_size = 4 + len_dest + len_startDateStr + len_endDateStr + triplength + actCount;
    _put_int(offset, gm_size);
}

void Itinerary::get_activities_from_global_mem(){ // this gets all the activites a user enters on react 
    cerr<< "testing we hit function  next print shoudl be 1" <<endl;
    //++plannedDays;
     cerr << plannedDays <<endl;
     cerr<<"Planning day "<<plannedDays+1<< "! " <<endl;
    //dailyPlan[plannedDays]= new Day;
    int offset= 2000;
    for(int i=0; i< triplength; ++i){
        dailyPlan[plannedDays]= new Day;
        for(int j=0; j<4; ++j){
                string activity = _global_mem +offset;
                cerr << activity <<endl;
                dailyPlan[plannedDays]->addActivity(activity);
                offset +=40;

        }
        ++plannedDays;
    }
  
    dailyPlan[1]->display();
}

void Itinerary::get_from_global_mem(int offset) { // this is used to get objects from global mem. 
    cerr<< "test"<< endl;
    gm_size = _get_int(offset);
    destination = _global_mem+offset+4;
    int len_dest = destination.length()+1;
    startDateStr = _global_mem + offset + 4 + len_dest;
    int len_startDate = startDateStr.length()+1;
    endDateStr = _global_mem + offset+4+ len_dest+ len_startDate;
    int len_endDate = endDateStr.length()+1;
    triplength = _get_int(offset+4+ len_dest+ len_startDate+len_endDate);
    actCount = _get_int(offset+4+len_dest+ len_startDate+len_endDate+triplength);
    cerr << actCount << endl;
    string test = _global_mem +offset+4+len_dest+ len_startDate+len_endDate+triplength+ actCount+50;
    cerr << test << endl;
    string activities[actCount];
    cerr<< "test" <<endl;
    int setOff = 0;
    for(int i=0; i<actCount; ++i){
        setOff+=50;
        activities[i] = _global_mem +offset+4+len_dest+ len_startDate+len_endDate+triplength+ actCount+setOff;
    }
     cerr << destination << endl;
      cerr << startDateStr << endl;
       cerr << endDateStr << endl;
    cerr << triplength << endl;
    cerr << actCount << endl;
    for(int i=0; i<actCount; ++i){
    cerr << activities[i] << endl;
    }    
}




//below are conversions for react. 
int Itinerary::getDayInt(string day) {
    int dayInt;
    stringstream ss;
    ss << day;
    ss >> dayInt;
    return dayInt;
}

int Itinerary::getMonthInt(string month) {
    int monthInt;
    stringstream ss;
    ss << month;
    ss >> monthInt;
    return monthInt;
}

int Itinerary::getYearInt(string year) {
    int yearInt;
    stringstream ss;
    ss << year;
    ss >> yearInt;
    return yearInt;
}

string Itinerary::InttoStr(int as) {
    string numstr;
    stringstream ss;
    ss << as;
    ss >> numstr;
    return numstr;

}

int Itinerary::StrtoInt(string as) {
    int numstr;
    stringstream ss;
    ss << as;
    ss >> numstr;
    return numstr;

}





