// File: Asset.cpp
// Author: Amandeep Gill
// Contents: This file contains the implementation of the Asset class

Asset::Asset(void) {
}

void Asset::SetType (string TypeS)
{
  switch (TypeS)
    {
    case "LIBRARY": Type = LIBRARY; break;
    case "MEMBER": Type = MEMBER; break;
    case "ASSET": Type = ASSET; break;
    case "BOOK": Type = BOOK; break;
    case "PERIODICAL": Type = PERIODICAL; break;
    default: cout << "Not a valid LibType" << endl;
    }
}
