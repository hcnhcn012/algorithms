//
//  main.cpp
//  bt_serialize
//
//  Created by ChengnanHu on 1/31/21.
//

#include <iostream>
#include <string>
#include <queue>
#include "../binary_tree/bth.hpp"

using namespace std;

string Serialize(Node *root);
Node* Deserialize(string &s);

int main(int argc, const char * argv[])
{
    /* build a tree */
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
    
    cout << "Tree: " << endl;
    print_t(&n1);
    
    string result = Serialize(&n1);
    cout << "Serialize result: " << endl;
    cout << result << endl;
    
    Node *root = Deserialize(result);
    cout << "Deserialize result: " << endl;
    print_t(root);
    
    return 0;
}

string Serialize(Node *root)
{
    queue<Node *> q;
    string result = "";
    
    q.push(root);
    
    while (!q.empty())
    {
        Node *cur_node = q.front(); q.pop();
        if (cur_node != nullptr)
        {
            result += to_string(cur_node->val);
            result.push_back(',');
            q.push(cur_node->left);
            q.push(cur_node->right);
        }
        else
            result += "#,";
    }
    
    /* pop the last comma */
    result.pop_back();
    
    return result;
    
}

Node* Deserialize(string &s)
{
    if (s[0] == '#')
        return nullptr;
    
    queue<Node *> q;
    int comma_pos = int(s.find(','));
    int root_val = atoi(s.substr(0, comma_pos).c_str());
    Node *root = new Node(root_val);
    
    q.push(root);
    s = s.substr(comma_pos+1);
    
    while (!q.empty() && !s.empty())
    {
        auto node = q.front(); q.pop();
        if (s[0] == '#')
        {
            node->left = nullptr;
            s = s.substr(2);
        }
        else
        {
            comma_pos = int(s.find(','));
            int val = atoi(s.substr(0, comma_pos).c_str());
            Node *node_left = new Node(val);
            node->left = node_left;
            s = s.substr(comma_pos+1);
            q.push(node_left);
        }
        if (s[0] == '#')
        {
            node->right = nullptr;
            if (s.length() >= 2) s = s.substr(2);
        }
        else
        {
            comma_pos = int(s.find(','));
            int val = atoi(s.substr(0, comma_pos).c_str());
            Node *node_right = new Node(val);
            node->right = node_right;
            s = s.substr(comma_pos+1);
            q.push(node_right);
        }
    }
    return root;
}
