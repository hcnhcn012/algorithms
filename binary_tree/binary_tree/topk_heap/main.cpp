//
//  main.cpp
//  topk_heap
//
//  Created by ChengnanHu on 12/14/20.
//

#include <iostream>
#include <vector>
#include "../binary_tree/bth.hpp"

#define MINHEAP byte(0)

using namespace std;

void topk(vector<int> &v, int k);

int main(int argc, const char * argv[])
{
    vector<int> v = {3,9,6,1,5,11,2,7};
    int k = 3;
    topk(v, k);
    return 0;
}

void topk(vector<int> &v, int k)
{
    if (k > v.size())
    {
        cout << "k must be smaller than the vector size" << endl;
        return;
    }
    heap hp = heap(MINHEAP);
    heap_insert(&hp, v[0]);
    
    for (int i=1; i<v.size(); i++)
    {
        if (v[i] > hp.get_root())
        {
            heap_pop_root(&hp);
            heap_insert(&hp, v[i]);
        }
        
        else
        {
            if (hp.size() < k)
                heap_insert(&hp, v[i]);
        }
    }
    hp.print_heap();
}
