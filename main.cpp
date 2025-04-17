#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

const int randomseed = 5; // random seed for start data R1.1 student id part
const int yearnow = 2025; // will use ctime lib to replace it. get year of system data. extra part

int printMenu(int &x, bool &enabled){
    cout << "All hail Ken Tsang.\n";
    cout << "*** SMS Main Menu ***\n";
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show Student Records\n";
    cout << "[3] Add/Delete Students\n";
    cout << "[4] Edit Students\n";
    cout << "[5] Generate Transcript\n";
    cout << "[6] Credits and Exit\n";
    cout << "*************\n";
    cout << "Option (1 - 6): ";
    cin.clear();
    cin >> x; //get user input
    if (!(enabled) && ((x >= 2) || (x <= 5)) && (x != 1)){
        // show error only when data is not loaded and user using function 2~5. R1.2
        cout << "Starting data is not yet loaded. Please load starting data first!\n";
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
    // set
    void setAlldata(char input1[], char input2[], char input3[]){
        setIDM(input1);
        setName(input2);
        setMajor(input3);
        setYearM();
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
       for(int i = 0; i < strlen(id) - 1; i++){
            cout << "[" << i << "] " << id[i] << endl;
        }
        cout << id << endl;
    }
    void setIDM(char input[]){
        for(int i = 0; i < 7; i++){
            id[i] = input[i];
        }
    }

    void setYear(int input){
        cohortyear = input;
        year = (yearnow - cohortyear);
    }
    void setYearM(){
        cohortyear = (id[1] - 48)* 10 + (id[2] - 48);
        year = getYear();
    }

    void setName(char input[]){
        for(int i = 0; i < 30; i++){
            name[i] = input[i];
        } // use for loop to ensure that only 30 char will be entered into name
    }
    void setMajor(char input[]){
        for(int i = 0; i < 30; i++){
            major[i] = input[i];
        }
    }

    // get
    int getYear(){
        return (yearnow - (cohortyear + 2000));
    }
    int getCYear(){
        return cohortyear;
    }
    string getName(){
        return name;
    }
    string getMajor(){
        return major;
    }
    string getID(){
        return id;
    }

    // misc
    void showInfo(){
        cout << getName() << "\t";
        cout << getID() << "\t";
        cout << getYear() << "\t";
        cout << getMajor() << "\t";
        cout << endl;
    }
    private:
        char name[30]; // need better solution to characters limit
        char id[8]; //done
        char major[30]; // need better solution to characters limit
        int year; // done, locked and cannot be decided by user
        int cohortyear; // done, user input
        float gpa;
        char subjectcode[8][7]; //replace 1D with vector
        char grade[8][2]; // replace with vector
};

class Subject{
    public:
    // set
    void setAllData(int input1, char input2[], char input3[]){
        setCredit(input1);
        setSubjectCode(input2);
        setSubjectName(input3);
    }
    void setCredit(int input){
        credit = input;
    }
    void setSubjectCode(char input[]){
        for(int i = 0; i < 7; i++){
            subjectcode[i] = input[i];
        }
    }
    void setSubjectName(char input[]){
        for(int i = 0; i < 40; i++){
            subjectname[i] = input[i];
        }
    }
    void loadData(){

    }

    // get
    int getCredit(){
        return credit;
    }

    private:
        char subjectcode[7];
        char subjectname[40];
        int credit;
};

void showInfoHeader(){
    cout << "Name" << setw(31-4) << "ID" << setw(8-2) << "Year" << setw(8) << "Major" << endl;
    cout << "************************************************************************" << endl;
}

double getgradepoints(char input[2]){
    int i = 373, j = 242;
    float grade[5][3] = {
        {4.3, 4.0, 3.7},
        {3.3, 3.0, 2.7},
        {2.3, 2.0, 1.7},
        {1.3, 1.0, 0  },
        {0  , 0  , 0  }};
    switch (input[1]){ // solution to shorten it
        case '+': j = 0; break;
        case '-': j = 2; break;
        default : j = 1; break;
    } //
    switch (input[0]){ // solution to shorten it
        case 'A': i = 0; break;
        case 'B': i = 1; break;
        case 'C': i = 2; break;
        case 'D': i = 3; break;
        default : i = 4; break;
    } //
    return grade[i][j];
}

int main(void){
    srand(randomseed);
    int stuindex = 0;
    int subindex = 0;
    int response = 999; // set variable to hold user input;
    char inputc[2];
    bool boo = true; // change to false at end
    do{
        printMenu(response, boo);
        switch (response)
        {
        case 1:
            cout << response << endl;
            Student studentdata[100];
            Subject subjectdata[100];
            studentdata[stuindex].setAlldata("S243560", "CHAN Tai Man", "Information Engineering");
            stuindex = stuindex + 1;
            studentdata[stuindex].setAlldata("S232210", "CHEUNG Jacky", "Civil Engineering");
            stuindex = stuindex + 1;
            studentdata[stuindex].setAlldata("S222343", "PAN Peter", "Global Business");
            stuindex = stuindex + 1;
            studentdata[stuindex].setAlldata("S244617", "WONG Kam", "Educational Psychology");
            stuindex = stuindex + 1;

            subjectdata[subindex].setAllData(3, "ENG2042", "Introduction to C++");
            subindex = subindex + 1;


            boo = true;
            break;
        case 2:
            cout << response << endl;
            showInfoHeader();
            for(int i = 0; i < stuindex; i++){
                studentdata[i].showInfo();
            }
            break;
        case 3:
            cout << response << endl;
            break;
        case 4:
            cout << response << endl;
            break;
        case 5:
            cout << response << endl;
            break;
        case 6:
            cout << "Quit?";
            break;
        case 7: //debug
            cout << "debug" << endl;
            break;
        default:
            cout << "Unexpected Input.";
            break;
        }
        system("pause");
        system("cls");
        //need better solution
    }while(response != 6);
    return 0;
}
