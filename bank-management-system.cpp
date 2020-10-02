
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;


class account
{
    int acno;
    char name[50];
    int deposit;
    char type;
public:
    void create_account();
    void show_account() const;	
    void modify();	
    void dep(int);	
    void draw(int);	
    void report() const;	
    int retacno() const;	
    int retdeposit() const;
    char rettype() const;	
    bool checkname(char *ab);    
    char checktype(char TYPE);   
    int checkdeposit(int DEPOSIT, char t);
    int acccno();
};     

char account::checktype(char TYPE)
{
    if(TYPE=='C' || TYPE=='S')
    {
        return TYPE;
    }
    else
    {
        cout<<"\nInvalid Input. Enter either C/S : ";
        cin>>TYPE;
        TYPE=toupper(TYPE);
        checktype(TYPE);
    }
}

int account::checkdeposit(int DEPOSIT, char t)
{
    if(t=='C')
    {
        if(DEPOSIT>=1000)
            return DEPOSIT;
        else
        {
            cout<<"\nInvalid Input. Enter a value more than 1000 : ";
            cin>>DEPOSIT;
            checkdeposit(DEPOSIT,'C');
        }
    }
    else if(t=='S')
    {
        if(DEPOSIT>=500)
            return DEPOSIT;
        else
        {
            cout<<"\nInvalid Input. Enter a value more than 500 : ";
            cin>>DEPOSIT;
            checkdeposit(DEPOSIT,'S');
        }
    }
}

bool account::checkname(char *ab)
{
    int i,length,flag=0;
    length = (strlen(ab));
    if(ab[0]==' ')
        return 0;
    for (i=0; i<length; i++)
    {
        if((ab[i] >=65 && ab[i] <= 90) ||(ab[i] >=97 && ab[i] <= 122) || ab[i]==' ')
            flag=1;
        else
        {
            flag=0;
            return 0;
        }
    }
    if(flag==1)
        return 1;

    return 0;
}


void account::create_account()
{

    acno=acccno();
    ++acno;
    cout<<"\n\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name,50);
    if(checkname(name))
    {
        cout<<"\nEnter Type of The account (Current(C)/Savings(S)) : ";
        cin>>type;
        type=toupper(type);
        type=checktype(type);
        cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin>>deposit;
        deposit=checkdeposit(deposit,type);
        cout<<"\n\n\nAccount Created..\n";
        cout<<"Your Account number is : "<<acno<<endl;
    }
    else
    {
        cout<<"\nInvalid Input. Input ALPHABETIC name\n";
        create_account();
    }
}

void account::show_account() const
{
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nAccount Holder Name : ";
    cout<<name;
    if(type=='S')
        cout<<"\nType of Account : "<<"Savings" ;
    else if(type=='C')
        cout<<"\nType of Account : "<<"Current" ;
    cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,50);
    if(checkname(name))
    {
        cout<<"\nModify Type of Account (Current(C)/Savings(S)) : ";
        cin>>type;
        type=toupper(type);
        type=checktype(type);
        cout<<"\nModify Balance amount (>=500 for Saving and >=1000 for current ) : ";
        cin>>deposit;
        checkdeposit(deposit,type);
    }
    else
    {
        cout<<"\nInvalid Input. Input ALPHABETIC name\n";
        modify();
    }
}


void account::dep(int x)
{
    deposit+=x;
}

void account::draw(int x)
{
    deposit-=x;
}

void account::report() const
{
    cout<<acno<<setw(10)<<" "<<name<<setw(12)<<" "<<type<<setw(22)<<deposit<<endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}
int account::acccno()
{
    account ac;
    ifstream file("account.dat", ios::in);
    while(!file.eof())
    {
        file.read((char *) (&ac), sizeof(account));
    }
    int c = ac.retacno();

    file.close();
    return c;

}


void write_account();	
void display_sp(int);	
void modify_account(int);	
void delete_account(int);	
void display_all();		
void deposit_withdraw(int, int); 
void intro();	
int enternmber(); 


int main()
{
    char ch;
    int num;
    system("Color 70");
    intro();
    do
    {
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. NEW ACCOUNT";
        cout<<"\n\n\t02. DEPOSIT AMOUNT";
        cout<<"\n\n\t03. WITHDRAW AMOUNT";
        cout<<"\n\n\t04. BALANCE ENQUIRY";
        cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout<<"\n\n\t06. CLOSE AN ACCOUNT";
        cout<<"\n\n\t07. MODIFY AN ACCOUNT";
        cout<<"\n\n\t08. EXIT";
        cout<<"\n\n\tSelect Your Option (1-8) ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout<<"\n\n\tEnter The account No. : ";
            num=enternmber();
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout<<"\n\n\tEnter The account No. : ";
            num=enternmber();
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout<<"\n\n\tEnter The account No. : ";
            num=enternmber();
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout<<"\n\n\tEnter The account No. : ";
            num=enternmber();
            delete_account(num);
            break;
        case '7':
            cout<<"\n\n\tEnter The account No. : ";
            num=enternmber();
            modify_account(num);
            break;
        case '8':
            cout<<"\n\n\tThanks for using bank managemnt system";
            break;

        default :
            cout<<"Invalid Choice\a";
        }
        cin.ignore();
        cin.get();
    }
    while(ch!='8');
    return 0;
}


void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.create_account();
    outFile.write((char *) (&ac), sizeof(account));
    outFile.close();
}


void display_sp(int n)
{
    account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) (&ac), sizeof(account)))
    {
        if(ac.retacno()==n)
        {
            ac.show_account();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nAccount number does not exist";
}



void modify_account(int n)
{
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read((char *) (&ac), sizeof(account));
        if(ac.retacno()==n)
        {
            ac.show_account();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write((char *) (&ac), sizeof(account));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}


void delete_account(int n)
{
    account ac;
    int flag =0;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }

    inFile.seekg(0,ios::beg);
    while(!inFile.eof())
    {
        inFile.read((char *) (&ac), sizeof(account));
        if(ac.retacno()!=n)
            flag=1;
        else
            flag=0;

    }
    if(flag ==1)
        cout<<"Record not found\n";
    else
    {
        inFile.close();
        inFile.open("account.dat",ios::binary);
        outFile.open("Temp.dat",ios::binary);
        while(inFile.read((char *) (&ac), sizeof(account)))
        {
            if(ac.retacno()!=n)
            {
                outFile.write((char *) (&ac), sizeof(account));
            }

        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat","account.dat");
        cout<<"\n\n\tRecord deleted ...";
    }




}

void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"========================================================================\n";
    cout<<"A/c no.         NAME                 Type              Balance\n";
    cout<<"========================================================================\n";
    while(inFile.read((char *) (&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

**************************************************************
int enternmber()
{
    int a;

    cin>>a;
    while(1)
    {

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid input"<<endl<<"\nENTER AGAIN : ";
            cin>>a;
        }
        if(!cin.fail())
            break;
    }
    return a;
}


void deposit_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read((char *) (&ac), sizeof(account));
        if(ac.retacno()==n)
        {
            ac.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited : ";
                amt=enternmber();
                ac.dep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw : ";
                amt=enternmber();
                int bal=ac.retdeposit()-amt;
                if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
                    cout<<"Insufficient balance";
                else
                    ac.draw(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write((char *) (&ac), sizeof(account));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}

void intro()
{
    cout<<"\n\n\n\t  BANK";
    cout<<"\n\n\tMANAGEMENT";
    cout<<"\n\n\t  SYSTEM";

    cin.get();
}
