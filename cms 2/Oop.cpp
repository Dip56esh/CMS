#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
class phone
{
    int id;
    string name;

    char address[20];

    long long ph_no;

public:
    void get();
    void add();
    void show();
    void search();
    void modify();
    void delete_data();
    void show_all();
};

void phone::get()
{
    
   // int id;
    



    cin.ignore();
    cout<<"enter the ID of the person"<<endl;
    cin>>id;
    cout << "Enter name.\n";
    getline(cin, name);
    cout << "Enter address.\n";
    cin >> address;
    cout << "Enter phone number." << endl;
    cin >> ph_no;
}

void phone::add()
{
    char ch;
    int i = 0;
    ofstream f1;
    f1.open("final1", ios::app | ios::out);

    do
    {
        system("cls");
        get();
        if (ph_no > 9600000000 && ph_no < 9899999999)
        {
            f1.write((char *)(this), sizeof(*this));
            //            cout<<"Do You Want Next Data?(y|n)"<<endl;
            //            cin>>ch;
            i == 1;
        }
        else
        {
            cout << "Invalid Number!" << endl;
            getch();
            cout<<"enter the phone number "<<endl;
            cin>>ph_no;
        f1.write((char *)(this), sizeof(*this));


        }
        cout << "Do You Want Next Data?(y|n)" << endl;
        cin >> ch;

    } while (ch == 'y');
    if (i == 1)
        cout << "Contact has been successfully created..." << endl;

    f1.close();
}

void phone::show()
{
    cout<<"ID   :"<<id<<endl;
    cout << "Name:" << name << endl;
    cout << "Address:" << address << endl;
    cout << "Phone no.:" << ph_no << endl
         << endl;
}

void phone::show_all()
{

    cout << "\n\n";
    fstream f2;

    f2.open("final1", ios::in);

    f2.seekg(0, ios::beg);

    while (f2.read((char *)(this), sizeof(*this)))

    {
        show();
        // i++;
    }

    f2.close();
    //            if(i==0)
    //                cout<<"No Record Found."<<endl;
    // }
}

void phone::search()
{

    fstream f3;
    int flag = 0;

    string tname;

    system("cls");
    cin.ignore();
    cout << "Enter name To search:" << endl;
    getline(cin, tname);
    f3.open("final1", ios::in);
    f3.seekg(0, ios::beg);
    while (!f3.eof())
    {

        if (f3.read((char *)(this), sizeof(*this)))
        {
            if (tname == name)
            {

                show();
                flag = 1;
            }
        }
    }
    if (flag != 1)
        cout << endl
             << "No record found!" << endl;
    f3.close();
}

void phone::modify()
{

    char ans;
    fstream f3;
    // int count=0;
    //string tname;
    int count;
    char taddress[25];
    long long tph_no;
    f3.open("final1", ios::in | ios::binary | ios::out);
    cin.ignore();
    cout << "\n\n\tEnter person Name whose record to be changed:";
    // getline(cin, tname);
    cin>>count;
    do
    {
        f3.read((char *)this, sizeof(*this));
        if (f3.eof() == 1)
        {
            break;
        }

        if (count == id)
        {
            cout << "Current Contact" << endl
                 << endl;
            show();
            cout << "\nEnter NEW Contact" << endl;
            cout << "Press Enter to Add" << endl;
            get();
        }
        //                        else
        //                            count=1;

        // int l=f3.tellg();
        int l = sizeof(*this);
        // f3.close();
        // f3.open("record.txt",ios::out|ios::binary|ios::ate);
        // f3.seekg(l-sizeof(*this));
        f3.seekp(-l, ios::cur);
        f3.write((char *)this, sizeof(*this));

    } while (!f3.eof());
    // if(count==)
    f3.close();
}

void phone::delete_data()
{
    string tname;
    int count = 0;
    fstream fin;
    ofstream fout;
    fin.open("final1", ios::in | ios::out);
    // fout.open("temp",ios::out|ios::app);
    fout.open("temp", ios::out);
    cin.ignore();
    cout << "\n\tDELETING...";
    cout << "\n\n\tEnter the name to delete: ";
    getline(cin, tname);
    fin.seekg(0, ios::beg);

    while (fin.read((char *)(this), sizeof(*this)))
    {

        if (tname != name)
        {

            fout.write((char *)this, sizeof(*this));
        }
        else
            count = 1;
    }

    fin.close();
    fout.close();
    remove("final1");
    rename("temp", "final1");

    if (count == 0)
    {
        cout << "Contact Not Found." << endl;
    }
    else
        cout << "Contact Deleted." << endl;
}

int main()
{
    system("cls");
    system("Color 3c");

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t*WELCOME TO CMS*" << endl;
    getch();
    while (1)
    {
        phone p1;
        int choice;
        system("cls");
        system("Color 94");

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
            cout << "\n\n\t\t\tTHANK YOU FOR USING CMS" << endl;
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
            cout << "\n\n\t\t\tTHANK YOU FOR USING CMS" << endl;

            exit(0);
        }
    }

    getch();

    return 0;
}
