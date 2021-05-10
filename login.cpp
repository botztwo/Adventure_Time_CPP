#include<iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool IsloggedIn(){
    string username,password,un, pw;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read(username +".txt");
    getline(read,un);
    getline(read,pw);

    if (un == username && pw ==password){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    int choice;

    cout << "1: Register"<<endl;
    cout << "2: Login"<<endl;
    cout << "Select Register or Login via number(1,2): ";
    cin >> choice;

    if (choice == 1){//register
        string username, password;

        cout << "select a username: ";
        cin >> username;
        cout << "select a password: ";
        cin >> password;

        ofstream f;
        f.open(username +".txt");
        f << username << endl;
        f << password <<endl;
        f.close();
        main();
    }
    else if (choice == 2){//login
        bool status = IsloggedIn();
        if (!status){
            cout << "Incorrect Login information!" << endl;
            return 0;
        }
        else{
            cout << "Successful login" << endl;
            return 1;
        }
    }
}