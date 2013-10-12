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

Member::Member(const shared_ptr<Member> m) {
    address = m->address;
    city = m->city;
    state = m->state;
    zip = m->zip;
    phone = m->phone;
    Name = m->Name;
    ID = m->ID;
    checkedOut = m->checkedOut;
}

shared_ptr<Member> Member::operator=(const shared_ptr<Member> m) {
    address = m->address;
    city = m->city;
    state = m->state;
    zip = m->zip;
    phone = m->phone;
    Name = m->Name;
    ID = m->ID;
    checkedOut = m->checkedOut;
}

void Member::Add(shared_ptr<Library> asset, Date date) {
    CheckedOut->push_back(asset);
}

void Member::Remove(shared_ptr<Library> asset) {
    // check if asset exists in the vector and remove it
}
