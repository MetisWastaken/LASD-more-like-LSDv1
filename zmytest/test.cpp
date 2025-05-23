

#include "vector/vectorTest.cpp"
#include "list/listTest.cpp"
#include "set/setTest.cpp"


#include <iostream>

using namespace std;


void test1();
void test2();

void mytest(){
    cout << endl << "----- Welcome to My Test Suite! -----" << endl;
  test1();
  test2();
}

void test1(){

    uint loctestnum = 0, loctesterr = 0;
    uint stestnum = 0, stesterr = 0;

lasd::vectorTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  lasd::listTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  lasd::setTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

    cout << endl << "----- Test Suite Summary -> Vector and List -----" << stesterr << " - " << stestnum << ")" << endl;
    cout << "Total tests: " << stestnum << endl;
    cout << "Total errors: " << stesterr << endl;
}

