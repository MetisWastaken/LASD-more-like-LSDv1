
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

    lasd::testVector(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testVectorChar(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testVectorDouble(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testVectorWithCharList(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testLis(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testListChar(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testListDouble(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testSet(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testSetChar(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    loctestnum = 0; loctesterr = 0;
    lasd::testSetDouble(loctestnum, loctesterr);
    stestnum += loctestnum; stesterr += loctesterr;

    cout << endl << "----- My Test Suite Summary -> Vector, List and Set -----" << endl;
    cout << "Total tests: " << stestnum << endl;
    cout << "Total errors: " << stesterr << endl;
    cout << "Goodbye! " << endl;
    
}



