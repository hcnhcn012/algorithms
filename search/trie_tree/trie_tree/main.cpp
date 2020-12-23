//
//  main.cpp
//  trie_tree
//
//  Created by ChengnanHu on 12/22/20.
//

#include <iostream>
#include <vector>
#include <string>

#include "trie_tree.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    vector<string> vs = {"how", "hi", "her", "hello", "so", "see"};
    trie_tree tt = trie_tree();
    for (int i=0; i<vs.size(); i++)
    {
        tt.insert(vs[i]);
    }
    
    cout << tt.search("how") << ' ';
    cout << tt.search("hi") << ' ';
    cout << tt.search("her") << ' ';
    cout << tt.search("hello") << ' ';
    cout << tt.search("so") << ' ';
    cout << tt.search("see") << ' ';
    
    cout << tt.search("abc") << ' ';
    cout << tt.search("here") << ' ';
    cout << tt.search("he") << ' ' << endl;
}
