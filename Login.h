#ifndef _Login_H_
#define _Login_H_
#include<iostream>
#include <cstring>
#include <fstream>
#include"../react.h"
#include"Messages.h"
using namespace std;

class User_info{
    private:
        string password;
        string email;
    protected:
        string username;
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

class Social: public User_info{
    //content about posting and deleting to a socials page. Simialr structure to how we will display in the user_profile page.
    //follow/follower method 
    
};
class Chat :public Social{
    short num_messages, size;
    std::string **elt;
    static const short DEFAULT_SIZE = 100;
    public:
        Messages();
        Messages(std::istream &is);
        void append_message(const string &msg);
        void display() const;
        void print_to_file(const char *filename) const;
        //void put_in_global_mem(int text_offset) const;
        //void clear();
        //void get_from_global_mem(int text_offset);
        ~Messages();
}; 

#endif  // _Login_H_
