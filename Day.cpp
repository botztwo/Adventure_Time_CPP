#include "Date.h"
#include "Day.h"
#include <iostream>
#include <iomanip> 
using namespace std;


    Day::Day(){
        count = 0;
        size= DEFAULT_SIZE;
        activities = new std::string[size];
        /*for(int i =0; i< DEFAULT_SIZE; ++i){
            activities[i]=0;
        }*/

    }

    void Day::addActivity(std::string act){
         activities[count] = act;
         ++count;
        // cerr<< count << endl;
    }

    void Day::display(){
        for(int i=0; i<count; ++i){
           cerr<<i+1<< ")" << activities[i] << endl;
        }
    }

    string Day::getActivity(int x){
        return activities[x];
    }
    