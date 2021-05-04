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
    protected:
        string un;
        string pw;
        int choice;
    public:
        User_info();
        void Test_for_Lab();
        bool IsloggedIn(); 
        int login_test();

};

#endif  // _Login_H_
