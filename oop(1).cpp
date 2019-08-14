#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include<iomanip>
#include <time.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class email
{

public:
    email()
    {

    fstream start;
    start.open("data.csv");
    if(!start)
    {
        start<<"NAME"<<',';
        start<<"MOBILE NO"<<',';
        start<<"EMAIl ID"<<',';
        start<<"COUNTRY"<<',';
        start<<"GENDER"<<',';
        start<<"DATE OF BIRTH"<<endl;
    }
    start.close();
    }

    void ad();
    void add(string );
    void srch();
    void display();
    void del();
    void modify();
};

void email::display()
{
    fstream op;
    string line;
    op.open("data.csv");
    cout<<fixed;
    int i=0;
    cout<<"\033[1;31m";
    cout<<"\n==================================================================================================\n";
    while(op)
    {
        cout<<endl;
        if(i==0)
        {
            cout<<"\033[21;33m";
        }

        getline(op,line,',');
        cout<<left<<setw(20)<<line;
        getline(op,line,',');
        cout<<left<<setw(20)<<line;
        getline(op,line,',');
        cout<<left<<setw(30)<<line;
        getline(op,line,',');
        cout<<left<<setw(10)<<line;
        getline(op,line,',');
        cout<<left<<setw(10)<<line;
        getline(op,line,'\n');
        cout<<left<<setw(10)<<line<<endl;
        if(i==0)
        {
            cout<<"\033[1;31m";
            cout<<"\n==================================================================================================\n";
            cout<<"\033[0;37m";
            i++;
        }

    }
    cout<<"\033[1;31m";
    cout<<"\n==================================================================================================\n";
     cout<<"\033[0;37m";
    op.close();
}
void email::ad()
{
    fstream rd;
    rd.open("data.csv");
    int flag=0;
    string id,line,no;
    cout<<"\nEnter mobile no :";
    cin>>no;

        while(rd)
    {
        getline(rd,line,',');

        getline(rd,line,',');
        if(no==line)
        {

             cout<<"\n Contact is already used \n";
            flag=1;

            break;
        }
        getline(rd,line,',');
        getline(rd,line,',');
        getline(rd,line,',');
        getline(rd,line,'\n');
    }

    if(flag==0)
    {
        cout<<"\nAdd new gmail id \n";
        add(no);
    }

    rd.close();
}
void email::add(string no)
{
    fstream w;

    string id,gender,country,line,date,name;
    long temp1,temp;
        cout<<"\nEnter full name  : ";
    cin.ignore();
    getline(cin,name);
    int flag;
    do

    {
        cout<<"\nEnter new mail id  : ";
        cin>>id;
        flag=0;
    w.open("data.csv");

    while(w)
    {
        getline(w,line,',');

        getline(w,line,',');

        getline(w,line,',');
        if(id==line)
        {
           cout<<"\n That username is taken. Try another. \n ";
           flag=1;
           w.close();
        }
        getline(w,line,',');
        getline(w,line,',');
        getline(w,line,'\n');



    }
    if(flag==1)
    {
        srand (time(NULL));
        temp1 = rand() %1000;
        temp=rand()%1000;
        cout<<"\nAvailable: ";
    cout<<endl<<name[0]<<name[1]<<name[2]<<temp1<<"@gmail.com"<<endl;
    cout<<endl<<temp<<name[0]<<name[1]<<name[2]<<"@gmail.com"<<endl;
    }
    }while(flag==1);
    w.close();

        cout<<"\n Enter your country : ";
    cin>>country;
    cout<<"\nEnter your gender (male/female): ";
    cin>>gender;
    cout<<"\nEnter date of birth (DD/MM/YYYY) : ";
    cin>>date;
    w.open("data.csv",ios::app);
    w<<name<<',';
     w<<no<<',';
     w<<id<<',';
     w<<country<<',';
     w<<gender<<',';
    w<<date<<endl;
w.close();



}

void email::srch()
{
    fstream op;
    op.open("data.csv");
    string line, sub;
    cout<<"\nEnter name to be search ";
    cin.ignore();
    getline(cin,sub);
    size_t temp;
    cout<<"\033[1;31m";
    cout<<"\n==================================================================================================\n";
        cout<<"\033[21;33m";
        getline(op,line,',');
        cout<<left<<setw(20)<<line;
        getline(op,line,',');
        cout<<left<<setw(20)<<line;
        getline(op,line,',');
        cout<<left<<setw(30)<<line;
        getline(op,line,',');
        cout<<left<<setw(10)<<line;
        getline(op,line,',');
        cout<<left<<setw(10)<<line;
        getline(op,line,'\n');
        cout<<left<<setw(10)<<line<<endl;
         cout<<"\033[1;31m";
cout<<"\n==================================================================================================\n";
cout<<"\033[0;37m";
        while(op)
    {
        cout<<endl;

        getline(op,line,',');
        temp=line.find(sub);
        if(temp!= string::npos )
        {
            cout<<left<<setw(20)<<line;
            getline(op,line,',');
            cout<<left<<setw(20)<<line;
            getline(op,line,',');
            cout<<left<<setw(30)<<line;
            getline(op,line,',');
            cout<<left<<setw(10)<<line;
            getline(op,line,',');
            cout<<left<<setw(10)<<line;
            getline(op,line,'\n');
            cout<<left<<setw(10)<<line<<endl;
        }
        else
        {
            getline(op,line,',');
            getline(op,line,',');
            getline(op,line,',');
            getline(op,line,',');
            getline(op,line,'\n');
        }
    }
    cout<<"\033[1;31m";
    cout<<"\n==================================================================================================\n";
    cout<<"\033[0;37m";
}
void email::del()
{
    string password;
    cout<<"\nEnter password to access this function ";
    cin>>password;
    if(password=="mitcoe" || password=="MITCOE")
    {
        ifstream fin;
    ofstream fout;
    string line1,line2,line,no,name;
    int flag=0,f=0;
        fin.open("data.csv");
        fout.open("temp.csv",ios::out|ios::binary);

         cout<<"\nEnter mobile number to confirm deletion process : ";
         cin>>no;
         while(fin)
    {

        flag=0;

        getline(fin,line1,',');


        if(!fin){
            break;
       }
        getline(fin,line2,',');
        if(no==line2)
        {
            flag++;
            f++;
        }

        if(flag==1)
        {
            getline(fin,line,',');
        getline(fin,line,',');
        getline(fin,line,',');
        getline(fin,line,'\n');

        }
        else
        {
            fout<<line1<<',';
            fout<<line2<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,'\n');
            fout<<line<<endl;
        }

    }
    if(f>=1)
    {
        cout<<"\nData deleted ";

    }
    else
    {
        cout<<"\nGiven data is not present";
    }
    fin.close();
    fout.close();
    remove("data.csv");
    rename("temp.csv","data.csv");
    }
    else
    {
        cout<<"\nWRONG PASSWORD ";
        cout<<"\nTry again later ";
    }


}
void email::modify()
{
    string password;
    cout<<"\nEnter password to excess this function ";
    cin>>password;
    if(password=="mitcoe" || password=="MITCOE")
    {
        ifstream fin;
    ofstream fout;
    string line1,line2,line,no,name,country,gender,date,id;
    int flag=0,f=0,n=0;
        fin.open("data.csv");
        fout.open("temp.csv",ios::out|ios::binary);

         cout<<"\nEnter mobile number to modify data process : ";
         cin>>no;
         while(fin)
    {

        flag=0;

        getline(fin,line1,',');


        if(!fin){
            break;
       }
        getline(fin,line2,',');
        if(no==line2)
        {
            flag++;
            f++;
        }

        if(flag==1)
        {
            getline(fin,line,',');
            id=line;
        getline(fin,line,',');
        getline(fin,line,',');
        getline(fin,line,'\n');
        n++;
        }
        if(n==1)
        {
            cout<<"\nEnter modified entry ";
            cout<<"\nEnter full name ";
            cin.ignore();
            getline(cin,name);
            fout<<name<<',';
            fout<<no<<',';
            fout<<id<<',';
            cout<<"\nEnter country ";
            cin>>country;
            fout<<country<<',';
            cout<<"\nEnter gender ";
            cin>>gender;
            fout<<gender<<',';
            cout<<"\nEnter date of birth ";
            cin>>date;
            fout<<date<<'\n';

        }
        else
        {
            fout<<line1<<',';
            fout<<line2<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,',');
            fout<<line<<',';
            getline(fin,line,'\n');
            fout<<line<<endl;
        }

    }
    if(f>=1)
    {
        cout<<"\nEntry modified";

    }
    else
    {
        cout<<"\nGiven number doesn't belong to data ";
    }
    fin.close();
    fout.close();
    remove("data.csv");
    rename("temp.csv","data.csv");
    }
    else
    {
        cout<<"\nWRONG PASSWORD ";
        cout<<"\nTry again later ";
    }
}
int main()
{

    email a;
    int n,cho;
    do
    {
     system("cls");
     cout<<endl;
    cout<<"\033[1;31m"<<"######## ##     ##    ###    #### ##          ##     ## ######## ########  #### ######## ####  ######     ###    ######## ####  #######  ##    ##"<<endl;
    cout<<"##       ###   ###   ## ##    ##  ##          ##     ## ##       ##     ##  ##  ##        ##  ##    ##   ## ##      ##     ##  ##     ## ###   ## "<<endl;
    cout<<"##       #### ####  ##   ##   ##  ##          ##     ## ##       ##     ##  ##  ##        ##  ##        ##   ##     ##     ##  ##     ## ####  ##"<<endl;
    cout<<"######   ## ### ## ##     ##  ##  ##          ##     ## ######   ########   ##  ######    ##  ##       ##     ##    ##     ##  ##     ## ## ## ## "<<endl;
    cout<<"##       ##     ## #########  ##  ##           ##   ##  ##       ##   ##    ##  ##        ##  ##       #########    ##     ##  ##     ## ##  ####"<<endl;
    cout<<"##       ##     ## ##     ##  ##  ##            ## ##   ##       ##    ##   ##  ##        ##  ##    ## ##     ##    ##     ##  ##     ## ##   ###"<<endl;
    cout<<"######## ##     ## ##     ## #### ########       ###    ######## ##     ## #### ##       ####  ######  ##     ##    ##    ####  #######  ##    ##"<<"\033[0;33m"<<endl;

    cout<<"\n1.Add id";
    cout<<"\n2.Display list";
    cout<<"\n3.Search id";
    cout<<"\n4.Modify";
    cout<<"\n5.Delete"<<endl;

    cin>>cho;
     cout<<"\033[0;37m";

        switch(cho)
        {
        case 1:
            a.ad();
            break;
        case 2:
            a.display();
            break;
        case 3:
            a.srch();
            break;
        case 5:
            a.del();
            break;
        case 4:
            a.modify();
            break;


        }
        cout<<"\npress 1 to continue ";
        cin>>n;

    }while(n==1);

    return 0;
}
