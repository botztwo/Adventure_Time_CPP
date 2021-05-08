#include<iostream>
#include <cstring>
using namespace std;

class User_info{
    private:
        string username;
        string password;
    protected:
        string usernametry;
        string passwordtry;
        bool logged = 0;
    public:
        User_info(const string u, const string p);
        void Test_for_Lab();
        void Login();

};

