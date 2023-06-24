// savejson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;
int main()
{
    
    string arr[11];
    int state;
    int i, j, y,k;
    string id[]={"id","state","catagory","title","description","icon","title","image","description","video","id","link"};
    cout << "Enter the data:\n";
    for ( i = 0,  j = 0,k=0; k<12 ; i++, j++,k++) {
        cout << "\nEnter " << id[j]<<":";
        if (j == 1) {
            cin >> state;
            i--;
        }
        else {
            cin>> arr[i];
        }

    }

    boost::property_tree::ptree pt;
    boost::property_tree::ptree cue;
    boost::property_tree::ptree pagecontent;
    boost::property_tree::ptree moreinfo;
    boost::property_tree::ptree page;
    boost::property_tree::ptree discoverylist;
    boost::property_tree::ptree discoverylistarr;
    boost::property_tree::ptree pagecontentarr;
    boost::property_tree::ptree moreinfoarr;

    for (i = 2, j = 3, k = 0; k < 3; i++, j++, k++) {
        cue.put(id[j], arr[i]);
    }
    for (i = 5, j = 6, k = 0; k < 4; i++, j++, k++) {
        pagecontent.put(id[j], arr[i]);
    }
    for (i = 9, j = 10, k = 0; k < 2; i++, j++, k++) {
        moreinfo.put(id[j], arr[i]);
    }
    pagecontentarr.push_back(make_pair("", pagecontent));
    moreinfoarr.push_back(make_pair("", moreinfo));
    page.add_child("pageContent", pagecontentarr);
    page.add_child("moreInfo", moreinfoarr);
    
    discoverylist.put(id[0],arr[0]);
    discoverylist.put(id[1],(1));
    discoverylist.put(id[2], arr[1]);
    discoverylist.add_child("cue", cue);
    discoverylist.add_child("page", page);

    discoverylistarr.push_back(make_pair("", discoverylist));
    
    pt.add_child("discoverList", discoverylistarr);
    
    try {
        boost::property_tree::write_json("output.json", pt);
        std::cout << "JSON file created and written successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating or writing JSON file: " << e.what() << std::endl;
        return 1;
    }

    
    _getch();
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
