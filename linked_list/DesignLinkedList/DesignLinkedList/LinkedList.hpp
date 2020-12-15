//
//  LinkedList.hpp
//  DesignLinkedList
//
//  Created by ChengnanHu on 11/2/20.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

#define MAX_SIZE 10

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    
    Node();
};

class LinkedList
{
public:
    int len;
    Node *head;
    int max_size;
    
    LinkedList();
    /*
     * Get the value of the index-th node in the linked list.
     * If the index is invalid, return -1.
     */
    int get(int index);
    
    /*
     * Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked list.
     */
    void addAtHead(int val);
    
    /*
     * Append a node of value val to the last element of the linked list.
     */
    void addAtTail(int val);
    
    /*
     * Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list,
     * the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted.
     */
    void addAtIndex(int index, int val);
    
    /*
     * Delete the index-th node in the linked list, if the index is valid.
     */
    void deleteAtIndex(int index);
    
    /* print linked list */
    void print();
};

#endif /* LinkedList_hpp */
