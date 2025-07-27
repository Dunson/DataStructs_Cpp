// Basic Linear Structures
#include "../include/ArrayList.hpp"
#include "../include/S_LinkedList.hpp"
#include "../include/D_LinkedList.hpp"
#include "../include/Queue.hpp"
#include "../include/Stack.hpp"

// Intermediate non-linear Structures


void ArrayListTest()
{
    ArrayList<int> myArray;
    
    for (int i = 0; i <= 20; i++) 
    {
        myArray.Insert(i);
    }
    myArray.Print();
    std::cout << "==========" << std::endl;

    // The size is dynamic, so we need to
    // save the state of the size outside
    // the removal loop or else 'i' will
    // eventually be larger than size
    // and will stop removing elements
    int mySize = myArray.GetSize();

    for (int i = 0; i <= mySize; i++) 
    {
        if (i % 2 == 0) 
            myArray.Remove(i, true);
    }     
    myArray.Print();
}

void SinglyListTest()
{ 
    S_LinkedList<int> mySinglyList;
    
    for (int i = 1; i <= 25; ++i) 
    {
        mySinglyList.Append(i);
    }    
    mySinglyList.Print();
    std::cout << "List Size: " << mySinglyList.GetSize() << std::endl;
    std::cout << "=======\n";
    
    for (int i = 1; i <= 25; ++i) 
    { 
        if (i % 2 != 0)        
            mySinglyList.RemoveVal(i);
        else
            mySinglyList.RemoveIdx(i);
    } 

    mySinglyList.Print();
    std::cout << "List size: " << mySinglyList.GetSize() << std::endl;
    mySinglyList.Delete();
    mySinglyList.Print();
} 
    
int main()
{
    // ArrayListTest();
    SinglyListTest();
    return 0;
 
}
