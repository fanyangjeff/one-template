#ifndef TEAM_PROJECT_LINKEDLIST
#define TEAM_PROJECT_LINKEDLIST

template <class T>
class LinkedList {
private:
    int (*cmp)(const T, const T);
    
    struct ListNode {
        T const *data;
        ListNode *next;
    };
    
    ListNode *head;
    
public:
    LinkedList(int (*cmp)(T, T));
    ~LinkedList();
    bool insert_overflow(const T&);
    bool remove_overflow(T &dataOut);
    bool search_overflow(T &dataOut);
};

template <class T>
LinkedList<T>::LinkedList(int (*cmp)(const T, const T))
{
    head = new ListNode;
    head = nullptr;
    this->cmp = cmp;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *curr = head, *prev;
    
    while (curr)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}

template <class T>
bool LinkedList<T>::insert_overflow(const T &newRecord)
{
    ListNode *newNode;
    newNode = new ListNode;
    newNode->data = new T;
    newNode->data = &newRecord;
    newNode->next = nullptr;
    
    if(head == nullptr)
        head = newNode;
    
    else
    {
        ListNode *curr = head;
        while (curr->next)
            curr = curr->next;
        
        curr->next = newNode;
    }
    
    return true;
}



template <class T>
bool LinkedList<T>::remove_overflow(T &dataOut)
{
    ListNode *curr, *prev;
    
    if(head == nullptr)
        return false;
    
    curr = head;
    std::cout<<"over flow   "<<dataOut<<std::endl;
    if(cmp(*curr->data, dataOut) == 1)
    {
        dataOut = *curr->data;
        head = curr->next;
        delete curr;
        
        return true;
    }
    
    prev = head;
    curr = head->next;
    
    while (curr && cmp(*curr->data, dataOut) == 0)
    {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr && cmp(*curr->data, dataOut) == 1)
    {
        dataOut = *curr->data;
        prev->next = curr->next;
        curr->data = nullptr;
        delete curr;
        
        return true;
    }
    
    return false;
}

template <class T>
bool LinkedList<T>::search_overflow(T &dataOut)
{
    ListNode *nodePtr = head;
    
    while (nodePtr)
    {
        if (cmp(*nodePtr->data, dataOut) == 1)
        {
            dataOut = *nodePtr->data;
            return true;
        }
        nodePtr = nodePtr->next;
    }
    
    return false;
}


#endif //TEAM_PROJECT_LINKEDLIST_H
