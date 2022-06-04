#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

bool has_spaces(string str){
    bool has_spaces = false;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            has_spaces = true;
        }
    }

    return has_spaces;
}

bool txt(string str){
    bool txt = false;

   for(int i = 0; i < str.length(); i++){
       if(str[i] == '.'){
           if(str[i + 1] == 't' && str[i + 2] == 'x' && str[i + 3] == 't') {
               txt = true;
           }
       }
   }

    return txt;
}

string get_file_names(bool filetype){
    bool input = false;
    string file_name;
    
    if(filetype == true){
        cout << "Output ";
    }
    else if(filetype == false){
        cout << "Input ";
    }

    cout << "file name(add the .txt)?: ";

    do{
        getline(cin, file_name);
        cout << endl;

        if(!has_spaces(file_name) && txt(file_name)){
            input = true;
        }
        else{
            cout << "That input is invalid try again: ";
            input = false;
        }
        
    } while(!input);

    return file_name;
}

void open_input_file(ifstream& strm){
    bool file_exists = true;

    do{
        string file_name = get_file_names(false);
        strm.open(file_name);
        if(!strm.is_open()){
            cout << "\nThe file couldn't be opened, try again.\n\n";
            file_exists = false;
        }
    }while(!file_exists);
}

bool close_file(ifstream& strm){
    strm.close();
    if (strm.is_open()){
        cout << "Stream could not close!" << endl;
        return false;
    }

    return true;
}


bool q_again(){
    bool input = true;
    char c;

    cout << "\nDo you want to build another resume again (y-yes, n-no)?: ";

    do{
        cin >> c;

        if(c == 'y'){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            return true;
        }
        else if(c == 'n'){
            return false;
        }
        else if(c != 'y' && c != 'n'){
            cout << "\nYou're input is invalid try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            input = false;
        }
    } while(!input);

    return false;
}