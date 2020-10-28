//
//  main.cpp
//  RemoveDuplicates
//
//  Created by ChengnanHu on 10/22/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums);

int main(int argc, const char * argv[]) {
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int len = removeDuplicates(v);
    cout << "len: " << len << '\n';
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    int i, j, len = 1;
    i = 0;
    j = i + 1;
    for (;j<nums.size();j++)
    {
        if (nums[i] != nums[j])
        {
            nums[++i] = nums[j];
            len++;
        }
    }
    return len;
}
