#ifndef S_LINKEDLIST_HPP
#define S_LINKEDLIST_HPP

#include <iostream>

template <typename T>
class S_LinkedList
{
    public:
        S_LinkedList();
        ~S_LinkedList();
        
        void Append(T data);
        void Prepend(T data);
        void RemoveVal(T data);
        void RemoveIdx(int idx);

        void RemoveHead();
        void Delete(); 

        int GetSize() const { return this->size; };
        void Print();

    private:
        struct Node
        {
            T data;     // Data Stored on the Node
            Node* next; // Pointer to the next Node      

            Node(const T& data) : data(data), next(nullptr) {}
        };

        Node* head;     // First node in the chain   
        Node* tail;     // Last node in the chain
        
        int size;       // The length of the chain
};

// Constructor
template <typename T>
S_LinkedList<T>::S_LinkedList() : head(nullptr), tail(head), size(0) {}

// Destructor
template <typename T>
S_LinkedList<T>::~S_LinkedList() 
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Append to chain
template <typename T>
void S_LinkedList<T>::Append(T data)
{
    Node* temp = new Node(data);

    if (this->head == nullptr)
    {
        this->head = temp;
        this->tail = head;
    }
    else
    {
        this->tail->next = temp;
        this->tail = temp;
    }
    this->size++;
}

// Prepend to chain
template <typename T>
void S_LinkedList<T>::Prepend(T data)
{
    Node* temp = new Node(data);

    if (this->head == nullptr)
    {
        this->head = temp;
        this->tail = head;
    }
    else
    {
        temp->next = this->head;
        this->head = temp;
    }
    this->size++;
}

// Removal Logic
template <typename T>
void S_LinkedList<T>::RemoveHead()
{
    Node* temp;

    // Is there a head?
    if (this->head == nullptr)
       return;
    
    temp = this->head;
    this->head = this->head->next;
    
    if (this->head == nullptr) 
        this->tail = head;   

    delete temp;

    this->size--;
}

// Remove by value
template <typename T>
void S_LinkedList<T>::RemoveVal(T data)
{
    Node* current = this->head;
    Node* prev;
    Node* temp;

    while(current != nullptr) 
    {
        if(current->data == data)
        {
            if (current == this->head) { this->RemoveHead(); break; }
            if (current == this->tail) { prev->next = nullptr; delete current; this->size--; break; }
            
            temp = current;
            current = current->next;
            prev->next = current;
            
            delete temp;
            this->size--;
            break;
        }
        else 
        {
            prev = current;
            current = current->next;
        }
    }
}

// Remove by Index
template <typename T>
void S_LinkedList<T>::RemoveIdx(int idx)
{
        

}

// Delete the entire List
template <typename T>
void S_LinkedList<T>::Delete()
{
    

}

// Print List
template <typename T>
void S_LinkedList<T>::Print()
{
    Node* current = this->head;
    int i = 0;
    while(current != nullptr)
    {
        i++;
        std::cout << "Node[" << i <<  "]: " << current->data << std::endl;
        current = current->next;
    }

}




#endif // S_LINKEDLIST_HPP
