#include"../react.h"
  
int main() {
  _init();

  if (_received_event()) {
    if (_event_id_is("Register")) {
      std::cerr << "Go!\n";
    } 
    else if (_event_id_is("Login")) {
      std::cerr << "Stop.\n";
    }
    else if (_event_id_is("Exit")){

    }
  }
  add_yaml("test.yaml");

  _quit();
}
