//
//  main.cpp
//  inversion_count
//
//  Created by ChengnanHu on 1/2/21.
//

#include <iostream>
#include <vector>

using namespace std;

int inversion_count(vector<int> &v, int left, int right);
int merge_count(vector<int> &v, int left, int mid, int right);

int main(int argc, const char * argv[])
{
    vector<int> v = {3,1,2};
    int ic = inversion_count(v, 0, int(v.size()-1));
    cout << "Inversion count: "<< ic << endl;
    cout << "Sorted array: ";
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    
}

int inversion_count(vector<int> &v, int left, int right)
{
    /* recursion exit */
    if (left == right)
    {
        return 0;
    }
    int count_left = 0, count_right = 0;
    int mid = (left + right) / 2;
    count_left = inversion_count(v, left, mid);
    count_right = inversion_count(v, mid+1, right);
    int count_merge = merge_count(v, left, mid, right);
    return count_left + count_right + count_merge;
}

int merge_count(vector<int> &v, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int inverstion_count = 0;
    vector<int> tempv = vector<int> (v);
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
        {
            tempv[k] = v[i];
            i++;
        }
        else
        {
            /* trick to get counts which are bigger than v[j]
             * for left and right subvector is order
             * if v[i] > v[j], and the number after v[i] is still
             * bigger than v[j], the counts is mid - i + 1(include v[i])
             */
            inverstion_count += mid - i + 1;
            tempv[k] = v[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid)
        tempv[k++] = v[i++];
    while (j <= right)
        tempv[k++] = v[j++];
    
    for (int idx=left; idx<=right; idx++)
        v[idx] = tempv[idx];
    
    
    return inverstion_count;
}
