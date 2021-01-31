//
//  main.cpp
//  insert_sort
//
//  Created by ChengnanHu on 11/16/20.
//

#include <iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int> &v);

int main(int argc, const char * argv[])
{
    vector<int> v = {4,5,6,1,2,3};
    insert_sort(v);
    
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void insert_sort(vector<int> &v)
{
    for (int i=1; i<v.size(); i++)
    {
        int j = i - 1;
        int insert = v[i];
        for (; j>=0; j--)
        {
            if (v[j] > insert)
                v[j+1] = v[j];
            else
                break;
        }
        v[j+1] = insert;
    }
}
