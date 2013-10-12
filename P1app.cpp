// file: P1app.cpp
// Authors: Amandeep Gill, Marshall Jankovsky, 
// Contents: This file contains the driver application for the library class

#include <iostream>
#include <vector> 
#include <fstream>
#include <memory>
#include "Library.h"
#include "Date.h"

using namespace std;

// Function Prototypes

// function to display menu options and grab user menu selection
char mainMenu ();
// function to load the library from the backup file specified by the user
void loadLib (vector<shared_ptr<Library> > &L);
// function to write the library to a backup file specified by the user
void saveLib (vector<shared_ptr<Library> > &L);
// function to allow the user to add a member to the library manually
void addMember (vector<shared_ptr<Library> > &L);
// function to allow the user to manually remove a member fro the library
void removeMember (vector<shared_ptr<Library> > &L);
// function to allow the user to manually add an asset, (book or periodical)
void addAsset (vector<shared_ptr<Library> > &L);
// function to allow the user to manually remove an asset from the library
void removeAsset (vector<shared_ptr<Library> > &L);
// function to check out an asset to a member
void memCheckout (vector<shared_ptr<Library> > &L);
// function currently does not do anything
void memReturn (vector<shared_ptr<Library> > &L);
// function to create a report from the given library
void makeReport(vector<shared_ptr<Library> > &L const);

int main()
{
    // initialize our library
    vector<shared_ptr<Library> > L;
    char choice;
    do {
        choice = mainMenu();
        switch(choice) {
            case '1':
                loadLib(L);
                break;
            case '2': 
                saveLib(L);
                break;
            case '3': 
                addMember(L);	
                break;
            case '4':
                removeMember(L);
                break;
            case '5':
                addAsset(L);
                break;
            case '6':
                removeAsset(L);
                break;
            case '7':
                memCheckout(L);
                break;
            case '8':
                memReturn(L);
                break;
            case '9':
                makeReport(L);
                break;
            case 'q':
                break;
            default:
                cout << "Invalid choice\n";
        }
        cout << endl;
    } while (choice != 'q')
    return 0;			
}

char mainMenu()
{
	char choice;
	cout << "'A'  : Restore Library Information from a File\n";
	cout << "'B'  : Save Library Information to a File\n";
	cout << "'C'  : Add Library Card Holder\n";
	cout << "'D'  : Remove Library Card Holder\n";
	cout << "'E'  : Add New Library Asset\n";
	cout << "'F'  : Remove Library Asset\n";
	cout << "'G'  : Card Holder Checkout Asset\n";
	cout << "'H'  : Card Holder Return Asset\n";
	cout << "'I'  : Generate Reports\n";
	cout << "'Q'  : Quit\n";
	cin >> choice; 
	return tolower(char);
}

void loadLib(vector<shared_ptr<Library> > &L)
{
	string fname;
	cout << "Enter the filename of the library to load:\n";
	cin >> fname; 
	ifstream libFile(fname);
	if(libFile.fail())
	{
		cout << fname << " not found.\n";
		return;
	}
	
	while (libFile.good())
	{
	    string Type;
	    libFile >> Type;
	    if (Type == "Type:") {
	        libFile >> Type;
	        if (Type == "MEMBER") {

	        } else if (Type == "BOOK") {

	        } else if (Type == "PERIODICAL") {

	        } else {
	            // Not a valid type
	        }
	    }
	}
}

void saveLib(vector<shared_ptr<Library> > &L)
{return;}

void addMember(vector<shared_ptr<Library> > &L)
{
	string name; string id; string address; string city; string state; 
	string zip; string phone;
	cout << "Create new member:\nMember Name: ";
	cin >> name;
	cout << "\nMember ID: ";
	cin >> id;
	cout << "\nMember Address: "
	cin >> address;
	cout << "\nMember City: "
    cin >> city;
	cout << "\nMember State: "
	cin >> state;
	cout << "\nMember Zip: "
	cin >> zip;
	cout << "\nMember Phone #: "
	cin >> phone;
	cout << endl;
	Member newMem = new Member(name, id, address, city, state, zip, phone);
	L.members.push_back(newMem);
	return;
}

void removeMember(vector<shared_ptr<Library> > &L)
{
	string targId;
	cout << "Delete current memeber:\nID of member you wish to erase: ";
	cin >> targId;
	for (int i=0;i<L.members.size();i++)
		if (L.members[i].getID() == targId)
			L.members[i].erase(L.members.begin()+i)
	return;
}

}
void addAsset(vector<shared_ptr<Library> > &L)
{
	char choice;
	bool isval = false; 
	while(isval == false)
	{
	    cout << "Add new Asset:\nEnter a type -\na) Book\nb) Periodical\n";
	    cin >> choice; 
	    tolower(choice);
	    if (choice != 'a' && choice != 'b')
	    	cout << "Invalid choice\n";
	}
	// Book 
	if (choice == 'a')
	{
		string name; string id; string asType; string author; string isbn; 
		string bookType; 
		cout << "Create new Book:\nBook Title: ";
		cin >> name;
		cout << "\nBook ID: ";
		cin >> id;
		cout << "\nAsset Type: ";
		cin >> asType;
		cout << "\nAuthor: ";
		cin >> author;
		cout << "\nISBN: ";
		cin >> isbn;
		cout << "\nBook Type: ";
		cin >> bookType;
		cout << endl;
		Book newBook = new Book(name, id, asType, author, isbn, bookType);
		L.assets.push_back(newBook);
		return;
	}	
	// Periodical 
	else
	{
		string name; string id; string asType; string issn; int numIssues; int volume; 
		int volNum; Date pubDate;  
		cout << "Create new Periodical:\nPeriodical Title: ";
		cin >> name;
		cout << "\nPeriodical ID: ";
		cin >> id;
		cout << "\nAsset Type: ";
		cin >> asType;
		cout << "\nISSN: ";
		cin >> author;
		cout << "\nNumber of issues to store: ";
		cin >> numIssues;
		for (int i=0;i<numIssues;i++)
		{
			cout << "\nVolume: ";
			cin >> volume;
			cout << "\nNumber: "
			cin >> volNum;
			cout << "\nPublication Date (MM/DD/YYYY): "
			cin >> pubDate;
			Periodical newPeri = new Periodical(name, id, asType, issn, numIssues,
												volume, volNum, pubDate);
			L.assets.push_back(newPeri);
		}
		cout << endl;
		return;
	}
}

void memCheckout()
{return;}

void memReturn()
{return;}

void makeReport(vector<shared_ptr<Library> > &L const)
{
    char choice = NULL; 
    while (choice != 'q') {
        cout << "Report Menu:\na) List overdue Assets\n";
        cout << "b) List members with overdue Assets\n";
        cout << "c) List members in a specified area code\nq) Quit\n";

        cin >> choice; 
        tolower(choice);

        switch (choice) {
            case 'a':
            case 'b':
            case 'c':
            case 'q':
                return;
            default:
                cout << "Invalid choice\n";
        }
    }
}
