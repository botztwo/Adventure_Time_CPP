#ifndef _Login_H_
#define _Login_H_
#include<iostream>
#include <cstring>
#include <fstream>
using namespace std;

class User_info{
    private:
        string username;
        string password;
        string email;
    protected:
        string un;
        string pw;
        int choice;
    public:
        int followed;
        int follow;
        User_info();
        void Test_for_Lab();
        bool IsloggedIn(); 
        int login_test();
        void first_page();

};

#endif  // _Login_H_
