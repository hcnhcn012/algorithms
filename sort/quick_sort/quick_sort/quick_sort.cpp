//
//  main.cpp
//  quick_sort
//
//  Created by ChengnanHu on 11/17/20.
//

#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &v, int left, int right);
int partition(vector<int> &v, int left, int right);

int main(int argc, const char * argv[])
{
    vector<int> v = {6,5,4,3,2,1};
    quick_sort(v, 0, int(v.size()-1));
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void quick_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    int p = partition(v, left, right);
    quick_sort(v, left, p-1);
    quick_sort(v, p+1, right);
}


int partition(vector<int> &v, int left, int right)
{
    int i = left;
    int j = right + 1;
    int part_val = v[left];
    while (true)
    {
        while(v[++i] < part_val && i < right);
        while(v[--j] > part_val && j > left);
        if (j <= i)
            break;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    v[left] = v[j];
    v[j] = part_val;
    return j;
}
