#include "Login.h"
#include"Itinerary.h"

    User_info::User_info(){
        followed = 0;
        follow = 0;
            
        //cerr << "This constructor ran" << endl; 
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
        cout << "3: Exit" << endl;
        cout << "Select Register or Login via number(1,2,3): ";
        cin >> choice;

        if (choice == 1){//register
            
            cout << "Select a username: ";
            cin >> username;
            cout << "Select a password: ";
            cin >> password;
            cout << "Input your email: ";
            cin >> email;

            write_to_file();
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
                first_page();
                return 1;
            }
        }
        else if (choice == 3){
            cout << "Bye!" << endl;
            return 0;
        }
    }
    void User_info::write_to_file(){
        ofstream f;
            f.open(username +".txt");
            f << username << endl;
            f << password << endl;
            f << "Email: " << email << endl;
            f << "Followers: " << followed << endl;
            f << "Following: " << follow << endl;
            f.close();
    }
    void User_info::first_page(){
        cout << "***************Welcome to Adventure Time " << username << "!***************" << endl;
        cout << "Home Page" << endl;
        cout << "Select Option: " << endl;
        cout << "1. Social Page" << endl;
        cout << "2. Add Trip" << endl;
        cout << "3. User_page" << endl;
        cout << "4. Logout" << endl;
        cout << ">> ";
        cin >> choice;
        if (choice == 1){
            cout << "move to socials"; //set up connection with a shared server (lab2, lab6, lab10)

        }
        else if (choice ==2){
            Itinerary mexico(4,25,2021,4,30,2021);
            //cout<<mexico.getTripLength()<< endl;
            mexico.planNewDay();
            //mexico[1];
        }
        else if (choice == 3){
            cout << "move to my page";
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

void User_info::put_in_global_mem(int offset) {
  username = _global_mem + offset + 4; 
  int len_user = username.length()+1;
  password = _global_mem +offset + 4 + 10;
  int len_pass = password.length()+1;
  //_put_raw(offset+4, username.c_str());
  //_put_raw(offset+4+len_user,password.c_str());
  gm_size = 4 + len_user + len_pass;
  _put_int(offset, gm_size);
  //testing
  //cerr << username << endl;
  //cerr << password << endl;
  //cerr << gm_size << endl;
}

void User_info::get_from_global_mem(int offset) {
  gm_size = _get_int(offset);
  username = _global_mem + offset + 4;
  int len_user = username.length()+1;
  password = _global_mem +offset + 4 + len_user;
  int len_pass = password.length()+1;
  cerr << "Testing for global mem input";
  cerr << username;
  cerr << ": ";
  cerr << password;
  cerr << endl;
}
void User_info::get_and_check(int offset){
    gm_size = _get_int(offset);
    username = _global_mem + offset + 4;
    int len_user = username.length()+1;
    password = _global_mem +offset + 4 + len_user;
    int len_pass = password.length()+1;


}

/*string Server::get_display_string(void) {
  stringstream ss;
  ss << bal << " (" << init_bal << ")[" << owner << "]";
  return string(ss.str());
}*/



