#ifndef _Day_H_
#define _Day_H_
#include "Date.h"
#include <iostream>
#include <iomanip> 
using namespace std;

class Day{
    int size;
    std::string* activities;
    //std::string activties[]; // The length of this string will depend on how many things someone is doing on this day so how would i do that? 
    static const int DEFAULT_SIZE = 100;
    
    public: 
    Day();
    void addActivity(std::string act);
    void display();
    int count;
    string getActivity(int x);
    
};

#endif
