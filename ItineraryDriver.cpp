#include "Itinerary.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
using namespace std;



int main(){

    Itinerary mexico(4,25,2021,4,30,2021);
    //cout<<mexico.getTripLength()<< endl;
    //mexico.planNewDay();
    //mexico[1];
    mexico.put_in_global_mem(0);
    mexico.get_from_global_mem(0);
    

}