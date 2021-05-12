#ifndef _Login_H_
#define _Login_H_
#include<iostream>
#include <cstring>
#include <fstream>
#include"../react.h"
#include"Itinerary.h"
#include <sstream>
//#include "Account.h"
//#include "Comm.h"
#include "react.h"
using namespace std;
class User_info{
    private:
        string password;
        string email;
        int count;
    protected:
        string username;
        string un;
        string pw;
        int choice;
        int gm_size;
        const char *tempu;
        const char *tempp;
    public:
        int followed;
        int follow;
        User_info();
        void Test_for_Lab();
        bool IsloggedIn(); 
        int login_test();
        void write_to_file();
        void first_page();
        void put_in_global_mem(int offset);
        void get_from_global_mem(int offset);
        bool check_file(int offset);
        void get_and_register(int offset);
        int check_and_login(int offset);

};

class Social: public User_info{
    //content about posting and deleting to a socials page. Simialr structure to how we will display in the user_profile page.
    //follow/follower method 
    
};
class Server :public Social{
    short num_messages, size;
    std::string **elt;
    static const short DEFAULT_SIZE = 100;
   
    public:
        Server();
        Server(std::istream &is);
        void append_message(const string &msg);
        void display() const;
        void print_to_file(const char *filename) const;
        //~Messages();
}; 

#endif  // _Login_H_
