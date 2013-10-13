// file: P1app.cpp
// Authors: Amandeep Gill, Marshall Jankovsky, 
// Contents: This file contains the driver application for the library class

#include "LibraryIO.h"
#include "Library.h"
#include "Date.h"

using namespace std;

// outputs the menu options to the terminal and reads in the user selection
char mainMenu(void) {
	char choice;
	cout << "1) Restore Library Information from a File\n";
	cout << "2) Save Library Information to a File\n";
	cout << "3) Add Library Card Holder\n";
	cout << "4) Add New Library Asset\n";
	cout << "5) Remove Library Card Holder\n";
	cout << "6) Remove Library Asset\n";
	cout << "7) Checkout Asset to Card Holder\n";
	cout << "8) Return Asset from Card Holder\n";
	cout << "9) Generate Reports\n";
	cout << "q) Quit\n";
    cout << "Select option: ";
	cin >> choice; 
	return tolower(choice);
}

int main() {
    // initialize our library
    vector<shared_ptr<Library> > L;

    char choice;
    do {
        choice = mainMenu();
        switch(choice) {
            case '1': {
                loadLib(L);
                break;
            }
            case '2': {
                saveLib(L);
                break;
            }
            case '3': {
                addMember(L);	
                break;
            }
            case '4': {
                addAsset(L);
                break;
            }
            case '5': {
                string id;
                cout << "Enter ID for the Card Holder: ";
                cin >> id;
                
                try {
                    removeItem(L, id);
                } catch (const char* e) {
                    cout << "Error: " << e << endl;
                }

                break;
            }
            case '6': {
                string id;
                cout << "Enter ID for the Asset: ";
                cin >> id;
                
                try {
                    removeItem(L, id);
                } catch (const char* e) {
                    cout << "Error: " << e << endl;
                }

                break;
            }
            case '7': {
                string memberID, assetID;
                cout << "Enter the ID of the Card Holder: ";
                cin >> memberID;
                cout << "Enter the ID of the Asset to checkout: ";
                cin >> assetID;

                try {
                    checkoutAsset(L, memberID, assetID);
                } catch (const char* e) {
                    cout << "Error: " << e << endl;
                }

                break;
            }
            case '8': {
                string memberID, assetID;
                cout << "Enter the ID of the Card Holder: ";
                cin >> memberID;
                cout << "Enter the ID of the Asset to return: ";
                cin >> assetID;

                try {
                    returnAsset(L, memberID, assetID);
                } catch (const char* e) {
                    cout << "Error: " << e << endl;
                }

                break;
            }
            case '9': {
                makeReport(L);
                break;
            }
            case 'q': {
                break;
            }
            default:
                cout << "Invalid choice\n";
        }
        cout << endl;
    } while (choice != 'q');
    return 0;			
}
