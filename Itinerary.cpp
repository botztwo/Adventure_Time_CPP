#include "Date.h"
#include "Day.h"
#include "Itinerary.h"
#include <iostream>
#include <iomanip> 
#include <string> 
#include"../react.h"
using namespace std;


Itinerary::Itinerary(int sm,int sd,int sy, int em,int ed,int ey):startDate(sm,sd,sy), endDate(em,ed,ey),actCount(0){
    startDateStr = startDate.makeStrDate();
    endDateStr = endDate.makeStrDate();
    cout<<startDateStr<<endl;
    triplength = getTripLength( );
    plannedDays = 0;
    dailyPlan = new Day*[triplength];
    for(int i=0;i<triplength; ++i){
        dailyPlan[i]=0;
    }
    cout << "Where are you headed?"<< endl; 
    getline(cin, destination);

}
void Itinerary::planNewDay(){ 
        ++plannedDays;
        dailyPlan[plannedDays]= new Day;
        bool running=1;
        cout<<"Planning day "<<plannedDays<< "! " <<endl;
        while (running){
            std::string activity;
            cout << "Enter Activity number ("<< actCount+1<< ") for day " << plannedDays << ":";
            cin >> activity;
            dailyPlan[plannedDays]->addActivity(activity);
            int yes=0;
            cout << "add another activity? Yes(1)/No(0): ";
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

int Itinerary::getTripLength(){
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

Day& Itinerary:: operator[](int i) {
        if((i-1)< 0) {
            std::cerr << "warning not a vaild index" << std::endl; 
            dailyPlan[0]->display();
    }
    
        else if (i > triplength) {
            std::cerr << "warning not a vaild index" << std::endl; 
        }
         return *(dailyPlan[i]);
    }



void Itinerary::put_in_global_mem(int offset) { 
    int len_dest = destination.length()+1;
    int len_startDateStr = startDateStr.length()+1;
    int len_endDateStr = endDateStr.length()+1;
    _put_raw(offset+4, destination.c_str());
    _put_raw(offset+4+ len_dest, startDateStr.c_str());
    _put_raw(offset+4+ len_dest+ len_startDateStr ,endDateStr.c_str());
    _put_int(offset+4+ len_dest+ len_startDateStr+len_endDateStr,triplength);
    _put_int(offset+4+len_dest+ len_startDateStr+len_endDateStr+triplength, actCount);
    int setOff= 0;
    for(int i = 0; i< plannedDays; ++i){
        for(int j=0; j< actCount;++j){
            setOff+=50;
            _put_raw(offset+4+ len_dest+ len_startDateStr + len_endDateStr + triplength+ actCount +setOff, (dailyPlan[i+1]->getActivity(j)).c_str());
        }
    }
    gm_size = 4 + len_dest + len_startDateStr + len_endDateStr + triplength + actCount;
    _put_int(offset, gm_size);
}

void Itinerary::get_from_global_mem(int offset) {
    cout<< "test"<< endl;
    gm_size = _get_int(offset);
    destination = _global_mem+offset+4;
    int len_dest = destination.length()+1;
    startDateStr = _global_mem + offset + 4 + len_dest;
    int len_startDate = startDateStr.length()+1;
    endDateStr = _global_mem + offset+4+ len_dest+ len_startDate;
    int len_endDate = endDateStr.length()+1;
    triplength = _get_int(offset+4+ len_dest+ len_startDate+len_endDate);
    actCount = _get_int(offset+4+len_dest+ len_startDate+len_endDate+triplength);
    cout << actCount << endl;
    string test = _global_mem +offset+4+len_dest+ len_startDate+len_endDate+triplength+ actCount+50;
    cout << test << endl;
    string activities[actCount];
    cout<< "test" <<endl;
    int setOff = 0;
    for(int i=0; i<actCount; ++i){
        setOff+=50;
        activities[i] = _global_mem +offset+4+len_dest+ len_startDate+len_endDate+triplength+ actCount+setOff;
    }
    cout << triplength << endl;
    cout << actCount << endl;
    for(int i=0; i<actCount; ++i){
    cout << activities[i] << endl;}    
}
