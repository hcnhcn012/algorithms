//
//  LinkedList.cpp
//  DesignLinkedList
//
//  Created by ChengnanHu on 11/2/20.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

Node::Node() {}

LinkedList::LinkedList()
{
    this->len = 0;
    this->max_size = MAX_SIZE;
    this->head = NULL;
}

int LinkedList::get(int index)
{
    Node *pnode;
    int i;
    i = 0;
    for (pnode=this->head; pnode!=NULL&&i<this->len; pnode=pnode->next, i++)
    {
        if (i == index)
            return pnode->val;
    }
    return -1;
}

void LinkedList::addAtHead(int val)
{
    Node *new_node;
    new_node = new Node();
    new_node->val = val;
    
    new_node->next = this->head;
    this->head = new_node;
    
    
    this->len++;
}

void LinkedList::addAtTail(int val)
{
    if (this->len == 0)
        return this->addAtHead(val);
    else
    {
        Node *pnode = this->head;
        /* move to tail */
        for (; pnode->next!=NULL; pnode=pnode->next);
        
        Node *new_node;
        new_node = new Node();
        new_node->val = val;
        new_node->next = NULL;
        
        pnode->next = new_node;

        this->len++;
    }
}

void LinkedList::addAtIndex(int index, int val)
{
    if (index == 0)
        return addAtHead(val);
    
    int i;
    i = 0;
    Node *pnode;
    for (pnode=this->head; pnode!=NULL&&i<this->len; pnode=pnode->next, i++)
    {
        /* find previous node */
        if (i == index - 1)
        {
            Node *new_node;
            new_node = new Node();
            new_node->val = val;
            
            new_node->next = pnode->next;
            pnode->next = new_node;
            
            this->len++;
        }
    }
    return;
}

void LinkedList::deleteAtIndex(int index)
{
    if (index == 0)
        this->head = this->head->next;
    else if (index > 0 && index < this->len)
    {
        int i = 0;
        Node *pnode = this->head;
        /* find previous node */
        for (; pnode!=NULL&&i<this->len; pnode=pnode->next, i++)
        {
            if (i == index - 1)
                pnode->next = pnode->next->next;
        }
    }
    this->len--;
}

void LinkedList::print()
{
    Node *pnode = this->head;
    cout << "Linked List at object at <" \
         << this \
         << ">\n" \
         << "has " << this->len << " vals\n";
    for (; pnode!=NULL; pnode=pnode->next)
        cout << pnode->val << "->";
    cout << "END" << endl;
}

