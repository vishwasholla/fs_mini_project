#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<ctype.h>
#include<windows.h>
#include<ctime>
#include<limits>
#include<iomanip>
#include<ctype.h>
#include<sstream>


using namespace std;

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;

void addrecords();
void displayrecord();
void deleterecords();
void searchrecord();
void modifyrecord();
void payment();


//int getValidIntegerInput() {
//    int input;
//    string inputString;
//    while (true) {
//        getline(cin, inputString);
//
//        stringstream ss(inputString);
//        if (ss >> input && ss.eof()) {
//            break;
//        }
//
//        cin.clear();
//        cout <<endl<< "Please enter a valid integer: ";
//    }
//    return input;
//}
long long getValidIntegerInput() {
    long long input;
    std::string inputString;
    while (true) {
        getline(std::cin, inputString);

        std::stringstream ss(inputString);
        if (ss >> input && ss.eof()) {
            break;
        }

        std::cin.clear();
        std::cout << "Please enter a valid integer: ";
    }
    return input;
}

class subscriber
{
 public:
 long long phonenumber;
 string name;
 int amount;
 int planamt;
 string status;
}s;


struct IndexEntry
{
    long long phoneNumber;
    long offset;
}indexPointer;



void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void changeColour(int colour) {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

void landingpage()
{
    system("cls");

    gotoxy(30,6);
    for(int i=0; i<62; i++){cout << char(178);}
    gotoxy(36,8);
    cout<<"WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM"<<endl;
    gotoxy(30,10);
    for(int i=0; i<62; i++){cout << char(178);}
    gotoxy(46,14);
    changeColour(GREEN);
    cout<<"Press any key to continue...";
    _getch();
    system("cls");
}

void userdetails()
{
    int m=31,n=31;
    gotoxy(0,0);
    changeColour(WHITE);
    cout<<"DETAILS:";
    gotoxy(0,1);
    cout << char(218);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(0,2);
    cout << char(179) << "  Phone Number: "<<s.phonenumber;gotoxy(m,2);cout<< char(179) << endl;
    gotoxy(0,3);
    cout << char(179) << "  Name: "<<s.name;
    gotoxy(m,3);
    cout<<char(179);
    gotoxy(0,4);
    cout <<char(179) << "  Plan: "<<s.planamt;
    gotoxy(n,4);
    cout<< char(179);
    gotoxy(0,5);
    cout <<char(179) << "  Amount: "<<s.amount;
    gotoxy(n,5);
    cout<< char(179);
    gotoxy(0,6);
    cout <<char(179) << "  Payment Status: "<<s.status;
    gotoxy(n,6);
    cout<< char(179);
    gotoxy(0,7);
    cout << char(192);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(217) << endl;
}

void plans()
{
     char plan1,plan2;
     cout<<"\n";
     cout << char(218);for(int i=0; i<20; i++){cout << char(196);} cout<< char(194);for(int i=0; i<24; i++){cout << char(196);} cout<< char(194);for(int i=0; i<20; i++){cout << char(196);} cout<<char(191)<< endl;
     cout << char(179)<<"  1. Annual Plan "<<"   "<<char(179)<< "   2. Half-yearly Plan  "<<char(179)<<"  3. Monthly Plan"<<"   "<<char(179)<< endl;
     cout << char(192); for(int i=0; i<20; i++){cout << char(196);} cout<< char(193);for(int i=0; i<24; i++){cout << char(196);} cout<< char(193);for(int i=0; i<20; i++){cout<< char(196);} cout<<char(217);
     cout<<"\nSelect subscription term -> ";
     s: cin>>plan1;
     switch(plan1){
         case '1':cout<<char(218);for(int i=0; i<14; i++){cout<<char(196);}cout<< char(191)<<endl;
                cout<< char(179)<<"  1.Rs.2,498 "<<" "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  2.Rs.2,399 "<<" "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  3.Rs.1,999 "<<" "<<char(179)<<endl;
                cout<< char(192); for(int i=0; i<14; i++){cout<< char(196);}cout<< char(217);
                cout<<"\nSelect your plan -> ";
                s1: cin>>plan2;
                 switch(plan2){
                    case '1':s.amount=2498*1.18;
                            s.planamt=2498;
                            break;
                    case '2':s.amount=2399*1.18;
                            s.planamt=2399;
                            break;
                    case '3':s.amount=1999*1.18;
                            s.planamt=1999;
                            break;
                    default:cout<<"Enter valid Plan\n";
                            goto s1;
                    }
                    break;

         case '2':cout<<char(218);for(int i=0; i<14; i++){cout<<char(196);}cout<< char(191)<<endl;
                cout<< char(179)<<"  1.Rs.1,295 "<<" "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  2.Rs.999 "<<"   "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  3.Rs.850 "<<"   "<<char(179)<<endl;
                cout<< char(192); for(int i=0; i<14; i++){cout<< char(196);}cout<< char(217);

                cout<<"\nSelect your plan -> ";
                s2: cin>>plan2;
                 switch(plan2){
                    case '1':s.amount=1295*1.18;
                            s.planamt=1295;
                            break;
                    case '2':s.amount=999*1.18;
                            s.planamt=999;
                            break;
                    case '3':s.amount=850*1.18;
                            s.planamt=850;
                            break;
                    default:cout<<"Enter valid Plan\n";
                            goto s2;
                    }
                    break;

         case '3':cout<<char(218);for(int i=0; i<14; i++){cout<<char(196);}cout<< char(191)<<endl;
                cout<< char(179)<<"  1.Rs.315 "<<"   "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  2.Rs.250 "<<"   "<<char(179)<<endl;
                cout<<char(179);for(int i=0; i<14; i++){cout<<char(196);}cout<<char(179)<<endl;
                cout<< char(179)<<"  3.Rs.219 "<<"   "<<char(179)<<endl;
                cout<< char(192); for(int i=0; i<14; i++){cout<< char(196);}cout<< char(217);

                cout<<"\nSelect your plan -> ";
                s3: cin>>plan2;
                 switch(plan2){
                    case '1':s.amount=315*1.18;
                            s.planamt=315;
                            break;
                    case '2':s.amount=259*1.18;
                            s.planamt=259;
                            break;
                    case '3':s.amount=219*1.18;
                            s.planamt=219;
                            break;
                    default:cout<<"Enter valid Plan\n";
                            goto s3;
                    }
                    break;
         default:cout<<"Enter valid Subscription plan\n";
                 goto s;
     }
}

void billmod()
{
    system("cls");
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    int tax;
    if(s.amount > s.planamt)
        tax = s.amount - s.planamt;
    else
        tax = 0;

    int m=61,n=61;
    gotoxy(0,0);
    changeColour(WHITE);
    cout<<"PAYMENT DETAILS:";
    gotoxy(0,1);
    cout << char(219);      for(int i=0; i<60; i++){cout << char(196);}      cout << char(219) << endl;gotoxy(0,2);
    cout<<char(179)<<"  ";for(int i=0; i<25; i++){cout << char(176);}cout<<" BILL ";for(int i=0; i<25; i++){cout << char(176);} gotoxy(m,2);cout<<char(179)<<endl;gotoxy(0,3);
    cout<<char(179);gotoxy(m,3);cout<<char(179);gotoxy(0,4);
    cout << char(179) << "  Bill To: "<<"\t\t\t\t Date: "<<local_time->tm_mday<<"-"<< 1 + local_time->tm_mon<<"-"<<1900 + local_time->tm_year;;gotoxy(m,4);cout<< char(179) << endl;
    gotoxy(0,5);
    cout<<char(179);gotoxy(m,5);cout<<char(179);
    gotoxy(0,6);
    cout << char(179) << "  NAME: "<<s.name;
    gotoxy(m,6);
    cout<<char(179);
    gotoxy(0,7);
    cout <<char(179) << "  PHONE NUMBER: "<<s.phonenumber;
    gotoxy(n,7);
    cout<< char(179);
    gotoxy(0,8);
    cout<<char(179);gotoxy(m,8);cout<<char(179);
    gotoxy(0,9);
    cout<<char(179);for(int i=0; i<60; i++){cout <<char(196);}gotoxy(m,9);cout<<char(179);
    gotoxy(0,10);
    cout<<char(179);gotoxy(m,10);cout<<char(179);
    gotoxy(0,11);
    cout <<char(179) << "  SUBSCRIPTION PLAN: Rs."<<s.planamt;
    gotoxy(n,11);
    cout<< char(179);
    gotoxy(0,12);
    cout<<char(179);gotoxy(m,12);cout<<char(179);
    gotoxy(0,13);
    cout <<char(179) << "  TAX: Rs."<<tax;
    gotoxy(n,13);
    cout<< char(179);
    gotoxy(0,14);
    cout<<char(179);gotoxy(m,14);cout<<char(179);
    gotoxy(0,15);
    cout <<char(179) << "  BALANCE AMOUNT: Rs."<<s.amount;
    gotoxy(n,15);
    cout<< char(179);
    gotoxy(0,16);
    cout<<char(179);gotoxy(m,16);cout<<char(179);
    gotoxy(0,17);
    cout <<char(179) << "  PAYMENT STATUS: "<<s.status;
    gotoxy(n,17);
    cout<< char(179);
    gotoxy(0,18);
    cout<<char(179);gotoxy(m,18);cout<<char(179);
    gotoxy(0,19);
    cout << char(219);      for(int i=0; i<60; i++){cout << char(196);}      cout << char(219) << endl;

}


void addrecords()
{
    fstream file, indexFile;
    char test;
    long long primaryKey;
    indexFile.open("index.txt", ios::out | ios::app);
    file.open("subscribe.txt", ios::app | ios::binary);
    if (!file || !indexFile)
    {
        cout << "Error opening file! \n";
        exit(1);
    }
    while (1)
    {
        changeColour(WHITE);
        cout << "Enter the Phone Number: ";
        s.phonenumber = getValidIntegerInput();
        primaryKey = s.phonenumber;
        cout << "Enter the Name: ";
        getline(cin >> ws, s.name);
        cout << "Select the Subscription Term: ";
        plans();
        s.status = "PENDING";
        file.seekp(0,ios::end);
        streampos pos = file.tellp();
        file.write(reinterpret_cast<const char*>(&s), sizeof(s));
        getch();
        indexFile << primaryKey << ' ' << pos << endl;

        cout << "\n";
        for (int i = 0; i < 10; i++)
        {
            cout << char(176);
        }
        cout << " RECORD ENTERED SUCCESSFULLY ";
        for (int i = 0; i < 10; i++)
        {
            cout << char(176);
        }
        changeColour(GREEN);
        cout << "\n\n Press Y/y key to add another record or any other key to GO BACK.";
        test = getche();
        system("cls");
        if (!(test == 89 || test == 121))
            break;
    }
    file.close();
    indexFile.close();
}


void displayrecord()
{
     fstream file;
     int counter=1;
     int a=5,b=3,num=0;
     file.open("subscribe.txt",ios::in);
     if(!file)
        {
         cout<<"\n";for(int i=0; i<10; i++){cout << char(176);}cout<<" NO RECORD FOUND ";for(int i=0; i<10; i++){cout << char(176);}
         cout<<"\n\n";
        }
     cout << char(201);for(int i=0; i<10; i++){cout << char(205);} cout<< char(203);     for(int i=0; i<18; i++){cout << char(205);}      cout<< char(203);for(int i=0; i<24; i++){cout << char(205);} cout<< char(203);for(int i=0; i<12; i++){cout << char(205);} cout<< char(203);for(int i=0; i<16; i++){cout << char(205);} cout<< char(203);for(int i=0; i<22; i++){cout << char(205);} cout<<char(187)<< endl;
     cout << char(186)<<"  Sl.no "<<"  "<<char(186)<< "     Phone No.    "<< char(186)<<"          Name"<<"          "<< char(186)<< "    Plan"<<"    "<<char(186)<< "     Amount"<<"     "<< char(186)<< "     Payment Status"<<"   "<< char(186)<< endl;
     cout << char(200); for(int i=0; i<10; i++){cout << char(205);} cout<< char(202);     for(int i=0; i<18; i++){cout << char(205);}      cout<< char(202);for(int i=0; i<24; i++){cout<< char(205);} cout<< char(202);for(int i=0; i<12; i++){cout << char(205);} cout<< char(202);for(int i=0; i<16; i++){cout << char(205);} cout<< char(202);for(int i=0; i<22; i++){cout << char(205);}cout<< char(188);
     cout<<"\n";
     while((file.read((char*)&s,sizeof(s))))
        {
            gotoxy(a,b);
            cout<<counter<<".";

            gotoxy(a+11,b);
            cout<<s.phonenumber;
            gotoxy(a+28,b);
            cout<<s.name;
            gotoxy(a+54,b);
            cout<<"Rs."<<s.planamt;
            gotoxy(a+68,b);
            cout<<"Rs."<<s.amount;
            gotoxy(a+89,b);
            cout<<s.status;
            a=5;
            b=b+2;
            counter++;
            num=b;
        }
    if(counter>1)
    {
    for(int i=0;i<num-2;i++){gotoxy(0,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(11,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(30,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(55,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(68,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(85,i+3);cout<<char(186);}
    for(int i=0;i<num-2;i++){gotoxy(108,i+3);cout<<char(186);}

    gotoxy(0,num);
    cout << char(200); for(int i=0; i<10; i++){cout << char(205);} cout<< char(202);     for(int i=0; i<18; i++){cout << char(205);}      cout<< char(202);for(int i=0; i<24; i++){cout<< char(205);} cout<< char(202);for(int i=0; i<12; i++){cout << char(205);} cout<< char(202);for(int i=0; i<16; i++){cout << char(205);} cout<< char(202);for(int i=0; i<22; i++){cout << char(205);} cout<< char(188);
    }

    file.close();
    changeColour(GREEN);
    cout<<"\n"<<char(174)<<" Press any key to go back";
    _getch();
    system("cls");
}


void deleterecords()
{
    fstream file, dumpFile, dumpIndex, indexFile;
    int i = 0,count_file=1;
    long long phone;
    bool flag=false;

    file.open("subscribe.txt", std::ios::binary | std::ios::in | std::ios::out|ios::app);
    indexFile.open("index.txt", std::ios::in | std::ios::out|ios::app);

    if (!file || !indexFile) {
        cout << "Can't open file\n";
        exit(0);
    }

    dumpFile.open("dumpFile.txt", ios::binary | ios::out|ios::app);
    dumpIndex.open("dumpIndex.txt", std::ios::out|ios::app);

    if (!dumpFile || !dumpIndex) {
        cout << "Can't open file\n";
        exit(0);
    }
    int newIndex;
    cout << "Enter the phone number to be deleted: ";
    phone=getValidIntegerInput();
    if (file.is_open() && indexFile.is_open()) {
         long long primaryKey,offset;
         while (indexFile >> primaryKey >> offset) {
            if (primaryKey != phone)
            {
                file.seekg(offset);
                file.read((char*)&s, sizeof(s));
                dumpFile.seekp(0,ios::end);
                dumpFile.write((char*)&s, sizeof(s));
                dumpIndex << primaryKey << ' ' << dumpFile.tellp()-sizeof(s) << endl;
            }
            else {
                flag = true;
            }
        }

    }
    if (flag) {
        file.close();
        indexFile.close();
        dumpIndex.close();
        dumpFile.close();
        remove("subscribe.txt");
        rename("dumpFile.txt", "subscribe.txt");
        remove("index.txt");
        rename("dumpIndex.txt", "index.txt");

        cout << "\n";
        for (int i = 0; i < 10; i++) {
            cout << char(176);
        }
        cout << " RECORD FOUND ";
        for (int i = 0; i < 10; i++) {
            cout << char(176);
        }
        cout << "\n\nRECORD DELETED SUCCESSFULLY\n\n";
        cout << "Press any key to continue...";
        getchar();
        system("cls");
    }
    else {
        file.close();
        indexFile.close();
        dumpIndex.close();
        dumpFile.close();
        cout << "The Entered Phone Number is NOT FOUND\n";
        remove("dumpFile.txt");
        remove("dumpIndex.txt");
        cout << "Press any key to continue...";
        getchar();
        system("cls");
    }
}


void searchrecord()
{
    fstream file,indexFile;
    bool flag;
    int i = 0,count_file=1;
    long long phone;
    int animate=0;
    file.open("subscribe.txt",ios::out|ios::in);
    indexFile.open("index.txt", std::ios::in | std::ios::out);
    if(!file || !indexFile)
        {
         cout<<"Add Record before searching\n";
         exit(0);
        }
    cout<<"Enter the phone number to be searched: ";
    phone=getValidIntegerInput();

    while(animate<2)
    {
        system("cls");
        cout<<"\n"<<char(179);
        Sleep(500);
        system("cls");
        cout<<char(196)<<char(196);
        Sleep(500);
        system("cls");
        cout<<"\n"<<"  "<<char(179);
        Sleep(500);
        system("cls");
        cout<<"\n\n"<<char(196)<<char(196);
        Sleep(500);
        system("cls");
        animate=animate+1;
    }
    if (file.is_open() && indexFile.is_open()) {
        long long primaryKey;
        int offset;
         while (indexFile >> primaryKey >> offset) {
                if(primaryKey==phone){
                    flag = true;
                }
         }
    }

    if(flag)
    {
        cout<<"\n";for(int i=0; i<10; i++){cout << char(176);}cout<<" RECORD FOUND ";for(int i=0; i<10; i++){cout << char(176);}
    }
    else
        cout<<"Record NOT FOUND.\n";
    changeColour(GREEN);
    cout<<"\n\nPress any key to continue...";
    _getch();
    system("cls");
}


void modifyrecord()
{
    fstream file, dumpFile, indexFile;
    int i = 0,count_file=1;
    long long primaryKey,phone;
    int index,offset;
    bool flag = false;
    char edit;
    file.open("subscribe.txt",ios::out|ios::in|ios::app);
    indexFile.open("index.txt",ios::out|ios::in|ios::app);
    if(!file || !indexFile)
        {
         cout<<"can not able to open file\n";
         exit(0);
        }
    dumpFile.open("dumpFile.txt",ios::app);
    if(!dumpFile)
        {
             cout<<"can not able to open file\n";
             exit(0);
        }
    cout<<"Enter the phone number to edit details: ";
    cin>>phone;
    system("cls");
     while (indexFile >> primaryKey >> offset) {
        if (primaryKey != phone) {
            file.seekg(offset);
            file.read((char*)&s, sizeof(s));
            dumpFile.seekp(0,ios::end);
            dumpFile.write((char*)&s, sizeof(s));
        }
        else {
            file.seekp(offset);
            file.read((char*)&s,sizeof(s));
             userdetails();
             cout<<"EDIT DETAILS: \n";
             cout<<"1. Change Name\n 2. Change Plan\n 3. Change both Name and Plan\n 4. Exit\n";
             cout<<"Enter your choice: ";
             a:cin>>edit;
             switch(edit)
             {
                 case '1':cout<<"\nEnter new name: ";
                        getline(cin >> ws, s.name);
                        dumpFile.write(reinterpret_cast<char*>(&s), sizeof(s));
                        break;
                 case '2':cout<<"\nSelect New Plan: ";
                        plans();
                        dumpFile.write(reinterpret_cast<char*>(&s), sizeof(s));
                        break;
                 case '3':cout<<"\nEnter new name: ";
                        getline(cin >> ws, s.name);
                        cout<<"\nSelect New Plan: ";
                        plans();
                        dumpFile.write(reinterpret_cast<char*>(&s), sizeof(s));
                        break;
                 case '4':file.close();
                        system("cls");
                        return;
                 default:cout<<"Enter valid option\n";
                          goto a;
             }
            flag = true;
        }
     }


    if(flag)
          {
             file.close();
             indexFile.close();
             dumpFile.close();
             remove("subscribe.txt");
             rename("dumpFile.txt","subscribe.txt");
             remove("dumpFile.txt");
             cout<<"\nThe entered phone number is FOUND and record MODIFIED SUCCESSFULLY\n";
             changeColour(GREEN);
             cout<<"Press any key to continue...";
             _getch();
             system("cls");
        }
    else
        {
             cout<<"The Entered Phone Number is NOT FOUND\n";
             remove("dumpFile.txt");
             changeColour(GREEN);
             cout<<"Press any key to continue...";
            _getch();
            system("cls");
        }
}


void payment()
{
    fstream file,indexFile;
	int i = 0,count_file=1;
    bool flag=false;
    long long phone,primaryKey;
    int index,offset,amt;
	file.open("subscribe.txt",ios::out|ios::in);
	indexFile.open("index.txt",ios::out|ios::in);
	if(!file)
    {
        cout<<"Unable to open the file\n";
        exit(0);
	}
	cout<<"Enter phone number of the subscriber for payment : ";
	cin>>phone;
    while (indexFile >> primaryKey >> offset)
    {
        if (primaryKey == phone)
        {
            file.seekg(offset);
            file.read((char*)&s, sizeof(s));
            if(s.amount > 0)
            {
                flag = true;
                billmod();
                cout<<"\nEnter amount of payment : ";
                cin>>amt;
                s.amount=s.amount-amt;
                if(s.amount == 0)
                {
                    s.status = "PAID";
                }
                file.seekg(-sizeof(s),ios_base::cur);
                file.write((char*)&s,sizeof(s));
                file.close();
                break;
            }
            break;
        }
	 }
	indexFile.close();
    if(flag)
    {
        cout<<"\n";for(int i=0; i<10; i++){cout << char(176);}cout<<" PAYMENT SUCCESSFUL ";for(int i=0; i<10; i++){cout << char(176);}
        cout<<"\n\n";
    }
    else if(i==2)
    {
        billmod();
        cout<<"\n\n";for(int i=0; i<10; i++){cout << char(176);}cout<<" PAYMENT ALREADY DONE! ";for(int i=0; i<10; i++){cout << char(176);}
        cout<<"\n\n";
    }
    else
    {
       cout<<"PHONE NUMBER NOT FOUND\n";
       cout<<"Please make sure you have a subscription plan.\n";
    }
    changeColour(GREEN);
    cout<<"Press any key to continue...";
    _getch();
    system("cls");

}




int main()
{
    char choice;
    lp:landingpage();
    system("cls");

    fstream indexFile;
    string seperator;
     while(1)
        {
             //add record
             gotoxy(50,0);
             changeColour(WHITE);
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,1);
             cout << char(179) << "  1. Add record      "<< char(179) << endl;gotoxy(50,2);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,3);
             //display record
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,4);
             cout << char(179) << "  2. Display record  "<< char(179) << endl;gotoxy(50,5);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,6);
            //delete
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,7);
             cout << char(179) << "  3. Delete record   "<< char(179) << endl;gotoxy(50,8);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,9);
            //search
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,10);
             cout << char(179) << "  4. Search record   "<< char(179) << endl;gotoxy(50,11);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,12);
            //modify
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,13);
             cout << char(179) << "  5. Modify record   "<< char(179) << endl;gotoxy(50,14);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,15);
            //payment
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,16);
             cout << char(179) << "  6. Make Payment    "<< char(179) << endl;gotoxy(50,17);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;gotoxy(50,18);
            //exit
             cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;gotoxy(50,19);
             cout << char(179) << "  7. Exit            "<< char(179) << endl;gotoxy(50,20);
             cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

             gotoxy(50,22);
             cout<<"ENTER YOUR CHOICE "<<char(45)<<char(62)<<" ";gotoxy(72,22);
             cin>>choice;
             system("cls");

             switch(choice)
             {
                 case '1':addrecords();
                        break;
                 case '2':displayrecord();
                        break;
                 case '3':deleterecords();
                        break;
                 case '4':searchrecord();
                        break;
                 case '5':modifyrecord();
                        break;
                 case '6':payment();
                        break;
                 case '7':gotoxy(46,14);
                        changeColour(BLUE);
                        cout<<"THANK YOU FOR USING OUR SERVICE";
                        Sleep(2000);
                        changeColour(WHITE);
                        exit(0);
                 default:gotoxy(36,14);
                         changeColour(RED);
                         for(int i=0; i<21; i++){cout << char(176);} cout<<"   ERROR !  ";for(int i=0; i<21; i++){cout << char(176);}
                         Sleep(1000);
                         system("cls");
                         gotoxy(38,14);
                         changeColour(GREEN);
                         cout<<"You entered a invalid choice.Press ENTER to continue";
                         _getch();
                         system("cls");
             }
         }
}
