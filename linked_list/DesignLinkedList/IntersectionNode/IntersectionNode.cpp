//
//  main.cpp
//  IntersectionNode
//
//  Created by ChengnanHu on 11/8/20.
//

#include <iostream>
#include <map>
#include "../DesignLinkedList/LinkedList.hpp"

using namespace std;
Node *getIntersectionNode(Node *headA, Node *headB);
Node *getIntersectionNodeV2(Node *headA, Node *headB);

int main(int argc, const char * argv[])
{
    /* codes are tested in leetcode problem 160 */
    return 0;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    map<Node *, int> refmap;
    for (Node *pa=headA; pa!=NULL; pa=pa->next)
        refmap[pa] = 1;
    for (Node *pb=headB; pb!=NULL; pb=pb->next)
    {
        map<Node *, int>::iterator iter = refmap.find(pb);
        if (iter != refmap.end())
        {
            return pb;
        }
    }
    return NULL;
}

Node *getIntersectionNodeV2(Node *headA, Node *headB)
{
    Node *pa = headA;
    Node *pb = headB;
    /* assert the linked list has no cycle */
    while (pa != NULL || pb != NULL)
    {
        if (pa == pb)
            return pa;
        else if (pa == NULL || pb == NULL)
        {
            if (pa == NULL)
            {
                pa = headB;
                pb = pb->next;
                continue;
            }
            if (pb == NULL)
            {
                pb = headA;
                pa = pa->next;
                continue;
            }
        }
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}
