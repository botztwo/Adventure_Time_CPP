#include"../react.h"
#include "Login.h"
#include"Itinerary.h"
int main(){
    _init();
    User_info jason;
    jason.login_test();
    jason.put_in_global_mem(0);
    jason.get_from_global_mem(0);
    std::ifstream f("a.txt");
    Server u1(f);
  _put_raw(0, "Select Option Below...\n");
  _put_int(21,0);
  _put_raw(22, "Register");
  _put_int(31,0);
  _put_raw(32, "Login");
  _put_int(41,0);
  _put_raw(42, "Exit");
  _put_int(48,0);
  _put_raw(49, "Username:");
  _put_int(58,0);
  _put_raw(59, "Password:");
  _put_int(68,0);
  _put_raw(69, "Email:");
  _put_int(75,0);
  int globnum = 76;

  if (_received_event()) {
    if (_event_id_is("Register")) {
      add_yaml("login2.yaml"); 
    } 
    else if (_event_id_is("Login")) {
      add_yaml("login2.yaml");
    }
    else if (_event_id_is("Exit")){
      //Go out of the page
    }
  }
  add_yaml("login.yaml");

  _quit();
}
