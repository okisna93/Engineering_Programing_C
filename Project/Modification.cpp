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
    int status;
    string task;
    int deadline;

public:
    Project(){
        person.name="none";
        person.lastname="none";
        person.title="none";
        priority=0;
        status=0;
        task="none";
        deadline=0;
    }
    Project(Employee a,string t, int p, int s,int dl){
        person.name=a.name;
        person.lastname=a.lastname;
        person.title=a.title;
        priority=p;
        status=s;
        task=t;
        deadline=dl;
    }
    void assingTask(Employee p,string t, int pri,int s,int dl,string location){

        task=t;
        priority=pri;
        status=s;
        deadline=dl;

        person.name=p.name;
        person.lastname=p.lastname;
        person.title=p.title;

        fstream taskfile;
        taskfile.open(location,std::ios_base::app);
        taskfile<<person.name<<endl;
        taskfile<<person.lastname<<endl;
        taskfile<<pri<<endl;
        taskfile<<task<<endl;
        if(status==100){
            taskfile<<status<<"% Completed"<<endl;
        }else{
            taskfile<<status<<"% InProgress"<<endl;
        }
        taskfile<<Deadline(dl)<<endl; //Calling the deadline function
        taskfile.close();
    }

    //This function help us to add days to current date
    //For example, when we assign a task , we need to declare deadline in terms of days
    //If we declare deadline as 30 days, function automatically adds 30 days to current date and calculate the deadline date
    void DatePlusDays( struct tm* date, int days )
    {
        const time_t ONE_DAY = 24 * 60 * 60 ;

        // Seconds since start of epoch
        time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

        // Update caller's date
        // Use localtime because mktime converts to UTC so may change date
        *date = *localtime( &date_seconds ) ;
    }
    string Deadline(int days){
        time_t t = time(0);   // get time now
        tm* now = localtime(&t);

        // initializing the local date
        struct tm date = { 0, 0, 12 } ;
        int year = now->tm_year + 1900 ;
        int month = now->tm_mon + 1 ;
        int day = now->tm_mday ;

        // Set up the date structure
        date.tm_year = year - 1900 ;
        date.tm_mon = month - 1 ;  // note: zero indexed
        date.tm_mday = day ;       // note: not zero indexed

        // Adding days to current date
        DatePlusDays( &date, +days ) ;

        // Show time/date using default formatting
        char *deadline;
        deadline=new char[15];//Memory allocation for deadline date
        string d; // Loop through asctime(&date) to changing display format, get rid of from hours and only showing day,month,year
        int k=0;
        for(int i=0;i<strlen(asctime(&date));i++){
            if(i>=11 && i<=19){
            }
            else{
               deadline[k]=asctime(&date)[i];
               d.push_back(deadline[k]);
            }
        }
        delete []deadline; //releasing the memory
        return d ;//returning to string date format is: Fri Dec 16 2022
    }


//    void setStatus(bool a){
//        cout<<"What is the Status of the task (T/F)?"<<endl;
//        cout<<"Please Enter 1 if it's in progress, enter 0 if it's completed";
//
//        cin>>a;
//
//        if(a==true){
//            status="In Progress";
//        }else{
//            status="Completed";
//        }
//    }
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
    //Formating the outputs like a chart
    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;

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
        if(choice==1){
            system("cls");
            fstream n;
            n.open("EMPLOYEE.txt",std::ios_base::app);
            while(flag==true){
                char answer;
                cout<<"Do you want to add new employee to the system (y/n) : ";
                cin>>answer;
                if(answer=='n'){
                    flag=false;
                }else{
                    cout<<endl<<endl;
                    Employee b;
                    string a;
                    string c;
                    string k;
                    cout<<"Enter Name : ";
                    getline(cin>>ws,a);
                    b.setName(a);
                    cout<<"Enter LastName : ";
                    getline(cin>>ws,c);
                    b.setLastname(c);
                    cout<<"Enter Title : ";
                    getline(cin>>ws,k);
                    b.setTitle(k);

                    //cout<<"Employe Name and Title"<<endl;
                    //cout<<b.getName()<<" "<<b.getLastname()<<" "<<b.getTitle()<<endl;
                    n<<b.getName()<<endl;
                    n<<b.getLastname()<<endl;
                    n<<b.getTitle()<<endl;
                    cout<<endl<<endl;
                }


            }
            n.close();
        }
        if(choice==2){
            system("cls");
            fstream listing;
            listing.open("EMPLOYEE.txt");
            //cout<<"Name"<<setw(19)<<"Last Name"<<setw(15)<<"Title"<<endl;
            cout<<left<<setw(nameWidth) << setfill(separator) <<"Name";
            cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
            cout<<left<<setw(nameWidth) << setfill(separator) <<"Title"<<endl;
            cout<<"==============================================="<<endl;
            int x=1;
            string name;
            string lastname;
            string title;
            int result;
            while(getline(listing,name,'\n')&&
                  getline(listing,lastname,'\n')&&
                  getline(listing,title,'\n')){
                cout<<left<<setw(nameWidth)<< setfill(separator)<<name;
                cout<<left<<setw(nameWidth)<< setfill(separator)<<lastname;
                cout<<left<<setw(nameWidth)<< setfill(separator)<<title<<endl;
//                result=x%3;
//                if(result==0){
//                    cout<<endl;
//                }
//                x++;
            }
            cout<<endl<<"Please Press the ESC Button to go Back to Main Menu "<<endl;
            k=getch();
            if(k==ESC){
                listing.close();
                continue;
            }
        }
        if(choice==3){
            system("cls");
            fstream n;
            n.open("EMPLOYEE.txt");
            string na;
            string lname;
            string t;
            vector<Project> Team;
            while(getline(n,na,'\n')&&
                  getline(n,lname,'\n')&&
                  getline(n,t,'\n')){
                Project a;
                a.name=na;
                a.lastname=lname;
                a.title=t;
                Team.push_back(a);
            }

            for(int i=0;i<Team.size();i++){
                cout<<i+1<<" - "<<Team[i].name<<" "<<Team[i].lastname<<" "<<endl;//Team[i].task<<endl;
            }

            bool taskFlag=true;
            while(taskFlag==true){
                char ans;
                cout<<"Do you want to assign a task (y/n)";
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

                    cout<<"What is the status of the task(Percentage) : ";
                    int s;
                    cin>>s;

                    cout<<"Deadline (How many days ?) :";
                    int dl;
                    cin>>dl;


                    Team[selection-1].assingTask(Team[selection-1],taskWrite,z,s,dl,"TASK.txt");

                }

            }

            n.close();
        }
        if(choice==4){
            system("cls");
            while(1){
                cout<<left<<setw(0.60*nameWidth) << setfill(separator) <<"TaskId";
                cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Name";
                cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
                cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Priority";
                cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<"Status";
                cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<"Deadline";
                cout<<left<<setw(nameWidth) << setfill(separator) <<"Task"<<endl;
                cout<<"=================================================================================================="<<endl;

                fstream f;
                f.open("TASK.txt");
//                int x=1;
//                int y=4;
//                int result;
                string name;
                string lastname;
                string task;
                string priority;
                string status;
                string deadline;
                string empt;
                vector<Project> TrackStatus;
                int TaskId=0;
                while(getline(f,name,'\n')&&
                      getline(f,lastname,'\n')&&
                      getline(f,priority,'\n')&&
                      getline(f,task,'\n')&&
                      getline(f,status,'\n')&&
                      getline(f,deadline,'\n')&&
                      getline(f,empt)){
                    int pri;
                    int stat;
                    pri=stoi(priority); // Converting string priority to integer
                    if(stoi(status.substr(0, 3))>=100){  // Converting string status to integer
                        stat=100;
                    }else{
                        stat=stoi(status.substr(0, 2));
                    }
                    TaskId++;
                    cout<<left<<setw(0.60*nameWidth)<< setfill(separator)  <<TaskId;
                    cout<<left<<setw(0.75*nameWidth)<< setfill(separator)  <<name;
                    cout<<left<<setw(nameWidth)<< setfill(separator)  <<lastname;
                    cout<<left<<setw(0.75*nameWidth)<< setfill(separator)  <<priority;
                    cout<<left<<setw(1.5*nameWidth)<< setfill(separator)  <<status; ;
                    cout<<left<<setw(1.5*nameWidth)<< setfill(separator)  <<deadline;
                    cout<<left<<setw(nameWidth)<< setfill(separator)  <<task<<endl;
                    Project a;
                    a.name=name;
                    a.lastname=lastname;
                    a.priority=pri;
                    a.status=stat;
                    a.task=task;
                    TrackStatus.push_back(a);
                }
                while(1){
                    cout<<endl<<"Do you want to update your status (y/n) ? : ";
                    char answ;
                    answ=getch();
                    if(answ=='n'){
                        break;
                    }else{
                        cout<<endl<<"Please Enter the TaskId Number for Modification : ";
                        int selection;
                        cin>>selection;

                        cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Name";
                        cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
                        cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Priority";
                        cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<"Status"<<endl;
                        cout<<"=================================================="<<endl;

                        cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<TrackStatus[selection-1].name;
                        cout<<left<<setw(nameWidth) << setfill(separator) <<TrackStatus[selection-1].lastname;
                        cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<TrackStatus[selection-1].priority;
                        cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<TrackStatus[selection-1].status<<endl;
                        cout<<endl<<"Modify Status :";
                        int newStatus;
                        cin>>newStatus;
                        if(newStatus>=100){
                            newStatus=100;
                        }
                        cout<<endl<<"How Many Days Left for Deadline :";
                        int leftDeadline;
                        cin>>leftDeadline;
                        TrackStatus[selection-1].status=newStatus;
                        TrackStatus[selection-1].deadline=leftDeadline;
                    }
                    cout<<endl;
                }

                cout<<endl<<"===========AFTER MODIFICATION=============="<<endl;
                cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Name";
                cout<<left<<setw(nameWidth) << setfill(separator) <<"LastName";
                cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<"Priority";
                cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<"Status"<<endl;
                cout<<"==========================================="<<endl;
                for(int i=0;i<TrackStatus.size();i++){
                    cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<TrackStatus[i].name;
                    cout<<left<<setw(nameWidth) << setfill(separator) <<TrackStatus[i].lastname;
                    cout<<left<<setw(0.75*nameWidth) << setfill(separator) <<TrackStatus[i].priority;
                    cout<<left<<setw(1.5*nameWidth) << setfill(separator) <<TrackStatus[i].status<<endl;
                    TrackStatus[i].assingTask(TrackStatus[i],TrackStatus[i].task,TrackStatus[i].priority,TrackStatus[i].status,TrackStatus[i].deadline,"TASK1.txt");
                }

                k=getch();

                if(k==ESC){
                    break;
                }
                f.close();
            }

        }
        if(choice==5){
            system("cls");
            cout<<"Program Closed "<<endl;
            mainFunc=false;
        }


    }




    //Reading From File to Show Entered Data




    return 0;
}
