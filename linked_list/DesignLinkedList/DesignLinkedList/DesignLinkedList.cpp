/*
 *  main.cpp
 *  DesignLinkedList
 *
 *  Created by ChengnanHu on 10/30/20.
 *
 */

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    
    LinkedList* myll = new LinkedList();
    myll->addAtHead(1);
    myll->addAtHead(2);
    myll->addAtTail(1);
    myll->get(0);
    myll->get(1);
    myll->get(2);
    myll->print();
    myll->addAtIndex(4, 3);
    myll->deleteAtIndex(3);
}
