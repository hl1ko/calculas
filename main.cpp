#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int randomseed = 5; // random seed for start data R1.1
const int yearnow = 2025; // will use ctime lib to replace it. get year of system data. extra part

int printMenu(int &x, bool &enabled){
    std::cout << "All hail Ken Tsang.\n";
    std::cout << "*** SMS Main Menu ***\n";
    std::cout << "[1] Load Starting Data\n";
    std::cout << "[2] Show Student Records\n";
    std::cout << "[3] Add/Delete Students\n";
    std::cout << "[4] Edit Students\n";
    std::cout << "[5] Generate Transcript\n";
    std::cout << "[6] Credits and Exit\n";
    std::cout << "*************\n";
    std::cout << "Option (1 - 6): ";

    std::cin >> x; //get user input
    if (!(enabled) && ((x >= 2) || (x <= 5)) && (x != 1)){ 
        // show error only when data is not loaded and user using function 2~5. R1.2
        std::cout << "Starting data is not yet loaded. Please load starting data first!\n";
        x = 0;
    }else if(!(enabled) && (x == 1)){
        enabled = true;
        // R1.1 insert loadrealstartingdata here -------------------------------------------------------------------------------
    }
    return x; // return user input
    // we should rewrite this actually.s
}

class Student{
    public:
    void setDefault(){

    }
    void setName(char nt[]){
        for(int i = 0; i < 30; i++){
            name[i] = nt[i];
        } // use for loop to ensure that only 30 char will be entered into name
    }

    void setYear(int input){
        cohortyear = input;
        year = yearnow - input;
    }
    int getYear(){
        return year;
    }
    int getCYear(){
        return cohortyear;
    }

    void setID(){
        // need better solution to turn int into char
        id[0] = 'S';
        id[1] = 48 + (getCYear() % 100 /10);
        id[2] = 48 + (getCYear() % 10);
        id[3] = 48 + (rand() % 10);
        id[4] = 48 + (rand() % 10);
        id[5] = 48 + (rand() % 10);
        id[6] = 0;
        for(int i = 1; i < 6; i++){
            id[6] = id[6] + id[i] - 48;
        }
        id[6] = 48 + (id[6] % 10);
       /*
       for(int i = 0; i < strlen(id) - 1; i++){
            cout << "[" << i << "] " << id[i] << endl;
        }
        cout << id << endl;
       */     
    }

    private:
        char name[30]; // done
        char id[7]; //done
        char major[30];
        int year; // done
        int cohortyear; // done
        float gpa;
        char subjectcode[8][7]; //replace 1D with vector 
        char grade[8]; // replace with vector 
};

class subject{
    public:
    void setCredit(int input){
        credit = input;
    }

    private:
        char code[7];
        char subjectname[30];
        int credit;

};

int main(void){
    srand(randomseed);
    int response = 999; // set variable to hold user input;
    bool boo = false;
    do{
        printMenu(response, boo);
        switch (response)
        {
        case 1:
            std::cout << response << std::endl;
            boo = true;
            break;
        case 2:
            std::cout << response << std::endl;
            break;
        case 3:
            std::cout << response << std::endl;
            break;
        case 4:
            std::cout << response << std::endl;
            break;
        case 5:
            std::cout << response << std::endl;
            break;
        case 6:
            std::cout << "Quit?";
            break;
        default:
            std::cout << "Unexpected Input.";
            break;
        }
        system("pause");
        system("cls");
        //need better solution
    }while(response != 6);
    return 0;
}