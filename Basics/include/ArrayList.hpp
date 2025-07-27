#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>

template <typename T>
class ArrayList
{

    public:

        //Constructor
        ArrayList();
        //Destructor
        ~ArrayList();

        //Manipulation functions
        void Insert(T data);
        void Remove(T data, bool all = false);

        //Getter functions
        int GetSize() const { return this->size; }
        int GetCap() const { return this->capacity; }
        
        void Print();
    private:
        //Members  

        int size;         // The current size of the list  
        int capacity;     // The overall capacity of the list
        T* arrayData;     // The data being stored in memory
        
        //Helper Function
        void Resize();


};

//------Implementations-----------

//Constructor
template <typename T>
ArrayList<T>::ArrayList() : size(0), capacity(10), arrayData(new T[capacity]) {}

//Destructor
template <typename T>
ArrayList<T>::~ArrayList() { delete[] arrayData; }

//------Member Functions----------


//Insert
template <typename T>
void ArrayList<T>::Insert(T data)
{

    // First: Is the array full?
    if(this->size == this->capacity) Resize();

    // Second: Append the element 
    this->arrayData[this->size] = data;
    
    // Third: increment size
    this->size++; 
}

//Remove
template <typename T>
void ArrayList<T>::Remove(T data, bool all)
{
    //Cycle through the list
    for (auto idx = 0; idx < this->size; ++idx) 
    {
        //Does the data exist in this list?
        if (this->arrayData[idx] == data) 
        {
            //Yes! Refactor the array from point x to end
            for (auto jdx = idx; jdx < this->size - 1; ++jdx) 
            {
                this->arrayData[jdx] = this->arrayData[jdx + 1];
            }
            this->size--;
            if(!all) break;
            else --idx;
        }
    }
}

//Resize
template <typename T>
void ArrayList<T>::Resize()
{
    //Define new capacity
    int newCap = capacity*2;

    //Create temp buffer with new capacity
    T* temp = new T[newCap];

    // Move elements over
    for (auto idx = 0; idx < GetSize(); ++idx) 
    {
        temp[idx] = arrayData[idx];
    }

    delete[] arrayData;
    arrayData = temp;
    this->capacity = newCap;
}

//Print
template <typename T>
void ArrayList<T>::Print()
{ 
    for (auto idx = 0; idx < this->size; ++idx) 
    {
        std::cout << "Element[" << idx << "]: " << this->arrayData[idx] << std::endl;
    }

}

#endif //ARRAYLIST_HPP

