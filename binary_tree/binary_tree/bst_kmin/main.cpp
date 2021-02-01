//
//  main.cpp
//  bst_kmin
//
//  Created by ChengnanHu on 2/1/21.
//

#include <iostream>
#include <stack>
#include "../binary_search_tree/bst.hpp"

using namespace std;

Node* KthNode(Node* pRoot, int k);

int main(int argc, const char * argv[])
{
    std::vector<int> v = {
        8,
        6,10,
        5,7,9,11,
    };
    Node root = Node(v[0]);
    for (int i=1; i<v.size(); i++)
    {
        Node *n = new Node(v[i]);
        insert(&root, n);
    }
    std::cout << "Current tree: " << std::endl;
    print_t(&root);
    Node *n = KthNode(&root, 1);
    cout << n->val << endl;
    return 0;
}

Node* KthNode(Node* pRoot, int k)
{
    /* inorder traverse using non-recursive solution */
    stack<Node *> s;
    Node *cur_node = pRoot;
    int i = 0;
    while (!s.empty() || cur_node != nullptr)
    {
        while (cur_node != nullptr)
        {
            s.push(cur_node);
            cur_node = cur_node->left;
        }
        
        cur_node = s.top(); s.pop();
        if (++i == k) return cur_node;
        
        cur_node = cur_node->right;
    }
    
    return nullptr;
}
