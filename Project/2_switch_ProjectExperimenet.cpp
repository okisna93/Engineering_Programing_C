#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

COORD coord = {0,0}; // Coordinate of  top-left corner of window

FILE *fp, *ft; /// file pointers
char another, choice;
long int recsize; /// size of each record of employee
//struct emp e; /// structure variable creation


void SetColor(int ColorValue)
//This function changes text colors.
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ColorValue & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void BackgroundColor(int ColorValue, int BColorValue)
{
     WORD wColor = ((BColorValue & 0x0F) << 4) + (ColorValue & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


struct emp
{
    string name;
    string lastname;
    string title;
};


int main(){



    //Creating and Opening file to save the records in the file
    fp = fopen("EMP2.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP2.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }



    // infinite loop continues untile the break statement encounter
    SetColor(45);
    BackgroundColor(45,10);

    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 1000;
    fontex.dwFontSize.X = 20;
    fontex.dwFontSize.Y = 20;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);

    bool flag=true;
    bool mainMenu=true;
    //fstream file;
    //file.open("EMPLOYEE.txt");

    while(mainMenu==true){
        system("cls"); //clear the console window
        gotoxy(50,7); //Setting Location for our text
        printf("1. Add Employee"); // option for add record
        gotoxy(50,9);
        printf("2. Show Team Members"); // option for showing existing record
        gotoxy(50,11);
        printf("3. Assign Task"); // option for editing record
        gotoxy(50,13);
        printf("4. Modify Status"); // option for deleting record
        gotoxy(50,15);
        printf("5. Exit"); // exit from the program
        gotoxy(50,17);
        printf("Enter a Number to Choose: "); // enter the choice 1, 2, 3, 4, 5
        emp e[3];
        int i=0;
        fflush(stdin); // flush the input buffer
        choice  = getche(); // get the input from keyboard
        char another;

        switch(choice){
            case '1':
                system("cls");
                while(flag==true){
                    cout<<"\nEnter Name: ";
                    cin>>e[i].name;
                    cout<<"\nEnter Lastname: ";
                    cin>>e[i].lastname;
                    cout<<"\nEnter Title: ";
                    cin>>e[i].title;

                    fwrite(&e[i],sizeof(e[i]),1,fp); // write the record in the file

                    printf("\nDo you wanna add another record (y/n) ");
                    i++;
                    fflush(stdin);
                    cin>>another;

                    if(another='n'){
                        flag=false;
                    }else{
                        continue;
                    }
                }break;
            case '2':
                system("cls");
                rewind(fp);
                int a=0;
                while(fread(&e,sizeof(e[i]),1,fp)==1)  // read the file and fetch the record one record per fetch
                {
                    cout<<e[i].name<<" "<<e[i].lastname<<" "<<e[i].title; // print the name, age and basic salary
                    a++;
                }break;

        }//switch ends

    }//main while loop

    return 0;
}
