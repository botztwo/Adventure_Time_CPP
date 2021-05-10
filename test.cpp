#include"../react.h"
  
int main() {
  _init();

  if (_received_event()) {
    if (_event_id_is("Register")) {
      std::cerr << "Register!\n";
    } 
    else if (_event_id_is("Login")) {
      std::cerr << "Login.\n";
    }
    else if (_event_id_is("Exit")){
      std::cerr << "Exit" << std::endl;

    }
  }
  add_yaml("test.yaml");

  _quit();
}
