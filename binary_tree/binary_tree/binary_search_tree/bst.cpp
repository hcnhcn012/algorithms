//
//  bst.cpp
//  binary_search_tree
//
//  Created by ChengnanHu on 11/23/20.
//

#include "./bst.hpp"

//int main(int argc, const char * argv[])
//{
//    std::vector<int> v = {
//        33,
//        16,50,
//        13,18,34,58,
//        12,14,17,25,51,66,
//        15,19,27,55
//    };
//    Node root = Node(v[0]);
//    for (int i=1; i<v.size(); i++)
//    {
//        Node *n = new Node(v[i]);
//        insert(&root, n);
//    }
//    std::cout << "Current tree: " << std::endl;
//    print_t(&root);
//    std::cout << "Now delete Node 55" << std::endl;
//    //remove(&root, 13);
//    Node * new_root = remove(&root, 14);
//    //remove(&root, 55);
//    print_t(new_root);
//}

Node * search(Node *root, int val)
{
    Node *n = root;
    Node *next = nullptr;

    for (; n!=nullptr; n=next)
    {
        if (n->val == val)
            return n;
        
        else if (n->val > val)
            next = n->left;
        
        else
            next = n->right;
    }
    
    std::cout << "Not Found" << std::endl;
    return nullptr;
}

Node * find_previous(Node *root, int val)
{
    Node *n = root;
    Node *previous = nullptr;
    
    while (n != nullptr)
    {
        if (val == n->val)
            break;
        
        previous = n;
        
        if (val < n->val)
            n = n->left;
        else if (val > n->val)
            n = n->right;
    }
    return previous;
}

Node * insert(Node *root, Node *new_node)
{
    Node *n = root;
    int depth = -1;
    
    while (n!=nullptr)
    {
        if (new_node->val < n->val && n->left != nullptr)
            n = n->left;
        else if (new_node->val < n->val && n->left == nullptr)
        {
            n->left = new_node;
            ++depth;
            break;
        }
        else if (new_node->val > n->val && n->right != nullptr)
            n = n->right;
        else if (new_node->val > n->val && n->right == nullptr)
        {
            n->right = new_node;
            ++depth;
            break;
        }
        
        else if (new_node->val == n->val)
            break;
    }
    
    if (depth == -1)
    {
        root = new_node;
    }
    return root;
}

Node * remove(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    
    /* determine what kind of node */
    Node *rmn = search(root, val);
    if (rmn == nullptr)
        return nullptr;
    
    Node *rmn_previous = find_previous(root, val);
    
    switch (int(rmn->left==nullptr)+int(rmn->right == nullptr))
    {
        case 2:
            if (rmn_previous != nullptr)
            {
                if (rmn == rmn_previous->left)
                    rmn_previous->left = nullptr;
                else
                    rmn_previous->right = nullptr;
                break;
            }
            else
                rmn = nullptr;
            
        case 1:
            if (rmn_previous != nullptr)
            {
                if (rmn == rmn_previous->left)
                {
                    rmn->left != nullptr ? rmn_previous->left = rmn->left : rmn_previous->left = rmn->right;
                }
                else if (rmn == rmn_previous->right)
                {
                    rmn->left != nullptr ? rmn_previous->right = rmn->left : rmn_previous->right = rmn->right;
                }
                break;
            }
            else
            {
                rmn->left != nullptr ? root = rmn->left : root = rmn->right;
            }
            
        case 0:
            /* find smallist node on the right tree */
            Node *np = rmn->right;
            for (; np->left!=nullptr; np=np->left);
            
            /* first slash */
            Node *np_previous = find_previous(root, np->val);
            // be careful that previous node of replace node cant be the
            // node to remove
            if (np_previous != rmn && np_previous != nullptr)
                np_previous->left = np->right;
            
            /* second redirect */
            np->left = rmn->left;
            if (np_previous != rmn)
                np->right = rmn->right;
            
            /* finally juncture */
            if (rmn_previous == nullptr)
                root = np;
            else
                rmn == rmn_previous->left ? rmn_previous->left = np : rmn_previous->right = np;
            break;
    }
    return root;
}
