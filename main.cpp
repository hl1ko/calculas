#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
using std::string;

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
        x = 819; // main switch case 819 output "Starting data is not yet loaded. Please load starting data first!\n"
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
        char temp[8];
        temp[0] = 'S';
        temp[1] = 48 + (getCYear() % 100 /10);
        temp[2] = 48 + (getCYear() % 10);
        temp[3] = 48 + (rand() % 10);
        temp[4] = 48 + (rand() % 10);
        temp[5] = 48 + (rand() % 10);
        for(int i = 1; i < 6; i++){
            temp[6] = temp[6] + temp[i] - 48;
        }
        temp[6] = 48 + (temp[6] % 10);
        id = temp;
    }
    void setIDM(string input){
        id = input;
    }

    void setYear(int input){
        cohortyear = input;
        year = (yearnow - cohortyear);
    }
    void setYearM(){
        cohortyear = (id[1] - 48)* 10 + (id[2] - 48);
        year = getYear();
    }

    void setName(string input){
        name = input;
    }
    void setMajor(string input){
        major = input;
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
        string name; // need better solution to characters limit
        string id; //done
        string major; // need better solution to characters limit
        int year; // done, locked and cannot be decided by user
        int cohortyear; // done, user input
        float gpa;
        string subjectcode[8]; //replace 1D with vector
        string grade[8]; // replace with vector
};

class Subject{
    public:
    // set
    void setAllData(int input1, string input2, string input3){
        setCredit(input1);
        setSubjectCode(input2);
        setSubjectName(input3);
    }
    void setCredit(int input){
        credit = input;
    }
    void setSubjectCode(string input){
        subjectcode = input;
    }
    void setSubjectName(string input){
        subjectname = input;
    }
    void loadData(){

    }

    // get
    int getCredit(){
        return credit;
    }

    private:
    string subjectcode;
    string subjectname;
    int credit;
};

void showInfoHeader(){
    cout << "Name" << setw(31-4) << "ID" << setw(8-2) << "Year" << setw(8) << "Major" << endl;
    cout << "************************************************************************" << endl;
}

double getgradepoints(string input){
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
    Student testsubject;
    int response = 999; // set variable to hold user input;
    string inputc;
    bool boo = false;
    do{
        printMenu(response, boo);
        switch(response){
        case 1:
            cout << "debug output: " << response << endl;
            testsubject.setMajor("something");
            cout << testsubject.getMajor() << endl;
            testsubject.setName("goodname");
            cout << testsubject.getName() << endl;
            testsubject.setYear(2024);
            testsubject.setID();
            cout << testsubject.getID() << endl;
            testsubject.setIDM("S234551");
            cout << testsubject.getID() << endl;
            cin >> inputc;
            cout << getgradepoints(inputc);
            /*
            cout << response << endl;
            Student studentdata[100];
            Subject subjectdata[100]; //bugs in gpp complier.
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
            */

            boo = true;
            break;
        case 2:
            cout << "debug output: " << response << endl;
            showInfoHeader();
            for(int i = 0; i < stuindex; i++){
                //studentdata[i].showInfo();
            }
            break;
        case 3:
            cout << "debug output: " << response << endl;
            break;
        case 4:
            cout << "debug output: " << response << endl;
            break;
        case 5:
            cout << "debug output: " << response << endl;
            break;
        case 6:
            cout << "Quit?";
            break;
        case 7: //debug
            cout << "debug" << endl;
            break;
        case 819:
            cout << "Starting data is not yet loaded. Please load starting data first!\n";
            break;
        default:
            cout << "Unexpected Input.";
            break;
        }
        system("pause");
        cout << flush;
        //need better solution
    }while(response != 6);
    return 0;
}
