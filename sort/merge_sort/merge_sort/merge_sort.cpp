//
//  main.cpp
//  merge_sort
//
//  Created by ChengnanHu on 11/17/20.
//

#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &v, int left, int right);
void smerge(vector<int> &v, vector<int> &v_temp, int left, int i, int right);

int main(int argc, const char * argv[])
{
    vector<int> v = {6,5,4,2,1,3};
    merge_sort(v, 0, 5);
    for (int i=0; i<v.size()-1; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void merge_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    
    int i = (left + right) / 2;
    merge_sort(v, i+1, right);
    merge_sort(v, left, i);
    vector<int> temp(v);
    smerge(v, temp, left, i, right);
    
    for (int j=0; j<v.size(); j++)
    {
        v[j] = temp[j];
    }
}

void smerge(vector<int> &v, vector<int> &v_temp, int left, int i, int right)
{
    int p, q, r;
    p = left;
    q = i + 1;
    r = 0;
    for (; r<v.size(); r++)
    {
        if (v[p] > v[q])
        {
            v_temp[r] = v[p];
            q++;
            continue;
        }
        else if (v[p] <= v[q])
        {
            v_temp[r] = v[q];
            p++;
            continue;
        }
    }
}
