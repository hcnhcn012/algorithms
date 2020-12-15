//
//  bth.h
//  binary_tree headers
//
//  Created by ChengnanHu on 11/23/20.
//

#ifndef bth_h
#define bth_h

#include <vector>

#define MAX_HEAP_SIZE 20

typedef unsigned char byte;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    
    Node (int _val);
};

class heap
{
private:
    /* vector for storeage */
    std::vector<int> __storage;
    int nnodes;
    byte type;
    
public:
    
    heap(byte _type);
    
    void print_heap();
    int size();
    int get_root();
    
    friend int heap_search(heap *hp, int val);
    friend void heap_insert(heap *hp, int val);
    friend void heap_remove(heap *hp, int val);
    friend int heap_pop_root(heap *hp);
};

void print_t(Node *tree);
int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255]);



/*class Tree
{
public:
    Node *root;
private:
    int height, depth;
};*/
#endif /* bth_h */
