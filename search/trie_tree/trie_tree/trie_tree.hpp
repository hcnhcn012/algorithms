//
//  trie_tree.hpp
//  trie_tree
//
//  Created by ChengnanHu on 12/22/20.
//

#ifndef trie_tree_hpp
#define trie_tree_hpp

#define MAX_HASHTABLE_SZ 256

#include <iostream>
#include <string>

class trie_node
{
private:
    char data;
    bool is_leaf;
public:
    trie_node *children[MAX_HASHTABLE_SZ];
    trie_node(char _data);
    char get_data();
    bool get_leaf();
    void set_leaf(bool flag);
};

class trie_tree
{
private:
    int nnodes;
    trie_node *root;
public:
    trie_tree();
    ~trie_tree();
    const trie_node *getroot() const;
    int size();
    void insert(std::string data);
    bool search(std::string data);
};

#endif /* trie_tree_hpp */
