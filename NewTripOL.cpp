#include <iostream>
#include <cstring>

/*struct Date{
    int startMonth;
    int startDay;
    int startYear;
    int endMonth;
    int endDay;
    int endYear;
};*/


class Trip{

    int startMonth;
    int startDay;
    int startYear;
    int endMonth;
    int endDay;
    int endYear;

   // int startMonth; //includes libray date . format();
    //int endDate; // includes on the dates 


    string location;
    Packing_Item packingItems[];
    Itnerary fullItnerary;

public:

    Trip(int start, int end):startDate(start),endDate(end){ }





  /*  getSummary(){


        //reeturn start date end date . 
    }
	

   int  setStartDate(){

   }

    string setlocation{


    }


};


class PackingItem{
    float cost;
    char *item;    

    public:
    PackingItem(float c,const char *ite ) :cost(c){
        item = new char[strlen(ite)+1];
        for(unsigned int i=0; i<strlen(ite)+1; ++i){
            item[i]=ite[i];} }


};

class Itnerary{

    Day day[]; // itenerary has many days 

    public: 

    detials about what each day is.. list of days... day class with activities 



};


class Day{

    string activties[];

    public: 
    add new activitys 


};

//Packing_Item::items[100];

*/
int main(){

    Trip Hawaii(12)
    //Packing_Item apples(12.99, "apples");
}