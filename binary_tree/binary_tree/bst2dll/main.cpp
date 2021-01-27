//
//  main.cpp
//  bst2dll
//
//  Created by ChengnanHu on 1/18/21.
//

#include <iostream>
#include "../binary_search_tree/bst.hpp"

Node* Convert(Node* pRootOfTree);
void _convert(Node *pRootOfTree, Node *pfather);
Node *find_left_tail(Node *pRoot);
Node *find_right_head(Node *pRoot);

int main(int argc, const char * argv[])
{
    std::vector<int> v = {
            10,
            6,14,
            4,8,12,16
    };
    Node root = Node(v[0]);
    for (int i=1; i<v.size(); i++)
    {
        Node *n = new Node(v[i]);
        insert(&root, n);
    }
    Convert(&root);
}
