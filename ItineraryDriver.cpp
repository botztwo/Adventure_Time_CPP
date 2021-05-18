#include "Itinerary.h"
#include "Login.h"
#include "Day.h"
#include "Date.h"
#include <iostream>
#include <iomanip> 
#include "../react.h"
using namespace std;

//Global variables that will be needed in many spots due to the nature of react yaml displays and page turning. 
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
    //adding null bytes so that the user does not have to use the text input boxes in sequence.
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
    //put char puts the page char into global mem so that if the webpage isn't just starting, we can get the value form global mem.
   _put_char(9108,page);
  _put_raw(0, "Plan New Trip");  // manual inputs of put raw for the headers and labels.
  _put_raw(21, "Where to?");  // null byte appended automatically
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
  }
  else{
    cerr << "else here " << endl;//testing 
    User_info jason;//object creation for user and tripplans 
  Itinerary mexico(75);
  cerr << "mexico made " << endl;//testing
  page = _get_char(9108);//get the page that is stored into global mem.
  if (_received_event()) {// controls the user interaction (buttons)
  cerr << "recived " << endl;//testing
   if (_event_id_is("Register")) {
     cerr << "register " << endl;
      jason.get_and_register(8109);//run register method when button is toggled
      page = 'l';
      _put_char(9108,page);//keep same page 
    } 
    else if (_event_id_is("Login")) {
           cerr << "login " << endl;

      if (jason.check_and_login(8109)){//if the credentials match then change the page to the next one 
        page = 'D';
        _put_char(9108,page);
        //cerr << "This page is" << _global_mem[9108] << endl;
      }
    else{//keep same page if it isn't 
        cerr << "Incorrect Login! Try Again!" << endl;
        page = 'l';
        _put_char(9108,page);
      }
    }
    else if (_event_id_is("Exit")){//return to the previous login page
      cerr << "Exit Ran" << endl;//test
      page = 'l';
      cerr << "Exit page is " << page << endl;//test
      cerr << _global_mem[9108] << endl;//test
    }
     else if (_event_id_is("Start")) {//toggled with the start planning button 
       page = 'I';
       _put_raw(122, "Itinerary");//getting the perimeters from the text inputs
       _put_raw(140, mexico.destination.c_str());
       _put_raw(155, mexico.startDateStr.c_str());
       _put_raw(170, mexico.endDateStr.c_str());
       _put_raw(200, mexico.InttoStr((mexico.getTripLength())).c_str());
       _put_raw(215, "Let's Plan Day ");//More basic put raw for the new page
       _put_raw(240, "Save Plan"); 
       _put_raw(340, "Trip Planning In Progress");   
       _put_raw(370, "Destination: ");   
       _put_raw(390, "Start Date: ");   
       _put_raw(410, "End Date: ");  
       _put_raw(425, "Trip Length: ");  
       _put_raw(700, "Complete");

        for(int i=0; i<mexico.getTripLength(); ++i){//difficult add yaml part which adds a yaml depending on the length of the trip changes index and location of each text box because 
          int count = i+1;
          _put_raw(day_index,mexico.InttoStr(count).c_str());
          add_yaml("debug.yaml", {{"index_1", text_index_1},{"index_2", text_index_2},{"index_3", text_index_3},
                                  {"index_4", text_index_4}/*,{"index_5", text_index_5}*/, {"x1", mexico.InttoStr(x1)+"%" }, 
                                  {"x2", mexico.InttoStr(x2)+"%"}, {"x3", mexico.InttoStr(x3)+"%" }, {"x4", mexico.InttoStr(x4)+"%" }, 
                                  {"x5", mexico.InttoStr(x5)+"%" }/*,{"x6", mexico.InttoStr(x6)+"%" }*/ ,  {"day_index", day_index}});
          _global_mem[text_index_1]=0;//null bytes so user can access any text box without affecting the other ones. 
          _global_mem[text_index_2]=0;
          _global_mem[text_index_3]=0;
          _global_mem[text_index_4]=0;
          text_index_1 += 160;//offset so that each textbox has a unique index. 
          text_index_2 +=160;
          text_index_3 +=160;
          text_index_4 +=160;
         
          cerr << count << endl;
          day_index +=2;//more offseting the index

          x1 +=30;
          x2 +=30;
          x3 +=30;
          x4 +=30;
          x5 +=30;      
        }
      
        }
        if (_received_event()) {//stores activities in the global mem and gets from global mem to display on the next page. 
              if (_event_id_is("add")) {
                page = 'I';
                mexico.get_activities_from_global_mem();
                mexico.put_in_global_mem(2500);
                mexico.get_from_global_mem(2500);
                 
              }
    
    else if (_event_id_is("summary")){//redundant but this part is associated with the complete button that displays a summary 
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
          
          int fine = 15;
          int y1 = 40;
                
        }
              
        }
    
  }
  
}
cerr << "here " << endl;
//page turning at the end of the function.
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

}
