//
//  main.cpp
//  iru_algorithm: value oriented
//
//  Created by ChengnanHu on 11/13/20.
//

#include <iostream>
#include "../DesignLinkedList/LinkedList.hpp"

using namespace std;

void lru_insert(LinkedList *list, int val);


int main(int argc, const char * argv[])
{
    LinkedList myll = LinkedList();
    for (int i=1; i<5; i++)
    {
        myll.addAtTail(i);
    }
    myll.print();

    lru_insert(&myll, 2);
    myll.print();
    return 0;
}

void lru_insert(LinkedList *list, int val)
{
    int i = 0;
    Node *p=list->head;
    /* if list contains node in same val i is the index */
    /* else i is list->len */
    for (; p!=NULL&&p->val!=val; p=p->next, i++);
    if (i < list->len)
    {
        list->deleteAtIndex(i);
        list->addAtHead(val);
    }
    
    else if (i == list->len)
    {
        /* first check if the linkedlist is full */
        if (list->len >= list->max_size)
            list->deleteAtIndex(list->len-1);
        
        list->addAtHead(val);
    }
    
    else
    {
        cout << "Failed" << endl;
    }
}
