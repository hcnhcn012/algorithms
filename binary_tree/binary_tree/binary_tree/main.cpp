//
//  main.cpp
//  binary_tree
//
//  Created by ChengnanHu on 11/23/20.
//

#include <iostream>
#include "bth.hpp"

void in_order(Node *node);
void pre_order(Node *node);
void post_order(Node *node);

int main(int argc, const char * argv[])
{
    Node n1 = Node(1);
    Node n2 = Node(2);
    Node n3 = Node(3);
    Node n4 = Node(4);
    Node n5 = Node(5);
    Node n6 = Node(6);
    
    n1.left = &n2;
    n1.right = &n3;
    
    n2.left = &n4;
    n2.right = &n5;
    
    n3.left = &n6;
    
    in_order(&n1);
    std::cout << std::endl;
    pre_order(&n1);
    std::cout << std::endl;
    post_order(&n1);
    std::cout << std::endl;
    
    return 0;
}

void in_order(Node *node)
{
    if (node == nullptr)
        return;
    
    in_order(node->left);
    std::cout << node->val << ' ';
    in_order(node->right);
}

void pre_order(Node *node)
{
    if (node == nullptr)
        return;
    
    std::cout << node->val << ' ';
    pre_order(node->left);
    pre_order(node->right);
}

void post_order(Node *node)
{
    if (node == nullptr)
        return;
    
    post_order(node->left);
    post_order(node->right);
    std::cout << node->val << ' ';
}
