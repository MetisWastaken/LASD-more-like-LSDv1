#include <iostream>


using namespace std; 

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"

namespace lasd
{
  void testVectorInt(uint & testnum, uint & testerr) 
  {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Vector<int> Test:" << endl;
    try {  
        lasd::SortableVector<int> vec;
        Empty(loctestnum, loctesterr, vec, true);
        SetFront(loctestnum, loctesterr, vec, true, 1);
        GetFront(loctestnum, loctesterr, vec, true, 1);

        SetAt(loctestnum, loctesterr, vec, true, 1, 2);
        GetAt(loctestnum, loctesterr, vec, true, 1, 2);

        Exists(loctestnum, loctesterr, vec, true, 1);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        lasd::SortableVector<int> equalVec1 = vec;
        // Test copy constructor-comparing vec and equalVec1
        EqualVector(loctestnum, loctesterr, vec, equalVec1, true);

        lasd::SortableVector<int> equalVec2 = move(vec);
        // Test move constructor-comparing vec and equalVec2
        EqualVector(loctestnum, loctesterr, vec, equalVec2, true);
        NonEqualVector(loctestnum, loctesterr, vec, equalVec2, true);
        EqualVector(loctestnum, loctesterr, equalVec1, equalVec2, true);

        vec = equalVec1;

        Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);   //Test Traverse
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        vec.Clear();  // Test Clear
        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);

        vec.Resize(0); //resize to 0
        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);
        vec = equalVec1;  

        vec.Resize(32); //resize to big size
        GetFront(loctestnum, loctesterr, vec, true, 1);
        vec = equalVec1;

        vec.Resize(1); //resize to small size
        GetFront(loctestnum, loctesterr, vec, true, 1);
        vec = equalVec1;

        vec.Sort(); //test sorting algorithm
        GetFront(loctestnum, loctesterr, vec, true, 5);
        GetAt(loctestnum, loctesterr, vec, true, 5, 3);
        GetAt(loctestnum, loctesterr, vec, true, 1, 9);
        GetBack(loctestnum, loctesterr, vec, true, 9);

        } catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
        }
        cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl
    }
}