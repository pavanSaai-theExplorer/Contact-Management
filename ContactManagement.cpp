// Adding header files

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;

//Declaring variables

string fstname, lstname;
string phoneNum;

//Declaring Functions

void addContact();
void searchContact();
void help();
void exit();
bool checkDigits(string);
bool checkNum(string);

// Declaring Main Function

int main()
	{		
	    int choice;
	    system("cls");
	    system("color 0A");
	    cout << "\n\n\n\t\t\t Contact Management";
	    cout << "\n\n\t 1.Add Contact \n\t 2.Search Contact \n\t 3.Help \n\t 4.Exit \n\t> ";
	    cin >> choice;

   		switch(choice)
    	{
	        case 1:
	            addContact();
	            break;
	        case 2:
	            searchContact();
	            break;
	        case 3:
	            help();
	            break;
	        case 4:
	            exit();
	            break;
	        default:
	            cout << "\n\n\t\t Invalid Input (Oh! No...)";
	            cout << "\n\t Press Any Key To Continue...";
	            getch();
	            main();
    	}
    	return 0;
	}
	
void addContact()
	{
	    ofstream phone("Contacts.txt", ios::app);
	    system("cls");
	    cout << "\n\n\t\t Enter First Name : ";
	    cin >> fstname;
	    cout << "\n\n\t\t Enter Last Name : ";
	    cin >> lstname;
	    cout << "\n\n\t\t Enter 10-Digit Phone Number : ";
	    cin >> phoneNum;
	
	    if(checkDigits(phoneNum) == true)
	    {
	        if(checkNum(phoneNum) == true)
	        {
	            if(phone.is_open())
	            {
	                phone << fstname << " " << lstname << " --> " << phoneNum << endl;
	                cout << "\n\n\t\t Contact Saved Successfully !";
	            }
	            else
	            {
	                cout << "\n\n\t\t Error in Opening File !";
	            }
		  	}
		        else
		        {
		            cout << "\n\n\t\t Phone Number Must Contain Numbers Only..!";
		        }
		}
		    else
		    {
		        cout << "\n\n\t\t A Phone Number Must Contain 10 Digits only..! \n\t\t It should be only Numbers..";
		    }
		    phone.close();
	}

void searchContact()
	{
	    bool found = false;
	    ifstream contactfile("Contacts.txt");
	    string keyword;
	    cout << "\n\n\t\t Enter Name you want to Search : ";
	    cin >> keyword;
	    while(contactfile >> fstname >> lstname >> phoneNum)
	    {
	        if(keyword == fstname || keyword == lstname)
	        {
	            system("cls");
	            cout << "\n\n\n\t\t\t ***Contact details*** ";
	            cout << "\n\n\t\t First Name : " << fstname;
	            cout << "\n\n\t\t Last Name : " << lstname;
	            cout << "\n\n\t\t Phone Number : " << phoneNum;
	            found = true;
	            break;
	        }
	    }
	    if(found == false)
	    cout << "\n\n\t\t Sorry, No Such Contact Found..";
	}	

void help()
	{
	    cout << "\t\t Press 1 for New Contact \n"<<endl;
	    cout << "\t\t Press 2 for searching the Contact \n"<<endl;
	    cout << "\t\t Press 4 for Exit "<<endl;
	}
		
void exit()
	{
	    system("cls");
	    cout << "\n\n\n\t\t\t Thank You For Using our Service..! \n\t\t\t\t ***See you Soon***";
	    exit(1);
	}
	
bool checkDigits(string x)
	{
	    if(x.length() == 10)
	    return true;
	    else
	    return false;
	}

bool checkNum(string x)
	{
	    bool check = true;
	    for(int i=0; i < x.length(); i++)
	    {
	        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
	        {
	            check = false;
	            break;
	        }
	    }
	
	    if(check == true)
	    return true;
	    if(check == false)
	    return false;
	}
