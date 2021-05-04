#ifndef _Date_H_
#define _Date_H_
#include <iostream>
#include <cstring>
#include <iomanip> 
using namespace std;


class Date{

    int month;
    int day;
    int year;

   public:
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    int getDay();
    int getMonth();
    int getYear();
    Date(int d=0, int m =0, int y=0);
    void print();
};


#endif