// file: P1app.cpp
// Authors: Marshall Jankovsky, 

#include <iostream>
#include <vector> 
#include <fstream>
#include "Library.h"
#include "Date.h"

using namespace std;

// container to hold the assets and members of a library.
struct lib
{
	vector<Asset> assets;
	vector<Member> members;
};

// Prototypes
char mainMenu ();
void loadLib (lib & L);
void saveLib (lib & L);
void addMember (lib & L);
void removeMember (lib & L);
void addAsset (lib & L);
void removeAsset (lib & L);
void memCheckout (lib & L);
void memReturn (lib & L);
void makeReport(lib & L const);

int main()
{
	// initialize our library
	lib L;
	char choice = NULL;
	while (choice != 'q')
	{
		choice = mainMenu();
		if (choice == 'a') 
			loadLib(lib L);
		else if (choice == 'b') 
			saveLib(L);
		else if (choice == 'c') 
			addMember(L);	
		else if (choice == 'd')
			removeMember(L);
		else if (choice == 'e')
			addAsset(L);
		else if (choice == 'f')
			removeAsset(L);
		else if (choice == 'g')
			memCheckout(L);
		else if (choice == 'h')
			memReturn(L);
		else if (choice == 'i')
			makeReport(L);
		else if (choice != 'q')
			cout << "Invalid choice\n";
		cout << endl;
	}
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

void loadLib(lib & L)
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

void saveLib(lib & L)
{return;}

void addMember(lib & L)
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

void removeMember(lib & L)
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
void addAsset(lib & L)
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

void makeReport(lib & L const)
{
	char choice = NULL; 
	while (choice != 'q')
	{
		cout << "Report Menu:\na) List overdue Assets\n";
		cout << "b) List members with overdue Assets\n";
		cout << "c) List members in a specified area code\nq) Quit\n";
		cin >> choice; 
		tolower(choice);
		if (choice == 'a')
			return; 
		else if (choice == 'b')
			return;
		else if (choice == 'c')
			return;
		else if (choice != 'q')
			cout << "Invalid choice\n";
	}
}


