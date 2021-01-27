//
//  bst.hpp
//  binary_tree
//
//  Created by ChengnanHu on 1/18/21.
//

#ifndef bst_h
#define bst_h

#include <iostream>
#include <vector>
#include "../binary_tree/bth.hpp"

Node * search(Node *root, int val);
Node * find_previous(Node *root, int val);
Node * insert(Node *root, Node *new_node);
Node * remove(Node *root, int val);

#endif /* bst_h */
