#include "Login.h"

    User_info::User_info(){
            //username = u;
            //password = p;
            
        cerr << "This constructor ran" << endl; 
        }
        
    void User_info::Test_for_Lab(){
            cerr << "This ran" << endl;
        }
    bool User_info::IsloggedIn(){
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
    int User_info::login_test(){
    
        cout << "1: Register"<<endl;
        cout << "2: Login"<<endl;
        cout << "Select Register or Login via number(1,2): ";
        cin >> choice;

        if (choice == 1){//register
            
            cout << "select a username: ";
            cin >> username;
            cout << "select a password: ";
            cin >> password;

            ofstream f;
            f.open(username +".txt");
            f << username << endl;
            f << password << endl;
            f.close();
            login_test();
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




