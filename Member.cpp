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

Member::Member(const Member &m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;
}

Member &Member::operator=(const Member &m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;
}

LibType Member::IsA(void) const {
    return MEMBER;
}

<<<<<<< HEAD
void Member::CheckOut(Member *asset) {
    checkedOut.push_back(asset);
    asset->CheckOut(this);
=======
void Member::CheckOut(Library *L) {
    checkedOut.push_back(L);
    L->CheckOut(this);
>>>>>>> 4bc081e375eeb55d0571c9353f359f529a905a79
}

void Member::Return(string assetID) {
    for (int i; i < checkedOut.size(); i++)
        if (checkedOut[i]->ID == assetID) {
	    checkedOut[i]->Return();
	    checkedOut.erase(i);
      }
}

