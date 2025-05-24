#include <iostream>

using namespace std; 

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"


namespace lasd{
    void testVector(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of Vector Test:" << endl;
        try {  
            lasd::SortableVector<int> vec;
            Empty(loctestnum, loctesterr, vec, true);
            
            // need resize 

            vec.Resize(2);
            SetFront(loctestnum, loctesterr, vec, true, 1);
            GetFront(loctestnum, loctesterr, vec, true, 1);
    
            SetAt(loctestnum, loctesterr, vec, true, 1, 3);
            GetAt(loctestnum, loctesterr, vec, true, 1, 3);
    
            Exists(loctestnum, loctesterr, vec, true, 1);
    
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
    
            lasd::SortableVector<int> equalVec1 = vec;
            // Test copy constructor-comparing 
            EqualVector(loctestnum, loctesterr, vec, equalVec1, true);
    
            lasd::SortableVector<int> equalVec2 = move(vec);
            // Test move constructor - empty post move
            EqualVector(loctestnum, loctesterr, vec, equalVec2, false);
            NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
    
           
    
            Traverse(loctestnum, loctesterr, vec,true,&TraversePrint<int>); 
            TraversePreOrder(loctestnum ,loctesterr ,vec,true,&TraversePrint<int>);
            TraversePostOrder(loctestnum ,loctesterr ,vec,true,&TraversePrint<int>);
    
            vec.Clear();  // Test Clear func
            Empty(loctestnum ,loctesterr ,vec,true);
            Size(loctestnum ,loctesterr ,vec,true ,0);
    
            vec.Resize(0); //resize function to 0

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

    void testVectorChar(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of Vector<char> Test:" << endl;
        try {  
            lasd::SortableVector<char> vec;
            Empty(loctestnum, loctesterr, vec, true);
            
            vec.Resize(2);
            SetFront(loctestnum, loctesterr, vec, true, 'A');
            GetFront(loctestnum, loctesterr, vec, true, 'A');
    
            SetAt(loctestnum, loctesterr, vec, true, 1, 'C');
            GetAt(loctestnum, loctesterr, vec, true, 1, 'C');
    
            Exists(loctestnum, loctesterr, vec, true, 'A');
    
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
    
            lasd::SortableVector<char> equalVec1 = vec;
            EqualVector(loctestnum, loctesterr, vec, equalVec1, true);
    
            lasd::SortableVector<char> equalVec2 = move(vec);
            EqualVector(loctestnum, loctesterr, vec, equalVec2, false);
            NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
    
            vec = equalVec1;
    
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
    
            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
    
            vec.Resize(0);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Vector<char> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

    void testVectorDouble(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of Vector<double> Test:" << endl;
        try {  
            lasd::SortableVector<double> vec;
            Empty(loctestnum, loctesterr, vec, true);
            
            vec.Resize(2);
            SetFront(loctestnum, loctesterr, vec, true, 1.5);
            GetFront(loctestnum, loctesterr, vec, true, 1.5);
    
            SetAt(loctestnum, loctesterr, vec, true, 1, 3.7);
            GetAt(loctestnum, loctesterr, vec, true, 1, 3.7);
    
            Exists(loctestnum, loctesterr, vec, true, 1.5);
    
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
    
            lasd::SortableVector<double> equalVec1 = vec;
            EqualVector(loctestnum, loctesterr, vec, equalVec1, true);
    
            lasd::SortableVector<double> equalVec2 = move(vec);
            EqualVector(loctestnum, loctesterr, vec, equalVec2, false);
            NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
    
            vec = equalVec1;
    
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
    
            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
    
            vec.Resize(0);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

    void testVectorWithCharList(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of Vector Test with Character List:" << endl;
        try {  
            //list of chr
            std::vector<char> mylist = {'A', 'B', 'C', 'D', 'E'};
            
            lasd::SortableVector<char> vec;
            Empty(loctestnum, loctesterr, vec, true);
            
            
            vec.Resize(mylist.size());
            
            //add elements to the vector
            for(uint i = 0; i < mylist.size(); ++i) {
                SetAt(loctestnum, loctesterr, vec, true, i, mylist[i]);
                GetAt(loctestnum, loctesterr, vec, true, i, mylist[i]);
            }
            
            // Test front  back
            GetFront(loctestnum, loctesterr, vec, true, mylist[0]); // 'A'
            GetBack(loctestnum, loctesterr, vec, true, mylist[mylist.size()-1]); // 'E'
    
            // Test existence of characters in the vector
            for(const char& c : mylist) {
                Exists(loctestnum, loctesterr, vec, true, c);
            }
            
            // Test exist
            Exists(loctestnum, loctesterr, vec, false, 'Z');
    
            // Test traversal
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
    
            // Test copy constructor
            lasd::SortableVector<char> equalVec1 = vec;
            EqualVector(loctestnum, loctesterr, vec, equalVec1, true);
    
            // Test move constructor
            lasd::SortableVector<char> equalVec2 = move(vec);
            EqualVector(loctestnum, loctesterr, vec, equalVec2, false);
            NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
    
            // Restore vec
            vec = equalVec1;
         
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<char>);
            
            std::vector<char> newChars = {'X', 'Y', 'Z'};
            for(uint i = 0; i < newChars.size() && i < vec.Size(); i++) {
                SetAt(loctestnum, loctesterr, vec, true, i, newChars[i]);
                GetAt(loctestnum, loctesterr, vec, true, i, newChars[i]);
            }
            
            // Test clear
            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Vector Test with Character List! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

}
