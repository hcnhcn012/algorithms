//
//  main.cpp
//  bubble_sort
//
//  Created by ChengnanHu on 11/14/20.
//

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &v);

int main(int argc, const char * argv[])
{
    vector<int> v = {4,5,6,3,2,1};
    bubble_sort(v);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void bubble_sort(vector<int> &v)
{
    int i = int(v.size()-1);
    for (; i>=0; i--)
    {
        int j = 0;
        for (; j<i; j++)
        {
            if (v[j] > v[j+1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}


