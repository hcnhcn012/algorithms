//
//  main.cpp
//  selection_sort
//
//  Created by ChengnanHu on 11/16/20.
//

#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &v);

int main(int argc, const char * argv[])
{
    vector<int> v = {6,5,3,4,2,1};
    selection_sort(v);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void selection_sort(vector<int> &v)
{
    int i = 0;
    for (; i<v.size(); i++)
    {
        int min = v[i];
        int min_index = i;
        for (int j=i+1; j<v.size(); j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                min_index = j;
            }
        }
        int temp = v[i];
        v[i] = v[min_index];
        v[min_index] = temp;
    }
}
