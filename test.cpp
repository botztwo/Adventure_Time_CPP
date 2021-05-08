#include"../react.h"

int main() {
  _init();

  if (_just_starting()) {
    _put_raw(1, "10%");
  }
  string s = _global_mem + 1;  // user input
  add_yaml("test.yaml", {{"x", s}});

  _quit();
}
