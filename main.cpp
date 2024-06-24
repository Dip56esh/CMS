#include <iostream>
#include <windows.h>
#include<mmsystem.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
const int MAX = 100;
class phone
{
    char name[MAX];
    char address[30];
    long long ph_no;
    int id;

public:
    void get();
    void add();
    void show();
    void search();
    void modify();
    void delete_data();
    void show_all();
    void get_name();
};

void phone::get_name()
{
    char c;
    int i = 0;
    while (cin.get(c) && c != '\n' && i < MAX - 1)
    {
        name[i] = c;
        i++;
    }
    name[i] = '\0';
}

void phone::get()
{

    cin.ignore();
    cout <<"Enter name.\n";
    get_name();
    cout << "Enter address.\n";
    cin >> address;
    cout << "Enter phone number." << endl;
    cin >> ph_no;
    cout<<"enter the ID"<<endl;
    cin>>id;
}

void phone::add()
{
    char ch;
     bool a=false;
    fstream f;
    f.open("main.txt", ios::out | ios::app);

    do
    {
        system("cls");
        get();
        a=false;
        if (ph_no >= 9600000000 && ph_no <= 9899999999)
        {
            f.write((char *)(this), sizeof(*this));
         a=true;
        }
        else
        {
            cout << "Invalid Number!" << endl;
            PlaySound(TEXT("invalid number.wav"),NULL,SND_SYNC);

            cout<<"Re enter the number"<<endl;
            cin>>ph_no;
            //cout<<"\t\t";

             
             f.write((char *)(this),sizeof(*this));

        }


    
   


          
    
        cout << "Do You Want Next Data?(y|n)" << endl;
        cin >> ch;

     } while (ch == 'y');
    if (a != false){
	
        cout << "Contact has been successfully created..." << endl;
         PlaySound(TEXT("contact created.wav"),NULL,SND_SYNC);

} f.close();

}


void phone::show()
{
    cout <<endl<< "Name:" << name << endl;
    cout << "Address:" << address << endl;
    cout << "Phone no.:" << ph_no << endl;
    cout<<" ID :"<<id<<endl
         << endl;
}

void phone::show_all()
{
    int i=0;
    cout << "\n";
    ifstream f;
    char c;
    f.open("main.txt");

    f.seekg(0, ios::beg);
    while (f.read((char *)(this), sizeof(*this)))
    {
        show();
        i++;
    }

    f.close();
    if(i==0)
    {
        cout<<"No Record Found!!"<<endl;
        PlaySound(TEXT("contact not found.wav"),NULL,SND_SYNC);
    }

}

void phone::search()
{

    fstream f;
    int flag = 0;
    char tname1[MAX];

    system("cls");
    cout << "Enter name To search:" << endl;
    cin.ignore();
    char c;
    int i = 0;
    while (cin.get(c) && c != '\n' && i < MAX - 1)
    {
        tname1[i] = c;
        i++;
    }
    tname1[i] = '\0';
    f.open("main.txt", ios::in);
    f.seekg(0, ios::beg);
    while (!f.eof())
    {

        if (f.read((char *)(this), sizeof(*this)))
        {
            if (strcmp(name, tname1) == 0)
            {

                show();
                flag = 1;
            }
        }
    }
    if (flag != 1){
	
        cout << endl
             << "No record found!" << endl;
             PlaySound(TEXT("contact not found.wav"),NULL,SND_SYNC);
         }
    f.close();
}

void phone::modify()
{

    char ans;
    fstream f;
    int i = 0, j = 0, k = 0;
    char tname1[MAX];
    char taddress[25];
    long long tph_no;

    f.open("main.txt", ios::in | ios::out);
    cout << "\n\n\tEnter person Name whose record to be changed:";

    cin.ignore();
    char c;
    int p = 0;
    while (cin.get(c) && c != '\n' && i < MAX - 1)
    {
        tname1[p] = c;
        p++;
    }
    tname1[p] = '\0';

    do
    {
        f.read((char *)this, sizeof(*this));

        if (strcmp(name, tname1) == 0&&k==0)
        {
            k = 1;

            cout << "Current Contact" << endl
                 << endl;
            show();
        level:

            if (j == 0)
            {
                cout << "Press Enter to Add" << endl;
            }
            else
            {
                cout << "\nEnter NEW Contact" << endl;
            }
            get();
            
            if (ph_no >= 9600000000 && ph_no <= 9899999999)
            {

                int l = sizeof(*this);
                f.seekp(-l, ios::cur);
                f.write((char *)this, sizeof(*this));
                i = 1;
            }
            else
            {
                system("cls");
                cout << "Invalid Number!" << endl;
                PlaySound(TEXT("invalid number.wav"),NULL,SND_SYNC);
                j = 1;
                goto level;
            }
        }

    } while (!f.eof());

    if (i == 1)
    {
        cout << "Contact Modified." << endl;
         PlaySound(TEXT("contact modified.wav"),NULL,SND_SYNC);
    }
    else if (k == 0)
    {
        cout << "No Matching Record Found!" << endl;
        PlaySound(TEXT("contact not found.wav"),NULL,SND_SYNC);
    }

    f.close();
}

void phone::delete_data()
{
    char tname1[MAX];
    int count = 0;
    fstream fin;
    fstream fout;

    fin.open("main.txt", ios::in);
    fout.open("temp_main.txt", ios::out);

    cout << "\n\tDELETING...";
    cout << "\n\n\tEnter the name to delete: ";

    cin.ignore();
    char c;
    int i = 0;
    while (cin.get(c) && c != '\n' && i < MAX - 1)
    {
        tname1[i] = c;
        i++;
    }
    tname1[i] = '\0';
    fin.seekg(0, ios::beg);

    while (fin.read((char *)(this), sizeof(*this)))
    {
        if (strcmp(name, tname1) != 0)
        {

            fout.write((char *)this, sizeof(*this));
        }
        else
            count = 1;
    }

    fin.close();
    fout.close();
    remove("main.txt");
    rename("temp_main.txt", "main.txt");

    if (count == 0)
    {
        cout << "Contact Not Found." << endl;
        PlaySound(TEXT("contact not found.wav"),NULL,SND_SYNC);
    }
    else{
	
        cout << "Contact Deleted." << endl;
         PlaySound(TEXT("contact deleted.wav"),NULL,SND_SYNC);
}
}

int main()
{
    system("cls");
    system("Color 2c");

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t*WELCOME TO TELEPHONE DIRECTORY*" << endl;
    getch();
     PlaySound(TEXT("welcome.wav"),NULL,SND_SYNC);
    while (1)
    {
        phone p1;
        int choice;
        system("cls");
        system("Color 1f");

        cout << "###### CONTACT MANAGEMENT SYSTEM ######" << endl;
    x:
        cout << "\nMAIN MENU:" << endl;
        cout << "=====================" << endl;
        cout << "[1] ADD" << endl;
        cout << "[2] List All Contacts" << endl;
        cout << "[3] SEARCH" << endl;
        cout << "[4] MODIFY" << endl;
        cout << "[5] DELETE" << endl;
        cout << "[0] EXIT" << endl;
        cout << "=====================" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        char ans;
        switch (choice)
        {
        case 1:
            system("cls");
            p1.add();

            break;

        case 2:
            system("cls");
            p1.show_all();

            break;

        case 3:
            system("cls");
            p1.search();

            break;

        case 4:
            system("cls");
            p1.modify();

            break;

        case 5:
            system("cls");
            p1.delete_data();

            break;

        case 0:
            system("cls");
            cout << "\n\n\t\t\t\tTHANK YOU FOR USING TELEPHONE DIRECTORY" << endl;
             PlaySound(TEXT("thank you.wav"),NULL,SND_SYNC);
             
            getch();
            exit(0);
            break;
        }

        cout << "\n\tGo To Main Menu(Y|N)" << endl;
        ans = getch();
        system("cls");
        if (ans == 'Y' || ans == 'y')
        {
            goto x;
        }
        else
        {
            system("cls");
            cout << "\n\n\t\t\t\tTHANK YOU FOR USING CMS" << endl;
             PlaySound(TEXT("thank you.wav"),NULL,SND_SYNC);
            getch();
            exit(0);
        }
    }

    getch();

    return 0;
}
