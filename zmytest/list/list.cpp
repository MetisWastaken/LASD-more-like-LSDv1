#include <iostream>

using namespace std; 

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../list/list.hpp"

namespace lasd{
    void testLis(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of List INT Test:" << endl;
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
        cout << "End of List INT Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

    void testListChar(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of List CHAR Test:" << endl;
        try {  
            lasd::List<char> lst;
            Empty(loctestnum, loctesterr, lst, true);
            
            InsertAtFront(loctestnum, loctesterr, lst, true, 'A');
            GetFront(loctestnum, loctesterr, lst, true, 'A');
    
            InsertAtFront(loctestnum, loctesterr, lst, true, 'C');
            GetFront(loctestnum, loctesterr, lst, true, 'C');
    
            Exists(loctestnum, loctesterr, lst, true, 'A');
            Exists(loctestnum, loctesterr, lst, true, 'C');
    
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<char>);
    
            lasd::List<char> equalLst1 = lst;
            EqualList(loctestnum, loctesterr, lst, equalLst1, true);
    
            lasd::List<char> equalLst2 = move(lst);
            EqualList(loctestnum, loctesterr, lst, equalLst2, false);
            NonEqualList(loctestnum, loctesterr, lst, equalLst2, true);
    
            lst = equalLst1;
    
            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<char>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<char>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<char>);
    
            lst.Clear();
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
    
            InsertAtFront(loctestnum, loctesterr, lst, true, 'X');
            RemoveFromFront(loctestnum, loctesterr, lst, true);
            Empty(loctestnum, loctesterr, lst, true);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of List CHAR Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

    void testListDouble(uint & testnum, uint & testerr) 
    {
        uint loctestnum = 0, loctesterr = 0;
        cout << endl << "Begin of List DOUBLE Test:" << endl;
        try {  
            lasd::List<double> lst;
            Empty(loctestnum, loctesterr, lst, true);
            
            InsertAtFront(loctestnum, loctesterr, lst, true, 1.5);
            GetFront(loctestnum, loctesterr, lst, true, 1.5);
    
            InsertAtFront(loctestnum, loctesterr, lst, true, 3.7);
            GetFront(loctestnum, loctesterr, lst, true, 3.7);
    
            Exists(loctestnum, loctesterr, lst, true, 1.5);
            Exists(loctestnum, loctesterr, lst, true, 3.7);
    
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    
            lasd::List<double> equalLst1 = lst;
            EqualList(loctestnum, loctesterr, lst, equalLst1, true);
    
            lasd::List<double> equalLst2 = move(lst);
            EqualList(loctestnum, loctesterr, lst, equalLst2, false);
            NonEqualList(loctestnum, loctesterr, lst, equalLst2, true);
    
            lst = equalLst1;
    
            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    
            lst.Clear();
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
    
            InsertAtFront(loctestnum, loctesterr, lst, true, 9.9);
            RemoveFromFront(loctestnum, loctesterr, lst, true);
            Empty(loctestnum, loctesterr, lst, true);

        } catch (...) {
            loctestnum++; loctesterr++;
            cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of List DOUBLE Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
        testnum += loctestnum;
        testerr += loctesterr;
    }

}
