//
//  bth.cpp
//  binary_tree
//
//  Created by ChengnanHu on 11/23/20.
//

#include <iostream>
#include <vector>

#include "bth.hpp"

Node::Node(int _val)
{
    left = nullptr;
    right = nullptr;
    val = _val;
}

heap::heap(byte _type)
{
    /* 0 for minheap, 1 for maxheap */
    this->nnodes = 0;
    this->type = _type;
    
    _type & byte(1) ? \
        this->__storage = std::vector<int> (MAX_HEAP_SIZE+1, INT_MAX) : \
        this->__storage = std::vector<int> (MAX_HEAP_SIZE+1, INT_MIN);
}

void heap::print_heap()
{
    int i=1;
    for (; i<=this->nnodes; i++)
    {
        std::cout << this->__storage[i] << ' ';
    }
    std::cout << std::endl;
}

int heap::size()
{
    return this->nnodes;
}

int heap::get_root()
{
    return this->__storage[1];
}

void heap_insert(heap *hp, int val)
{
    /* start from 1 */
    int insert_pos = hp->nnodes + 1;
    if (insert_pos > MAX_HEAP_SIZE)
    {
        std::cout << "Exceed max heap size!" << std::endl;
        return;
    }
    hp->__storage[insert_pos] = val;
    hp->nnodes++;
    
    /* heap violation check */
    switch (hp->type)
    {
        case 0:
            for (int pos=insert_pos; pos>0; pos=pos/2)
            {
                int &child = hp->__storage[pos];
                int &father = hp->__storage[insert_pos/2];
                if (child < father)
                {
                    /* swap child and father's value */
                    int temp = father;
                    father = child;
                    child = temp;
                }
                else
                    break;
            }
            break;
            
        case 1:
            for (int pos=insert_pos; pos>1; pos=pos/2)
            {
                int &child = hp->__storage[pos];
                int &father = hp->__storage[insert_pos/2];
                if (child > father)
                {
                    /* swap child and father's value */
                    int temp = father;
                    father = child;
                    child = temp;
                }
                else
                    break;
            }
            break;
            
        default:
            break;
    }
}

int heap_search(heap *hp, int val)
{
    int i=0;
    for (; i<=hp->nnodes; i++)
    {
        if (hp->__storage[i] == val)
            return i;
    }
    return -1;
}

void heap_remove(heap *hp, int val)
{
    int val_pos = heap_search(hp, val);
    if (val_pos == -1)
    {
        std::cout << "Not found" << std::endl;
        return;
    }
    int pos = val_pos;
    /* Swap node to remve with the last node */
    hp->__storage[val_pos] = hp->__storage[hp->nnodes];
    
    switch (hp->type)
    {
        case 1:/* Max heap */
            hp->__storage[hp->nnodes] = INT_MAX;
            hp->nnodes--;
            for (; 2*pos<=hp->nnodes; )
            {
                int left_pos = 2 * pos;
                int right_pos = 2 * pos + 1;
                int max_pos;
                hp->__storage[left_pos] > hp->__storage[right_pos] ? \
                    max_pos = left_pos : max_pos = right_pos;
                if (hp->__storage[pos] < hp->__storage[max_pos])
                {
                    /* swap current node with max node */
                    int temp = hp->__storage[pos];
                    hp->__storage[pos] = hp->__storage[max_pos];
                    hp->__storage[max_pos] = temp;
                }
                pos = max_pos;
            }
            break;
            
        case 0:/* min heap */
            hp->__storage[hp->nnodes] = INT_MIN;
            hp->nnodes--;
            for (; 2*pos<=hp->nnodes; )
            {
                int left_pos = 2 * pos;
                int right_pos = 2 * pos + 1;
                int max_pos;
                hp->__storage[left_pos] > hp->__storage[right_pos] ? \
                    max_pos = left_pos : max_pos = right_pos;
                if (hp->__storage[pos] > hp->__storage[max_pos])
                {
                    /* swap current node with max node */
                    int temp = hp->__storage[pos];
                    hp->__storage[pos] = hp->__storage[max_pos];
                    hp->__storage[max_pos] = temp;
                }
                pos = max_pos;
            }
            break;
            
        default:
            break;
    }
}

int heap_pop_root(heap *hp)
{
    int root = hp->__storage[1];
    heap_remove(hp, root);
    return root;
}

int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->val);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void print_t(Node *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}
