#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#define esc 27

using namespace std;

class Employee{
public:
    string name;
    string lastname;
    string title;
public:
    Employee(){

    }
    void setName(string n){
        name=n;
    }
    string getName(){
        return name;
    }

    void setLastname(string l){
        lastname=l;
    }
    string getLastname(){
        return lastname;
    }

    void setTitle(string t){
        title=t;
    }
    string getTitle(){
        return title;
    }
};

ostream& operator<<(ostream& ostr, Employee a){
    ostr<<a.name<<","<<a.lastname<<","<< a.title;
    return ostr;
}


class Project:public Employee{
public:
    Employee person;
    int priority;
    string status;
    string task;

public:
    Project(){
        person.name="none";
        person.lastname="none";
        person.title="none";
        priority=0;
        status="none";
        task="none";
    }
    Project(Employee a,string t, int p, string s){
        person.name=a.name;
        person.lastname=a.lastname;
        person.title=a.title;
        priority=p;
        status=s;
        task=t;
    }
    void assingTask(Employee p,string t, int pri){

        task=t;
        priority=pri;

        person.name=p.name;
        person.lastname=p.lastname;
        person.title=p.title;

        fstream taskfile;
        taskfile.open("TASK.txt",std::ios_base::app);
        taskfile<<person.name<<endl;
        taskfile<<person.lastname<<endl;
        taskfile<<pri<<endl;
        taskfile<<task<<endl;
        taskfile.close();
    }
    void showTask(string location){

    }

    string getTask(){
        return task;
    }
    void setStatus(bool a){
        cout<<"What is the Status of the task (T/F)?"<<endl;
        cout<<"Please Enter 1 if it's in progress, enter 0 if it's completed";

        cin>>a;

        if(a==true){
            status="In Progress";
        }else{
            status="Completed";
        }
    }
    string getStatus(){
        return status;
    }
};

ostream& operator<<(ostream& ostr, Project team){
    ostr<<team.name<<" "<<team.lastname<<"   "<<team.title<<"   "<<team.priority<<"   "<<team.status<<"   "<<team.task<<endl;;
    return ostr;
}


// Global Variable
COORD coord = {0,0}; // 0,0 Coordinate is top left-hand side of the screen
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){
    const int ESC=27;  // Using ESC Button for Returning to Main Menu
    char k; // For User Input to Detect Whether ESC is Pressed
    bool mainFunc=true;
    while(mainFunc){

        system("cls");
        gotoxy(30,10); // move the cursor to postion 30, 10 from top-left corner
        cout<<"1. Add New Employee"; // Add new employee to the system
        gotoxy(30,12);
        cout<<"2. List Employee Records"; // Show Team Members and Their Titles
        gotoxy(30,14);
        cout<<"3. Assign Task"; // Assign task to the employee
        gotoxy(30,16);
        cout<<"4. Show Task Tracking"; // Show the main frame of the task tracing
        gotoxy(30,18);
        cout<<"5. Exit"; // exit from the program
        gotoxy(30,20);
        cout<<"Your Choice: "; // enter the choice 1, 2, 3, 4, 5
        int choice;
        cin>>choice;


        //Entering New Employee Record to the file
        bool flag=true;
        fstream n;
        n.open("EMPLOYEE.txt");

        if(choice==1){
            system("cls");
            while(flag==true){
                Employee b;
                string a;
                string c;
                string k;
                cout<<"Enter Name : ";
                cin>>a;
                b.setName(a);
                cout<<"Enter LastName : ";
                cin>>c;
                b.setLastname(c);
                cout<<"Enter Title : ";
                cin>>k;
                b.setTitle(k);

                //cout<<"Employe Name and Title"<<endl;
                //cout<<b.getName()<<" "<<b.getLastname()<<" "<<b.getTitle()<<endl;
                n<<b.getName()<<" "<<b.getLastname()<<" "<<b.getTitle()<<endl;

                cout<<endl<<endl;
                char answer;
                cout<<"Do you want to add new employee to the system (y/n) : ";
                cin>>answer;
                if(answer=='n'){
                    flag=false;
                }
            }
        }
        if(choice==2){
            system("cls");
            string name;
            string lastname;
            string title;
            cout<<"Name"<<setw(19)<<"Last Name"<<setw(15)<<"Title"<<endl;
            cout<<"=========================================="<<endl;
            while(!n.eof()){
                n>>name>>lastname>>title;
                cout<<name<<setw(20-name.size())<<lastname<<setw(17)<<title<<endl;
            }
            cout<<endl<<"Please Press the ESC Button to go Back to Main Menu "<<endl;
            k=getch();
            if(k==ESC){
                continue;
            }
        }
        if(choice==3){
            system("cls");
            string na;
            string lname;
            string t;
            vector<Project> Team;
            while(!n.eof()){
                n>>na>>lname>>t;
                Project a;
                a.name=na;
                a.lastname=lname;
                a.title=t;
                Team.push_back(a);
            }

            for(int i=0;i<Team.size();i++){
                cout<<i+1<<" - "<<Team[i].name<<" "<<Team[i].lastname<<" "<<Team[i].task<<endl;
            }

            bool taskFlag=true;
            while(taskFlag==true){
                char ans;
                cout<<"Do you want to assign more task (y/n)";
                cin>>ans;
                if(ans=='n'){
                    taskFlag=false;
                }else{
                    int selection;
                    cout<<"Please Select the Person's Number You Want to Assign a Task : ";
                    cin>>selection;

                    int z;
                    cout<<"What is the priority level : ";
                    cin>>z;

                    cout<<"What is the task : ";
                    string taskWrite;
                    getline(cin>>ws,taskWrite);

                    Team[selection-1].assingTask(Team[selection-1],taskWrite,z);

                }

            }

            //cout<<endl<<endl<<"SHOW WHOLE TEAM"<<endl;
            //cout<<"================================="<<endl;
            //for(int i=0;i<Team.size();i++){
                //cout<<Team[i]<<endl;
            //}

            const char separator    = ' ';
            const int nameWidth     = 15;
            const int numWidth      = 15;
            cout<<left<<setw(nameWidth) << setfill(separator) <<"Name";
            cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
            cout<<left<<setw(nameWidth) << setfill(separator) <<"Priority";
            cout<<left<<setw(nameWidth) << setfill(separator) <<"Task"<<endl;
            cout<<"========================================================"<<endl;
            for(int i=0;i<Team.size();i++){
                cout<<left<<setw(nameWidth) << setfill(separator) <<Team[i].name;
                cout<<left<<setw(nameWidth) << setfill(separator) <<Team[i].lastname;
                cout<<left<<setw(nameWidth) << setfill(separator) <<Team[i].priority;
                cout<<left<<setw(nameWidth) << setfill(separator) <<Team[i].getTask()<<endl;
            }



    //        if(selection==1){
    //            Team[0].assingTask()
    //        }

        }
        if(choice==4){
            system("cls");
            while(1){
                const char separator    = ' ';
                const int nameWidth     = 15;
                cout<<left<<setw(nameWidth) << setfill(separator) <<"Name";
                cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
                cout<<left<<setw(nameWidth) << setfill(separator) <<"Priority";
                cout<<left<<setw(20) << setfill(separator) <<"Task"<<endl;
                cout<<"=============================================================="<<endl;

                ifstream f;
                f.open("TASK.txt");
                int x=1;
                int y=4;
                int result;
                string line;
                while(getline(f,line)){
                    cout<<left<<setw(nameWidth)<< setfill(separator)  <<line;
                    result=x%4;
                    if(result==0){
                        cout<<endl;
                    }
                    x++;
                }
                cout<<"Please Enter ESC to go back to Main Menu"<<endl;


                k=getch();

                if(k==ESC){
                    break;
                }
                f.close();
            }

        }
        if(choice==5){
            system("cls");
            n.close(); // Closing the file Employee record file
            cout<<"Program Closed "<<endl;
            mainFunc=false;
        }


    }




    //Reading From File to Show Entered Data




    return 0;
}
