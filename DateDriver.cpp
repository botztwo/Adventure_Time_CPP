#include <iostream>
#include <iomanip> 
#include "Date.h"
using namespace std;




int main(){
  Date d1(4,1,2012);
  /*Trip d2(3,7,2015);
  Trip d3(12,4,2015);*/
  cout<< d1.makeStrDate()<< endl;
  cout<< endl;
  d1.print();
  cout<< endl;
  /*d2.print();
  cout<<endl;
  d3.print();
  cout<<endl;*/
    
}