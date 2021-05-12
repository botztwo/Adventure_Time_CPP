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
  int gcount = 78;
  //jason.login_test();
  //jason.get_from_global_mem(78);

  if (_received_event()) {
    if (_event_id_is("Register")) {
      jason.get_and_register(gcount);
    } 
    else if (_event_id_is("Login")) {
      jason.check_and_login(gcount);
    }
    else if (_event_id_is("Exit")){
      //Go out of the page
    }
  }
  add_yaml("login.yaml");

  _quit();
}
