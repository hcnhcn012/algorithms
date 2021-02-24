//
//  main.cpp
//  merge_sort
//
//  Created by ChengnanHu on 11/17/20.
//

#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &v, int left, int right, vector<int> &v_temp);
void smerge(vector<int> &v, int left, int mid, int right, vector<int> &v_temp);

int main(int argc, const char * argv[])
{
    vector<int> v = {6,5,4,2,1,3,6,6};
    vector<int> temp(v);
    merge_sort(v, 0, int(v.size())-1, temp);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void merge_sort(vector<int> &v, int left, int right, vector<int> &v_temp)
{
    if (left == right)
        return;
    
    int mid = (left + right) / 2;
    vector<int> temp(v);
    merge_sort(v, mid+1, right, temp);
    merge_sort(v, left, mid, temp);
    smerge(v, left, mid, right, temp);
}

void smerge(vector<int> &v, int left, int mid, int right, vector<int> &v_temp)
{
    int p, q, r;
    p = left;
    q = mid + 1;
    r = left;
    while(p <= mid && q <= right)
    {
        if (v[p] > v[q])
            v_temp[r++] = v[q++];
        else
            v_temp[r++] = v[p++];
    }
    while (p <= mid)
    {
        v_temp[r++] = v[p++];
    }
    while (q <= right)
    {
        v_temp[r++] = v[q++];
    }
    for (int i=left; i<=right; i++)
    {
        v[i] = v_temp[i];
    }
}
