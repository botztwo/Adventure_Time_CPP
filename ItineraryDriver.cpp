#include "Itinerary.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include"../react.h"
using namespace std;



int main(){
  _init();

  add_yaml("Itinerary.yaml");
  _put_raw(5, " Where to?");  // null byte appended automatically
  _put_raw(1, "zyx");

  _quit();



  //Itinerary mexico(4,25,2021,4,30,2021);
    //cout<<mexico.getTripLength()<< endl;
    //mexico.planNewDay();
    //mexico[1].display();
    //mexico.planNewDay();
    //mexico[2].display();
    //mexico.put_in_global_mem(0);
    //mexico.get_from_global_mem(0);
    
}