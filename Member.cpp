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

Member::Member (string name, string id, string address, string city, string state, string zip, string phone) {
    this->Name = name;
    this->ID = id;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
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

void Member::Add(shared_ptr<Library> asset, Date date) {
    checkedOut.push_back(asset);
}

void Member::Remove(shared_ptr<Library> asset) {
    for (unsigned int i = 0; i < checkedOut.size(); ++i) {
        if (checkedOut[i] == asset) {
            checkedOut.erase(checkedOut.begin() + i);
            return;
        }
    }
}

void Member::ReadIn(istream &input) {
}

void Member::WriteOut(ostream &output) {
}

