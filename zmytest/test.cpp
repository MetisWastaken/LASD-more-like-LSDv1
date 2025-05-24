
// #include "list/listTest.cpp"
// #include "set/setTest.cpp"

#include "vector/vector.hpp"
#include "vector/vector.cpp"

#include "list/list.hpp"
#include "list/list.cpp"

#include "set/set.hpp"
#include "set/set.cpp"

#include <iostream>

using namespace std;


void mytest(){
    cout << endl << "----- Welcome to My Test Suite! -----" << endl;
    
    uint loctestnum = 0, loctesterr = 0;
    uint stestnum = 0, stesterr = 0;

    lasd::testVectorInt(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testListInt(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testSetInt(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    cout << endl << "----- Test Suite Summary -> Vector, List and Set -----" << endl;
    cout << "Total tests: " << stestnum << endl;
    cout << "Total errors: " << stesterr << endl;
    
}



