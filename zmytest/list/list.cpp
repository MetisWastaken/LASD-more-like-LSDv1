#include <iostream>

using namespace std; 

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../list/list.hpp"

namespace lasd{
    void testListInt(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of List Test:" << endl;
        try {  
            lasd::List<int> lst;
            Empty(loctestnum, loctesterr, lst, true);
            
            // Insert elements at the front
            InsertAtFront(loctestnum, loctesterr, lst, true, 1);
            GetFront(loctestnum, loctesterr, lst, true, 1);
    
            InsertAtFront(loctestnum, loctesterr, lst, true, 3);
            GetFront(loctestnum, loctesterr, lst, true, 3);
    
            Exists(loctestnum, loctesterr, lst, true, 1);
            Exists(loctestnum, loctesterr, lst, true, 3);
    
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
    
            lasd::List<int> equalLst1 = lst;
            // Test copy constructor-comparing 
            EqualList(loctestnum, loctesterr, lst, equalLst1, true);
    
            lasd::List<int> equalLst2 = move(lst);
            // Test move constructor - should be empty at the end
            EqualList(loctestnum, loctesterr, lst, equalLst2, false);
            NonEqualList(loctestnum, loctesterr, lst, equalLst2, true);
    
            lst = equalLst1;
    
            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<int>);   //Test Traverse
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
    
            lst.Clear();  // Test Clear func
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
    
            // Test RemoveFromFront
            InsertAtFront(loctestnum, loctesterr, lst, true, 5);
            RemoveFromFront(loctestnum, loctesterr, lst, true);
            Empty(loctestnum, loctesterr, lst, true);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

}
