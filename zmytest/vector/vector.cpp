#include <iostream>

using namespace std; 

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"


namespace lasd{
    void testVectorInt(uint & testnum, uint & testerr) 
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
            // Test move constructor - dopo il move, vec dovrebbe essere vuoto
            EqualVector(loctestnum, loctesterr, vec, equalVec2, false);
            NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
    
            vec = equalVec1;
    
            Traverse(loctestnum, loctesterr, vec,true,&TraversePrint<int>);   //Test Traverse
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

}
