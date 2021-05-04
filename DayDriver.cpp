#include <iostream>
#include <iomanip> 
#include "Date.h"
#include "Day.h"
using namespace std;


int main(){
    Day day1;
    Day day2;
    day1.addActivity("Fishing");
    day1.addActivity("Picnic");
    day1.display();
}


