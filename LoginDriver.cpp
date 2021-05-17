#include"../react.h"
#include "Login.h"
#include"Itinerary.h"
int main(){//
    User_info jason;
    //std::ifstream f("a.txt");
    //Server u1(f);
  _init();
  
  _put_raw(0, "Welcome to Adventure Time!");
  _put_raw(27, "Register");
  _put_raw(37, "Login");
  _put_raw(47, "Exit");
  _put_raw(52, "Username:");
  _put_raw(62, "Password:");
  _put_raw(72, "Email:");
  _put_raw(79, "Home_Page");
  _put_raw(89, "Add_Trip");
  _put_raw(98, "User_Page");
  //108;
  int gcount1 = 153;
  _global_mem[75+gcount1]=  0;
    _global_mem[100+gcount1]= 0;
    _global_mem[103+gcount1]= 0;
    _global_mem[106+gcount1] =0;
    _global_mem[111+gcount1] =0;
    _global_mem[114+gcount1] =0;
    _global_mem[117+gcount1] =0;
    _global_mem[250+gcount1] =0;
    _global_mem[280+gcount1] =0;
    _global_mem[310+gcount1] =0;
  _put_raw(0+gcount1, "Plan New Trip");  // null byte appended automatically
  _put_raw(21+gcount1, "Where to?");
  _put_raw(32+gcount1, "Start Date: ");
  _put_raw(45+gcount1, "End Date: ");
  _put_raw(57+gcount1, "Start Planning ");
  char page = 'l';
  if (_just_starting()){
    page = 'l';
    _global_mem[113] = 0;
    _global_mem[123] = 0;
    _global_mem[133] = 0;
    _global_mem[153] = 0;
    _put_char(108,page);
  }
  else {
    page = _get_char(108);
  }

  //jason.login_test();
  //jason.get_from_global_mem(78);
  
  if (_received_event()) {
    if (_event_id_is("Register")) {
      jason.get_and_register(gcount1);
      page = 'l';
      _put_char(108,page);
    } 
    else if (_event_id_is("Login")) {
      if (jason.check_and_login(gcount1)){
        page = 't';
        _put_char(108,page);
        cerr << "This page is" << _global_mem[108] << endl;
      }
    else{
        cerr << "Incorrect Login! Try Again!" << endl;
        page = 'l';
        _put_char(108,page);
      }
    }
    else if (_event_id_is("Exit")){
      cerr << "Exit Ran" << endl;
      page = 'l';
      cerr << "Exit page is " << page << endl;
      cerr << _global_mem[108] << endl;
    }
    else if (_event_id_is("Socials")){
      //come back to this ya 
    }
    else if ( _event_id_is("Add")){
      page = 'D';
      _put_char(108,page);
    }
    else if (_event_id_is("Back")){
      page = 'q';
    }
    else if (_event_id_is("Start")) {
      Itinerary mexico(75+gcount1);
       //Itinerary mexico( );
       //mexico.get_and_start_trip(75);
       //add_yaml("texts.yaml", {{"index_1", text_index_1};
       //ADD SOMEWHERE
       _put_raw(122+gcount1, "Itinerary");
       _put_raw(140+gcount1, mexico.destination.c_str());
       _put_raw(155+gcount1, mexico.startDateStr.c_str());
       _put_raw(170+gcount1, mexico.endDateStr.c_str());
       _put_raw(200+gcount1, mexico.InttoStr((mexico.getTripLength())).c_str());
       _put_raw(215+gcount1, "Day");
       _put_raw(230+gcount1, mexico.InttoStr((mexico.plannedDays+1)).c_str());
       _put_raw(245+gcount1, "add");
       page = 'I';
      }

   /* else if (_event_id_is("add")) {
                mexico.get_activities_from_global_mem();
                mexico.actCount++;     
        }*/
  }
  //page turning
  if (page == 'l'){
    add_yaml("login.yaml");
    add_yaml("test.yaml");
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

  else if ( page == 'q'){
    int test = 17;
    for (int i = 0; i < 30; i+=10){
      string numstr;
      test += 10;
      stringstream ss;
      ss << 2*i;
      ss >> numstr;
      string percent = numstr + "%";
      add_yaml("text.yaml",{{"x", percent},{"index", test}});
    }
  }
  _quit();
}


