#include "Login.h"
#include"Itinerary.h"

    User_info::User_info(){
        followed = 0;
        follow = 0;
            
        //cerr << "This constructor ran" << endl; testing purposes
        }
        
    void User_info::Test_for_Lab(){//used for testing in the lab to see if methods run according to call.
            cerr << "This ran" << endl;
        }
    bool User_info::IsloggedIn(){// a bool function that allows the user to compare the username and password combination to the txt file database 
    //standard cin inputs for terminal use.
    cerr << "Enter username: ";
    cin >> username;
    cerr << "Enter password: ";
    cin >> password;

    ifstream read(username +".txt");//reading from a file
    getline(read,un);
    getline(read,pw);

    if (un == username && pw ==password){//checking to see if the password matches the username 
        return true;
    }
    else{
        return false;
    }
    }
    int User_info::login_test(){//used to see if the login functionality works in the terminal
    
        cerr << "1: Register"<<endl;
        cerr << "2: Login"<<endl;
        cerr << "3: Exit" << endl;
        cerr << "Select Register or Login via number(1,2,3): ";
        cin >> choice;

        if (choice == 1){//register
            
            cerr << "Select a username: ";
            cin >> username;
            cerr << "Select a password: ";
            cin >> password;
            cerr << "Input your email: ";
            cin >> email;

            write_to_file();
            login_test();
        }
        
        else if (choice == 2){//login
            bool status = IsloggedIn();
            if (!status){
                cerr << "Incorrect Login information!" << endl;
                return 0;
            }
            else{
                cerr << "Successful login" << endl;
                first_page();
                return 1;
            }
        }
        else if (choice == 3){
            cerr << "Bye!" << endl;
            return 0;
        }
    }
    void User_info::write_to_file(){
        ofstream f;//opens file connection
            f.open(username +".txt");//opens a txt file with the username that was created.
            f << username << endl;//username goes in
            f << password << endl;//password goes in
            f << "Email: " << email << endl;//email goes in
            f << "Followers: " << followed << endl;//dont use
            f << "Following: " << follow << endl;//dont use
            f.close();
    }
    void User_info::first_page(){
        cerr << "***************Welcome to Adventure Time " << username << "!***************" << endl;
        cerr << "Home Page" << endl;
        cerr << "Select Option: " << endl;
        cerr << "1. Social Page" << endl;
        cerr << "2. Add Trip" << endl;
        cerr << "3. User_page" << endl;
        cerr << "4. Logout" << endl;
        cerr << ">> ";
        cin >> choice;
        if (choice == 1){
            cerr << "move to socials"; //set up connection with a shared server (lab2, lab6, lab10)

        }
        else if (choice ==2){
            Itinerary mexico(4,25,2021,4,30,2021);
            //cerr<<mexico.getTripLength()<< endl;
            mexico.planNewDay();
            //mexico[1];
        }
        else if (choice == 3){
            cerr << "move to my page";
        }
        else if (choice == 4){
            login_test();
        }
    }   

    Server::Server(){
        num_messages = 0;
        size = DEFAULT_SIZE;
        elt = new std::string*[size];
        for (int i = 0; i < size; i++){
            elt[i] = 0;
        }
    }
    Server :: Server(std::istream &is){
        int n;
        is >> n;
        num_messages = n;
        size = DEFAULT_SIZE;
        elt = new std::string*[num_messages];
        for (int i = 0; i < num_messages; i++){
            std::string *s = new std::string;
            std::string mes;
            is >> mes;
            *s = mes;
            elt[i] = s;
        }
    }

    void Server::append_message(const string &msg){
        std::string *message = new std::string(msg);
        elt[num_messages] =  message;
        num_messages++; 
    }

    void Server::display() const{
        for (int i = 0; i < num_messages;i++){
            cerr << i <<": " << *elt[i] << endl;
        }
    }

    void Server:: print_to_file(const char *filename) const{
        std::ofstream f(filename);
        f << num_messages <<endl;
        for (int i = 0; i < num_messages; i++){
            f << *elt[i] << endl;
        }
        f.close();
    }

void User_info::put_in_global_mem(int offset) {//Important in terms of putting stuff into global mem. Also used in the Itinerary function 
  username = _global_mem + offset + 4; //username would be put inot global mem at the given offset plus size of gm_size
  password = _global_mem +offset + 4 + 10;//account for username length
  email = _global_mem +offset + 4 + 20;//account for password length 
  //_put_raw(offset+4, username.c_str());
  //_put_raw(offset+4+len_user,password.c_str());
  int len_user = username.length()+1;//length + null byte
  int len_pass = password.length()+1;
  gm_size = 4 + len_user + len_pass;//size of the user info 
  _put_int(offset, gm_size);
  //testing
  //cerr << username << endl;
  cerr << password << endl;
  //cerr << gm_size << endl;
}

void User_info::get_from_global_mem(int offset) {//get the information that we stored into global_mem. Used in the Itinerary class as well. 
  gm_size = _get_int(offset);
  username = _global_mem + offset + 4;
  int len_user = username.length()+1;
  password = _global_mem +offset + 4 + len_user;
  int len_pass = password.length()+1;
  cerr << "Testing for global mem input";//testing
  cerr << username;
  cerr << ": ";
  cerr << password;
  cerr << endl;
}
bool User_info::check_file(int offset){
    username = _global_mem + offset + 4; //same method from get_from_global_mem
    password = _global_mem +offset + 4 + 10;
    ifstream read(username +".txt");//open the txt file to read. Same method used in the 
    getline(read,un);
    getline(read,pw);
    cerr << un << endl;

    if (un == username && pw ==password){
        return true;
    }
    else{
        return false;
    }
}

void User_info::get_and_register(int offset){//used for the first time register button. 
    gm_size = _get_int(offset);
    username = _global_mem + offset + 4;//modifed version of get_from_global_mem
    int len_user = username.length()+1;
    password = _global_mem +offset + 4 + 10;
    int len_pass = password.length()+1;
    email = _global_mem +offset + 4 + 20;
    int len_mail = email.length()+1;
    write_to_file();
}

bool User_info::check_and_login(int offset){//isolated part of the login functionality to associate the function to a button. 
    bool status = check_file(offset);
        if (!status){
            cerr << "Incorrect Login information!" << endl;
            return 0;
        }
        else{
            cerr << "Successful login" << endl;
            return 1;
        }
}



/*string Server::get_display_string(void) {
  stringstream ss;
  ss << bal << " (" << init_bal << ")[" << owner << "]";
  return string(ss.str());
}*/



