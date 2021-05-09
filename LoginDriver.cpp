#include "Login.h"
#include"Itinerary.h"
int main(){
    User_info jason;
    jason.login_test();
    jason.put_in_global_mem(0);
    jason.get_from_global_mem(0);
    std::ifstream f("a.txt");
    Server u1(f);
    _init();

  if (_just_starting()) {
    _put_raw(1, "10%");
  }
  string s = _global_mem + 1;  // user input
  add_yaml("test.yaml", {{"x", s}});

  _quit();
}
