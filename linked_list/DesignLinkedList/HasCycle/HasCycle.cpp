//
//  LinkedListCycle.cpp
//  LinkedListCycle
//
//  Created by ChengnanHu on 11/4/20.
//

#include <stdio.h>
#include "../DesignLinkedList/LinkedList.hpp"

using namespace std;

bool hasCycle(Node *head);

int main(int argc, const char * argv[])
{
    LinkedList *myLinkedList = new LinkedList();
//    /* Test case: 3->2->0->4->NULL */
//    myLinkedList->addAtTail(3);
//    myLinkedList->addAtTail(2);
//    myLinkedList->addAtTail(0);
//    myLinkedList->addAtTail(4);
//    cout << hasCycle(myLinkedList->head) << endl;
//
//    /* Test case: 3->2->0->4
//     *               ^-----'
//     */
//    myLinkedList->deleteAtIndex(3);
//    myLinkedList->deleteAtIndex(2);
//    myLinkedList->deleteAtIndex(1);
//    myLinkedList->deleteAtIndex(0);
//    myLinkedList->addAtTail(3);
//    myLinkedList->addAtTail(2);
//    myLinkedList->addAtTail(0);
//    myLinkedList->addAtTail(4);
//    Node *p2, *p4, *head;
//    for (head=myLinkedList->head; head!=NULL; head=head->next)
//    {
//        if (head->val == 2)
//            p2 = head;
//        if (head->val == 4)
//            p4 = head;
//    }
//    p4->next = p2;
//    cout << hasCycle(myLinkedList->head) << endl;
//
//    /* Test case: 3->NULL */
//    myLinkedList->deleteAtIndex(3);
//    myLinkedList->deleteAtIndex(2);
//    myLinkedList->deleteAtIndex(1);
//    cout << hasCycle(myLinkedList->head) << endl;
//
//    /* Test case: 3->2->3->3->2->NULL */
//    myLinkedList->addAtTail(2);
//    myLinkedList->addAtTail(3);
//    myLinkedList->addAtTail(3);
//    myLinkedList->addAtTail(2);
//    cout << hasCycle(myLinkedList->head) << endl;
    
    /* Test case: 3<- */
    /*            |__|*/
    myLinkedList->addAtTail(3);
    myLinkedList->head->next = myLinkedList->head;
    cout << hasCycle(myLinkedList->head) << endl;
}

bool hasCycle(Node *head)
{
    bool has_cycle = false;
    
    Node *pfast = head;
    Node *pslow = head;
    
    while (pfast != nullptr && pslow != nullptr)
    {
        if (pfast->next) pfast = pfast->next->next;
        pslow = pslow->next;
        
        if (pfast == pslow)
        {
            has_cycle == true;
            break;
        }
    }
    
    return has_cycle;
}

