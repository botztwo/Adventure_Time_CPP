#include "Itinerary.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include "../react.h"
using namespace std;

int text_index_1 = 2000,  text_index_2= 2040,  text_index_3=2080,  text_index_4= 2120    /*,  text_index_5 =610 */;
int x1 = 15.5, x2= 22, x3 =27, x4 =32, x5 = 37/*, x6=42*/;
int day_index =1000;

      
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
       _put_raw(215, "Let's Plan Day ");
       //_put_raw(235, "1");
       //_put_raw(230, mexico.InttoStr((mexico.plannedDays+1)).c_str());
       //_put_raw(230, "1");
       _put_raw(240, "Save Plan"); 
       _put_raw(340, "Trip Planning In Progress");   
       _put_raw(370, "Destination: ");   
       _put_raw(390, "Start Date: ");   
       _put_raw(410, "End Date: ");  
       _put_raw(425, "Trip Length: ");  

        for(int i=0; i<mexico.getTripLength(); ++i){
          int count = i+1;
          _put_raw(day_index,mexico.InttoStr(count).c_str());
          add_yaml("debug.yaml", {{"index_1", text_index_1},{"index_2", text_index_2},{"index_3", text_index_3},
                                  {"index_4", text_index_4}/*,{"index_5", text_index_5}*/, {"x1", mexico.InttoStr(x1)+"%" }, 
                                  {"x2", mexico.InttoStr(x2)+"%"}, {"x3", mexico.InttoStr(x3)+"%" }, {"x4", mexico.InttoStr(x4)+"%" }, 
                                  {"x5", mexico.InttoStr(x5)+"%" }/*,{"x6", mexico.InttoStr(x6)+"%" }*/ ,  {"day_index", day_index}});
          text_index_1 += 200;
          text_index_2 +=240;
          text_index_3 +=280;
          text_index_4 +=320;
          //text_index_5 +=360;
          //_put_raw(day_index,mexico.InttoStr(count).c_str());
          cerr << count << endl;
          day_index +=2;

          x1 +=30;
          x2 +=30;
          x3 +=30;
          x4 +=30;
          x5 +=30;


          //x6 +=30;
      
        }
      
        }
        //if (_received_event()) {
              if (_event_id_is("add")) {
                //add_yaml("debug.yaml");
                /*string placeHold= _global_mem+ 235;
                mexico.StrtoInt(placeHold);
                mexico.plannedDays = mexico.StrtoInt(placeHold);;
                cerr << mexico.plannedDays <<endl;*/
                mexico.get_activities_from_global_mem();
                  //_put_raw(230, "a");
                //cerr << mexico.plannedDays++ <<endl;
                //_put_raw(235, mexico.InttoStr((mexico.plannedDays)).c_str()); }
               //cerr << mexico.plannedDays <<endl
    
    if (_event_id_is("summary")){
        add_yaml("summary.yaml");
        _put_raw(450, "test");
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