#include <iostream>

using namespace std; 

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

#include "../set/set.hpp"

namespace lasd{
    void testSetInt(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of Set<int> Test:" << endl;
        try {  
            // Test SetVec
            cout << endl << "Testing SetVec..." << endl;
            lasd::SetVec<int> setvec;
            Empty(loctestnum, loctesterr, setvec, true);
            Size(loctestnum, loctesterr, setvec, true, 0);
            
            // insert elements
            InsertC(loctestnum, loctesterr, setvec, true, 5);
            InsertC(loctestnum, loctesterr, setvec, true, 3);
            InsertC(loctestnum, loctesterr, setvec, true, 8);
            InsertC(loctestnum, loctesterr, setvec, false, 5); // Duplicate should fail
            
            Size(loctestnum, loctesterr, setvec, true, 3);
            Exists(loctestnum, loctesterr, setvec, true, 5);
            Exists(loctestnum, loctesterr, setvec, true, 3);
            Exists(loctestnum, loctesterr, setvec, true, 8);
            Exists(loctestnum, loctesterr, setvec, false, 10);
    
            TraversePreOrder(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    
            // Test copy constructor and compare
            lasd::SetVec<int> equalSetVec1 = setvec;
            EqualSetVec(loctestnum, loctesterr, setvec, equalSetVec1, true);
    
            // Test move constructor
            lasd::SetVec<int> equalSetVec2 = move(setvec);
            EqualSetVec(loctestnum, loctesterr, setvec, equalSetVec2, false);
            NonEqualSetVec(loctestnum, loctesterr, setvec, equalSetVec2, true);
    
            setvec = equalSetVec1;
    
            // Test SetLst
            cout << endl << "Testing SetLst..." << endl;
            lasd::SetLst<int> setlst;
            Empty(loctestnum, loctesterr, setlst, true);
            Size(loctestnum, loctesterr, setlst, true, 0);
            
            // Inserisco elementi nel SetLst
            InsertC(loctestnum, loctesterr, setlst, true, 5);
            InsertC(loctestnum, loctesterr, setlst, true, 3);
            InsertC(loctestnum, loctesterr, setlst, true, 8);
            InsertC(loctestnum, loctesterr, setlst, false, 5); // Duplicate should fail
            
            Size(loctestnum, loctesterr, setlst, true, 3);
            Exists(loctestnum, loctesterr, setlst, true, 5);
            Exists(loctestnum, loctesterr, setlst, true, 3);
            Exists(loctestnum, loctesterr, setlst, true, 8);
    
            TraversePreOrder(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    
            lasd::SetLst<int> equalSetLst1 = setlst;
            // Test copy constructor-comparing 
            EqualSetLst(loctestnum, loctesterr, setlst, equalSetLst1, true);
    
            lasd::SetLst<int> equalSetLst2 = move(setlst);
            // Test move constructor
            EqualSetLst(loctestnum, loctesterr, setlst, equalSetLst2, false);
            NonEqualSetLst(loctestnum, loctesterr, setlst, equalSetLst2, true);
    
            setlst = equalSetLst1;
    
            // Test equality between SetVec and SetLst
            EqualLinear(loctestnum, loctesterr, setlst, setvec, true);
    
            // Test Clear func
            setvec.Clear();
            setlst.Clear();
            Empty(loctestnum, loctesterr, setvec, true);
            Empty(loctestnum, loctesterr, setlst, true);
            Size(loctestnum, loctesterr, setvec, true, 0);
            Size(loctestnum, loctesterr, setlst, true, 0);
    
            // Test Remove
            InsertC(loctestnum, loctesterr, setvec, true, 7);
            Remove(loctestnum, loctesterr, setvec, true, 7);
            Empty(loctestnum, loctesterr, setvec, true);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

}