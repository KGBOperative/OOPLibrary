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

virtual string Asset::GetType () const
{
    switch (Type)
    {
        case SHORT: return "SHORT";
        case LITERARY: return "LITERARY";
        case MYSTERY: return "MYSTERY";
        case SCIFI: return "SCIFI";
        case SELFHELP: return "SELFHELP";
        case BIOGRAPHY: return "BIOGRAPHY";
        case COOKING: return "COOKING";
        case SPORTS: return "SPORTS";
        default: return "";
    }
}
