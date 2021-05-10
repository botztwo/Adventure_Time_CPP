#include "Itinerary.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include"../react.h"
using namespace std;



int main(){
    /*_init();

  if (_received_event()) {
    if (_event_id_is("go")) {
      std::cerr << "Go!\n";
    } else if (_event_id_is("stop")) {
      std::cerr << "Stop.\n";
    }
  }
  add_yaml("Itinerary.yaml");
  _quit();*/
    Itinerary mexico(4,25,2021,4,30,2021);
    //cout<<mexico.getTripLength()<< endl;
    mexico.planNewDay();
    mexico[1].display();
    mexico.put_in_global_mem(0);
    mexico.get_from_global_mem(0);
    
}