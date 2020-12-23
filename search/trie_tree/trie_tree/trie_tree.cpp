//
//  trie_tree.cpp
//  trie_tree
//
//  Created by ChengnanHu on 12/22/20.
//

#include <queue>
#include "trie_tree.hpp"

/* trie node implementation */

trie_node::trie_node(char _data)
{
    this->data = _data;
    this->is_leaf = false;
    for (int i=0; i<MAX_HASHTABLE_SZ; i++)
    {
        this->children[i] = nullptr;
    }
}

char trie_node::get_data()
{
    return this->data;
}

void trie_node::set_leaf(bool flag)
{
    this->is_leaf = flag;
}

bool trie_node::get_leaf()
{
    return this->is_leaf;
}/* end trie node implementation*/

/* trie tree implementation */

trie_tree::trie_tree()
{
    /* generate the root node of a trie_tree */
    this->nnodes = 1;
    this->root = new trie_node('\0');
}

trie_tree::~trie_tree()
{
    /* iterate all nodes and delete them (using BFS) */
    using namespace std;
    
    int node_count = 0;
    trie_node *pnode = this->root;
    queue<trie_node *> delete_queue = queue<trie_node *>();
    delete_queue.push(pnode);
    while (!delete_queue.empty())
    {
        trie_node *node_to_delete = delete_queue.front();
        delete_queue.pop();
        for (int i=0; i<MAX_HASHTABLE_SZ; i++)
        {
            if (node_to_delete->children[i] != nullptr)
                delete_queue.push(node_to_delete->children[i]);
        }
        /* no manual memory alloction in trie_node class
         * so delete it by delete expression
         */
        delete node_to_delete;
        node_count++;
    }
    
    if (node_count == this->nnodes)
        cout << "Successfully delete the trie_tree" << endl;
    else
        cout << "Delete the trie_tree failed, memory may be dirty" << endl;
}

const trie_node *trie_tree::getroot() const
{
    return this->root;
}

int trie_tree::size()
{
    return nnodes;
}

void trie_tree::insert(std::string data)
{
    trie_node *pnode = this->root;
    
    for (int i=0; i<data.length(); i++)
    {
        /* if i-th char isn't in the tree
         * add it as a leaf
         */
        if (pnode->children[data[i]] == nullptr)
        {
            trie_node *new_node = new trie_node(data[i]);
            pnode->children[data[i]] = new_node;
            pnode->set_leaf(false);
            this->nnodes++;
        }
        pnode = pnode->children[data[i]];
    }
    /* set leaf at last node */
    pnode->set_leaf(true);
}

bool trie_tree::search(std::string data)
{
    trie_node *pnode = this->root;
    int i=0;
    for (; i<data.length(); i++)
    {
        /* if i-th char isn't in the tree
         * return false
         */
        if (pnode->children[data[i]] == nullptr)
        {
            break;
        }
        pnode = pnode->children[data[i]];
    }
    /* check if last node and all char
     * of data is traversed
     */
    if (pnode->get_leaf() && i == data.length())
        return true;
    
    return false;
}/* end trie tree implementation */
