#include "Itinerary.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include "../react.h"
using namespace std;

int main(){
  //Itinerary mexico(4,25,2021,4,30,2021);
  _init();
  //Itinerary mexico(4,25,2021,4,30,2021);
 //Itinerary mexico();
  if(_just_starting()){
    _global_mem[75]=  0;
    _global_mem[100]= 0;
    _global_mem[103]= 0;
    _global_mem[106] =0;
    _global_mem[111] =0;
    _global_mem[114] =0;
    _global_mem[117] =0;
    _global_mem[250] =0;
    _global_mem[280] =0;
    _global_mem[310] =0;
   add_yaml("Dates.yaml");
   //cerr<< "test test " <<endl;
  _put_raw(0, "Plan New Trip");  // null byte appended automatically
  _put_raw(21, "Where to?");
  _put_raw(32, "Start Date: ");
  _put_raw(45, "End Date: ");
  _put_raw(57, "Start Planning ");
  //Itinerary mexico(4,25,2021,4,30,2021);
  }
  else{
  Itinerary mexico(75);
  int gcount= 67;
  if (_received_event()) {
    add_yaml("Itinerary.yaml");
     if (_event_id_is("Start")) {
       //Itinerary mexico( );
       //mexico.get_and_start_trip(75);
       _put_raw(122, "Itinerary");
       _put_raw(140, mexico.destination.c_str());
       _put_raw(155, mexico.startDateStr.c_str());
       _put_raw(170, mexico.endDateStr.c_str());
       _put_raw(200, mexico.InttoStr((mexico.getTripLength())).c_str());
       _put_raw(215, "Day");
       _put_raw(230, mexico.InttoStr((mexico.plannedDays+1)).c_str());
       _put_raw(245, "add");
        
        }
        if (_received_event()) {
              if (_event_id_is("add")) {
                mexico.get_activities_from_global_mem();
                mexico.actCount++;
               
        }
         

        }


      
      

       /*for(int i =0; i< mexico.triplength; ++i){
         _put_raw(120, "Itinerary ");

       }*/

  
     //cerr<< "hi" <<endl;
     //mexico.get_and_start_trip(75);
    
    

  }
 
}






  _quit();



  //Itinerary mexico(4,25,2021,4,30,2021);
    //cout<<mexico.getTripLength()<< endl;
    //mexico.planNewDay();
    //mexico[1].display();
    //mexico.planNewDay();
    //mexico[2].display()
    //mexico.put_in_global_mem(0);
    //mexico.get_from_global_mem(0);
}