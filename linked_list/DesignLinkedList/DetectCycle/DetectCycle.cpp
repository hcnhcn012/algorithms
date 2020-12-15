//
//  DetectCycle.cpp
//  DetectCycle
//
//  Created by ChengnanHu on 11/5/20.
//

#include <stdio.h>
#include "../DesignLinkedList/LinkedList.hpp"

using namespace std;

Node *detectCycle(Node *head);

int main(int argc, const char * argv[])
{
    LinkedList *myLinkedList = new LinkedList();
    /* Test case: 3->2->0->4
     *               ^-----'
     */
    myLinkedList->addAtTail(3);
    myLinkedList->addAtTail(2);
    myLinkedList->addAtTail(0);
    myLinkedList->addAtTail(4);
    Node *p2, *p4, *head;
    for (head=myLinkedList->head; head!=NULL; head=head->next)
    {
        if (head->val == 2)
            p2 = head;
        if (head->val == 4)
            p4 = head;
    }
    p4->next = p2;
    cout << detectCycle(myLinkedList->head)->val << endl;
}

Node *detectCycle(Node *head)
{
    if (head == NULL)
        return NULL;
    
    Node *pslow = head;
    Node *pfast = head->next;
    Node *pmeet = NULL;
    int cycle_flag = 0;
    
    for (; pslow!=NULL&&pfast!=NULL; pslow=pslow->next)
    {
        if (pslow == pfast)
        {
            cycle_flag = 1;
            pmeet = pslow;
            break;
        }
        if (pfast->next == NULL)
            break;
        pfast = pfast->next->next;
    }
    
    if (cycle_flag == 0)
        return NULL;
    
    /* when linked list has cycle */
    Node *p1 = head;
    int find = 0;
    
    /* cycle node should be in the head Node to the Meet Node */
    for (;;)
    {
        int flag=0;
        for (Node *p2=pmeet; p2!=pmeet||flag==0; p2=p2->next)
        {
            flag++;
            if (p1 == p2)
            {
                find = 1;
                break;
            }
        }
        if (find == 0)
            p1 = p1->next;
        else if (find == 1)
            break;
    }
    
    return p1;
}
