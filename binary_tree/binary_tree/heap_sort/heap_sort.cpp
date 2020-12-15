//
//  main.cpp
//  heap_sort
//
//  Created by ChengnanHu on 12/5/20.
//

#include <iostream>
#include <vector>
#include "../binary_tree/bth.hpp"

#define MAXHEAP byte(1)

using namespace std;

void heap_sort(vector<int> &v);

int main(int argc, const char * argv[])
{
    vector<int> v = {3,9,6,1,5};
    heap_sort(v);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void heap_sort(vector<int> &v)
{
    heap hp = heap(MAXHEAP);
    
    for (int i=0; i<v.size(); i++)
        heap_insert(&hp, v[i]);
    
    for (int j=int(v.size()-1); j>=0; j--)
        v[j] = heap_pop_root(&hp);
}
