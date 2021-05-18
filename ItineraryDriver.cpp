#include "Itinerary.h"
#include "Login.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include "../react.h"
using namespace std;

int text_index_1 = 2000,  text_index_2= 2040,  text_index_3=2080,  text_index_4= 2120    /*,  text_index_5 =610 */;
int x1 = 15.5, x2= 22, x3 =27, x4 =32, x5 = 37/*, x6=42*/;
int day_index =1000;
char page = 'l';

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
    _global_mem[8113] =0;
    _global_mem[8123] =0;
    _global_mem[8133] =0;
    _put_char(9108,page);
   //add_yaml("Dates.yaml");
   //cerr<< "test test " <<endl;
  _put_raw(0, "Plan New Trip");  // null byte appended automatically
  _put_raw(21, "Where to?");
  _put_raw(32, "Start Date: ");
  _put_raw(45, "End Date: ");
  _put_raw(57, "Start Planning ");
  _put_raw(7000, "Welcome to Adventure Time!");
  _put_raw(7027, "Register");
  _put_raw(7037, "Login");
  _put_raw(7047, "Exit");
  _put_raw(7052, "Username:");
  _put_raw(7062, "Password:");
  _put_raw(7072, "Email:");
  _put_raw(7079, "Home_Page");
  _put_raw(7089, "Add_Trip");
  _put_raw(7098, "User_Page");
  //Itinerary mexico(4,25,2021,4,30,2021);
  }
  else{
    cerr << "else here " << endl;
    User_info jason;
  Itinerary mexico(75);
  cerr << "mexico made " << endl;
  int gcount= 67;
  page = _get_char(9108);
  if (_received_event()) {
  cerr << "recived " << endl;
   // add_yaml("Itinerary.yaml");
   if (_event_id_is("Register")) {
     cerr << "register " << endl;
      jason.get_and_register(8109);
      page = 'l';
      _put_char(9108,page);
    } 
    else if (_event_id_is("Login")) {
           cerr << "login " << endl;

      if (jason.check_and_login(8109)){
        page = 'D';
        _put_char(9108,page);
        //cerr << "This page is" << _global_mem[9108] << endl;
      }
    else{
        cerr << "Incorrect Login! Try Again!" << endl;
        page = 'l';
        _put_char(9108,page);
      }
    }
    else if (_event_id_is("Exit")){
      cerr << "Exit Ran" << endl;
      page = 'l';
      cerr << "Exit page is " << page << endl;
      cerr << _global_mem[9108] << endl;
    }
     else if (_event_id_is("Start")) {
       page = 'I';
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
       _put_raw(700, "Complete");

        for(int i=0; i<mexico.getTripLength(); ++i){
          int count = i+1;
          _put_raw(day_index,mexico.InttoStr(count).c_str());
          add_yaml("debug.yaml", {{"index_1", text_index_1},{"index_2", text_index_2},{"index_3", text_index_3},
                                  {"index_4", text_index_4}/*,{"index_5", text_index_5}*/, {"x1", mexico.InttoStr(x1)+"%" }, 
                                  {"x2", mexico.InttoStr(x2)+"%"}, {"x3", mexico.InttoStr(x3)+"%" }, {"x4", mexico.InttoStr(x4)+"%" }, 
                                  {"x5", mexico.InttoStr(x5)+"%" }/*,{"x6", mexico.InttoStr(x6)+"%" }*/ ,  {"day_index", day_index}});
          _global_mem[text_index_1]=0;
          _global_mem[text_index_2]=0;
          _global_mem[text_index_3]=0;
          _global_mem[text_index_4]=0;
          text_index_1 += 160;
          text_index_2 +=160;
          text_index_3 +=160;
          text_index_4 +=160;
         

          /*_global_mem[text_index_2-1]=0;
          _global_mem[text_index_3-1]=0;
          _global_mem[text_index_4-1]=0;*/
          
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
        if (_received_event()) {
              if (_event_id_is("add")) {
                page = 'I';
                //add_yaml("debug.yaml");
                /*string placeHold= _global_mem+ 235;
                mexico.StrtoInt(placeHold);
                mexico.plannedDays = mexico.StrtoInt(placeHold);;
                cerr << mexico.plannedDays <<endl;*/
                mexico.get_activities_from_global_mem();
                mexico.put_in_global_mem(2500);
                mexico.put_strings_in_global_mem(4000);
                mexico.get_from_global_mem(2500);
                  //_put_raw(230, "a");
                //cerr << mexico.plannedDays++ <<endl;
                //_put_raw(235, mexico.InttoStr((mexico.plannedDays)).c_str()); }
               //cerr << mexico.plannedDays <<endl
              }
    
    else if (_event_id_is("summary")){
          int firststr = 2500 + 4 + mexico.destination.length() +1 +mexico.startDateStr.length()+1 + mexico.endDateStr.length()+1 + +4 +4+17;
          cerr << mexico.triplength <<endl;
          cerr <<_global_mem[4000]<<endl;
          page = 'S';
          _put_raw(710, "Enjoy your trip to ");
          _put_raw(732, "You will be leaving on ");
          _put_raw(757, mexico.startDateStr.c_str());
          _put_raw(770, ", and coming home");
          _put_raw(795, mexico.endDateStr.c_str());
          _put_raw(9500, "Have Fun!");
          //x1 = 15;
          int fine = 15;
          int y1 = 40;
          //add_yaml("activity.yaml", {{"index_pos", 4000}, {"xxx", mexico.InttoStr(fine)+"%" }, {"yyy", mexico.InttoStr(y1)+"%" }});
          //add_yaml("activity.yaml", {{"index_pos", 4000}, {"xxx", mexico.InttoStr(fine)+"%" }, {"yyy", mexico.InttoStr(y1)+"%" }});
          
//{yyy}{index_pos}
//{xxx}
          /*for(int i=0 ; i<  mexico.triplength; ++i){
                for(int j=0; i<4 ; ++j){
                 add_yaml("activity.yaml", {{"index_pos", 4000+(20*j)}, {"xxx", mexico.InttoStr(fine)+"%" }, {"yyy", mexico.InttoStr(y1)+"%" }});
                 y1 += 5;
                }
                fine += 20;
          }*/
          //_global_mem[2504];
        
        }
              
        }
        
       
     

       /*for(int i =0; i< mexico.triplength; ++i){
         _put_raw(120, "Itinerary ");

       }*/

  
     //cerr<< "hi" <<endl;
     //mexico.get_and_start_trip(75);
    
    

  }
   

 //mexico[1].display();
}
cerr << "here " << endl;
 //mexico[1].display()
  if (page == 'l'){
    add_yaml("login.yaml");
  }
  else if (page == 't'){
    add_yaml("test.yaml");
  }
  else if ( page == 'D'){
    add_yaml("Dates.yaml");
  }
  else if (page == 'I'){
    add_yaml("Itinerary.yaml");
  }
  else if (page =='S'){
    add_yaml("summary.yaml");
  }

  _quit();



  //Itinerary mexico(4,25,2021,4,30,2021);
    //cout<<mexico.getTripLength()<< endl;
    //mexico.planNewDay();
    //mexico[1].display();
    //mexico.planNewDay();
    //mexico[1].display()
    //mexico.put_in_global_mem(0);
    //mexico.get_from_global_mem(0);
}
