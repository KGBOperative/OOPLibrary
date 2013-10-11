// File: Asset.cpp
// Author: Amandeep Gill
// Contents: This file contains the implementation of the Asset class

Asset::Asset(void) {
}

void Asset::SetType (string TypeS)
{
    switch (TypeS)
    {
        case "SHORT": Type = SHORT; break;
        case "LITERARY": Type = LITERARY; break;
        case "MYSTERY": Type = MYSTERY; break;
        case "SCIFI": Type = SCIFI; break;
        case "SELFHELP": Type = SELFHELP; break;
        case "BIOGRAPHY": Type = BIOGRAPHY; break;
        case "COOKING": Type = COOKING; break;
        case "SPORTS": Type = SPORTS; break;
        default: cout << "Not a valid LibType" << endl;
    }
}
