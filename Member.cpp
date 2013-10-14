// File: Member.cpp
// Authors: Amandeep Gill
// Contents: This file contains the implementation of the Member class

#include "Member.h"

Member::Member(void) {
    Type = MEMBER;

    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";
    Name = "";
    ID = "";
}

Member::Member (string name, string id, string Address, string City, string State, string Zip, string Phone) {
    Type = MEMBER;
    Name = name;
    ID = id;
    address = address;
    city = city;
    state = state;
    zip = zip;
    phone = phone;
}

Member::Member(const Member & m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;
}

Member & Member::operator=(const Member & m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;

    return *this;
}

void Member::Add(shared_ptr<Library> asset, Date date, int number) {
    checkedOut.push_back(asset);
}

void Member::Remove(shared_ptr<Library> asset, int number) {
    for (unsigned int i = 0; i < checkedOut.size(); ++i) {
        if (checkedOut[i] == asset) {
            checkedOut.erase(checkedOut.begin() + i);
            return;
        }
    }
}

void Member::ReadIn(istream &input) {
    while (input.good()) {
        string field;
        input >> field;

        if (field == "Name:")
            getline(input, Name);

        else if (field == "ID:")
            input >> ID;

        else if (field == "Address:")
            getline(input, address);

        else if (field == "City:")
            getline(input, city);

        else if (field == "State:")
            getline(input, state);

        else if (field == "Zip:")
            getline(input, zip);

        else if (field == "Phone_Number:") {
            getline(input, phone);
            return;
        }
    }
}

void Member::WriteOut(ostream &output) {
    output << "Type: " << Library::GetType() << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Address: " << address << endl;
    output << "City: " << city << endl;
    output << "State: " << state << endl;
    output << "Zip: " << zip << endl;
    output << "Phone_Number: " << phone << endl;
    output << "Checked_Out: " << checkedOut.size();

    for (unsigned int i = 0; i < checkedOut.size(); ++i) {
        output << " " << checkedOut[i]->GetID();
    }

    output << endl << endl;
}

