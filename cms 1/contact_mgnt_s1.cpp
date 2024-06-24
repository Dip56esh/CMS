#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class phone
{
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
{   cin.ignore();
     cout<<"Enter name.\n";
        getline(cin,name);
        cout<<"Enter address.\n";
        cin>>address;
        cout<<"Enter phone number."<<endl;
        cin>>ph_no;

}

void phone::add()
{
     char ch;
        fstream f1;
        f1.open("rec.txt",ios::binary|ios::app|ios::in|ios::out|ios::ate);
        //f1.open("record.txt",ios::binary|ios::app);
        do{
                system("cls");
            get();

           // f1.write(reinterpret_cast<char*>(this),sizeof(*this));
            f1.write((char*)(this),sizeof(*this));
            cout<<"Do You Want Next Data?(y|n)"<<endl;
            cin>>ch;


        }while(ch=='y');
        cout<<"Contact has been successfully created..."<<endl;
        f1.close();

}

void phone::show()
{
    cout<<"\t\tName:"<<name<<endl;
    cout<<"\t\tAddress:"<<address<<endl;
    cout<<"\t\tPhone no.:"<<ph_no<<endl<<endl;
}

void phone::show_all()
{

     cout<<"\n\n";
            fstream f2;

            f2.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
          // f2.open("record.txt",ios::out);
           // if(f2.peek()==fstream::traits_type::eof())
           // {
             //   cout<<"No Record."<<endl;
           // }
           // else{
            f2.seekg(0);

            while(f2.read((char*)(this),sizeof(*this)))
            {
                show();
            }

            f2.close();
           // }


}

void phone::search()
{

     ifstream f3;
        int flag=0;

        string tname;

     system("cls");
     cin.ignore();
             cout<<"Enter name To search:"<<endl;
        getline(cin,tname);
        f3.open("rec.txt",ios::binary);
        while(!f3.eof())
        {
           // if(f3.read(reinterpret_cast<char*>(this),sizeof(*this)))
           if(f3.read((char*)(this),sizeof(*this)))
            {
                if(tname==name)
                {

                    show();
                    flag =1;

                }


            }

        }
        if(flag!=1)
       cout<<endl<<"No record found"<<endl;
        f3.close();



}


void phone::modify()
{

    char ans;
                fstream f3;
                //int count=0;
                string tname;
                char taddress[25];
                long long tph_no;
                f3.open("rec.txt",ios::in|ios::binary|ios::out);
                cin.ignore();
                cout<<"\n\n\tEnter person Name whose record to be changed:";
                getline(cin,tname);
                do
                {
                    f3.read((char *)this,sizeof(*this));
                    if(f3.eof()==1)
                    {
                        break;
                    }

                    if(tname==name)
                    {
                        cout<<"Current Contact"<<endl<<endl;
                        show();
                        cout<<"\nEnter NEW Contact"<<endl;
                        cout<<"Press Enter to Add"<<endl;
                        get();

                    }
//                        else
//                            count=1;

                       // int l=f3.tellg();
                       int l=sizeof(*this);
                       // f3.close();
                        //f3.open("record.txt",ios::out|ios::binary|ios::ate);
                        //f3.seekg(l-sizeof(*this));
                        f3.seekp(-l,ios::cur);
                        f3.write((char *)this,sizeof(*this));

                }
                while(!f3.eof());
               // if(count==)
                f3.close();
}

void phone::delete_data()
{
                string tname;
                int count=0;
                ifstream fin;
                 ofstream fout;
                 fin.open("rec.txt",ios::in|ios::binary);
                 fout.open("temp.txt",ios::out|ios::binary);
                cin.ignore();
                cout<<"\n\tDELETING...";
                cout<<"\n\n\tEnter the name to delete: ";
                getline(cin,tname);


                while (fin.read((char*)(this), sizeof(*this)))
                 {

                    if (tname!=name)
                    {

                     fout.write((char*)this, sizeof(*this));
                    }
                 }

                fin.close();
                fout.close();
                 remove("rec.txt");
                 rename("temp.txt", "rec.txt");
               // cout << "\tEntry is deleted.\n";
//              if(count==0)
//               {
//                   cout<<"Contact Not Found."<<endl;
//               }
              // else
               // cout<<"Contact Deleted."<<endl;
}


int main()
{
     system("cls");
    system("Color 3c");

    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t*WELCOME TO CMS*"<<endl;
    getch();
    while(1){
        phone p1;
        int choice;
        system("cls");
        system("Color 94");

        cout<<"###### CONTACT MANAGEMENT SYSTEM ######"<<endl;
          x: 
          cout<<"\nMAIN MENU:"<<endl;
            cout<<"====================="<<endl;
            cout<<"[1] ADD"<<endl;
            cout<<"[2] List All Contacts"<<endl;
            cout<<"[3] SEARCH"<<endl;
            cout<<"[4] MODIFY"<<endl;
            cout<<"[5] DELETE"<<endl;
            cout<<"[0] EXIT"<<endl;
            cout<<"====================="<<endl;

        cout<<"Enter your choice"<<endl;
        cin>>choice;
        char ans;
        switch(choice)
        {
            case 1:
            system("cls");
            p1.add();
            cout<<"do you want to continue"<<endl;
            ans=getch();
            system("cls");
            if(ans=='Y' || ans=='y')
            {
                goto x;
            }
            
            break;

            case 2:
            system("cls");
            p1.show_all();
            cout<<"do you want to continue"<<endl;
            ans=getch();
            system("cls");
            if(ans=='Y' || ans=='y')
            {
                goto x;
            }


            break;

             case 3:
            system("cls");
            p1.search();
            cout<<"do you want to continue"<<endl;
            ans=getch();
            system("cls");
            if(ans=='Y' || ans=='y')
            {
                goto x;
            }

            break;

             case 4:
            system("cls");
            p1.modify();

            cout<<"do you want to continue"<<endl;
            ans=getch();
            system("cls");
            if(ans=='Y' || ans=='y')
            {
                goto x;
            }

            break;

             case 5:
            system("cls");
            p1.delete_data();

            cout<<"do you want to continue"<<endl;
            ans=getch();
            system("cls");
            if(ans=='Y' || ans=='y')
            {
                goto x;
            }

            break;

             case 0:
            system("cls");
            cout<<"\n\n\t\t\tTHANK YOU FOR USING CMS"<<endl;
            exit(0);
            break;

        }

        int opt;

        cout<<"\n\n::Enter the choice:\n[0] Exit\t\t[1] Main Menu\n";
        cin>>opt;

        switch (opt)
        {
        case 0:
            system("cls");
            cout<<"\n\n\t\t\tTHANK YOU FOR USING CMS"<<endl;
            exit(0);
            break;


        default:
            continue;


        }
    }
    getch();

return 0;
}
