#include "Date.h"
#include "Day.h"
#include <iostream>
#include <iomanip> 
using namespace std;



//day object has a string of activities; these are what used in the itinerary 
    Day::Day(){
        count = 0;
        size= DEFAULT_SIZE;
        activities = new std::string[size];
    }


//add a new activity 
    void Day::addActivity(std::string act){
         activities[count] = act;
         ++count;
       
    }


/// display your plans
    void Day::display(){
        for(int i=0; i<count; ++i){
           cerr<<i+1<< ")" << activities[i] << endl;
        }
    }

    string Day::getActivity(int x){
        return activities[x];
    }
    