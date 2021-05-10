#include <iostream>
#include <iomanip> 
#include "Date.h"
using namespace std;



Date::Date(int sm,int sd,int sy/*, int em,int ed,int ey*/){

    setMonth(sm);
    setDay(sd);
    setYear(sy);
    
}

void Date:: setDay(int d){ // initalizes the start day
    if(d >=1 && d<=31){
    day = d;
    }
    
    
}


int Date:: getDay(){
    return day;
}


void Date:: setMonth(int m){
    if(m >=1 && m <= 12){
    month = m;
    }
    
}

int Date:: getMonth(){
    return month;
}

void Date:: setYear(int y){
    year = y;  
}


int Date:: getYear(){
    return year;
}



string Date::getMonthStr() {
    string monthStr;
    stringstream ss;
    ss<< getMonth();
    ss >> monthStr;
    return monthStr;

}

string Date::getDayStr() {
    string dayStr;
    stringstream ss;
    ss<< getDay();
    ss >> dayStr;
    return dayStr;

}

string Date::getYearStr(){
    string yearStr;
    stringstream ss;
    ss<< getYear();
    ss >> yearStr;
    return yearStr;

}

/*void Date::Datetostring(){
    string str;
    stringstream ss;
    ss<< getMonth();
    ss >>str;
    cout<<"string rep test     " << str << endl;
}*/

void Date:: print() {
    std::cerr << "Date " << std::endl;
    std::cerr<<setfill('0') <<setw(2) <<getMonth()<<"/"
                            << setw(2)<<getDay()<< "/" 
                            << setw(4) << getYear() << endl;}
string Date::makeStrDate() {
   // std::cerr << "Date " << std::endl;
    string date;
    stringstream ss;
    ss << setfill('0') << setw(2) << getMonthStr() + "/"<< setw(2)<<getDayStr() + "/" << setw(4) << getYearStr();
    ss>>date;
    return date;
    //use string stream as wel
    }



