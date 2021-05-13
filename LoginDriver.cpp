#include"../react.h"
#include "Login.h"
#include"Itinerary.h"
int main(){
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
  _put_raw(79, "Home Page");
  _put_raw(89, "Add Trip");
  _put_raw(98, "User Page");
  //108;
  int gcount1 = 109;
  char page;
  if (_just_starting()){
    page = 'l';
    _put_char(108,page);
  }
  else {
    page = _get_char(190);
  }
  //page turning
  if (page == 'l'){
    add_yaml("login.yaml");
    cerr << "ya " << page << endl;
  }
  else if (page == 't'){
    add_yaml("test.cpp");
  }
  //jason.login_test();
  //jason.get_from_global_mem(78);
  
  if (_received_event()) {
    if (_event_id_is("Register")) {
      jason.get_and_register(gcount1);
      page = 'l';
    } 
    else if (_event_id_is("Login")) {
      if (jason.check_and_login(gcount1)){
        page = 't';
        _put_char(190,page);
      }
      else{
        cerr << "Incorrect Login! Try Again!" << endl;
        page = 'l';
      }
    }
    else if (_event_id_is("Exit")){
      //cerr << jason.check_and_login(gcount1) << endl;
    }
  }
  _quit();
}
