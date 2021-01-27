//
//  main.cpp
//  binary_tree
//
//  Created by ChengnanHu on 11/23/20.
//

#include <iostream>
#include <stack>
#include "bth.hpp"

void in_order(Node *node);
void pre_order(Node *node);
void post_order(Node *node);

void pre_order_iter(Node *node);
void in_order_iter(Node *node);
void post_order_iter(Node *node);

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
    
    std::cout << "Iteration results: " << std::endl;
    in_order_iter(&n1);
    std::cout << std::endl;
    pre_order_iter(&n1);
    std::cout << std::endl;
    post_order_iter(&n1);
    std::cout << std::endl;
    
    std::cout << "Recursion results: " << std::endl;
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

void pre_order_iter(Node *node)
{
    std::stack<Node *> s;
    
    Node *cur_node = node;
    while (cur_node!=nullptr || !s.empty())
    {
        /* add all left node of left subtree into stack */
        while (cur_node!=nullptr)
        {
            std::cout << cur_node->val << ' ';
            s.push(cur_node);
            cur_node = cur_node->left;
        }
        
        cur_node = s.top(); s.pop();
        cur_node = cur_node->right;
    }
}

void in_order_iter(Node *node)
{
    std::stack<Node *> s;
    
    Node *cur_node = node;
    while (cur_node != nullptr || !s.empty())
    {
        while (cur_node!=nullptr)
        {
            s.push(cur_node);
            cur_node = cur_node->left;
        }
        
        cur_node = s.top(); s.pop();
        std::cout << cur_node->val << ' ';
        cur_node = cur_node->right;
    }
    
}

void post_order_iter(Node *node)
{
    std::stack<Node *> s;
    
    Node *cur_node = node;
    /* important first push right, then push cur_node */
    if (cur_node->right!=nullptr)   s.push(cur_node->right);
    if (cur_node!=nullptr)  s.push(cur_node);
    cur_node = cur_node->left;
    
    while (!s.empty())
    {
        while (cur_node != nullptr)
        {
            if (cur_node->right!=nullptr)   s.push(cur_node->right);
            s.push(cur_node);
            cur_node = cur_node->left;
        }
        
        cur_node = s.top(); s.pop();
        /* if cur_node has right and the right node is the top node after
         * the cur_node's pop
         */
        if (cur_node->right && !s.empty() && cur_node->right == s.top())
        {
            /* pop cur_node->right, i.e. s.top() or cur_right */
            Node *cur_right = s.top(); s.pop();
            /* repush the cur_node */
            s.push(cur_node);
            cur_node = cur_right;
        }
        
        else
        {
            std::cout << cur_node->val << ' ';
            /* important, cur_node is travelled, so must set it to null */
            cur_node = nullptr;
        }
    }
}
