//
//  main.cpp
//  FindDisappearedNumbers
//
//  Created by ChengnanHu on 10/28/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums);

int main(int argc, const char * argv[]) {
    vector<int> v = {4,3,2,7,8,2,3,1};
    vector<int> v1 = findDisappearedNumbers(v);
    for (int i=0; i<v1.size(); i++)
    {
        cout << v1[i] << ' ';
    }
    cout << endl;
    return 0;
}

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> res = {};
    /* Do some marks */
    for (int num : nums)
    {
        int normal_pos = abs(num) - 1;
        nums[normal_pos] > 0? nums[normal_pos] = -nums[normal_pos] : nums[normal_pos] = nums[normal_pos];
    }
    for (int i=0; i<nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            res.push_back(i+1);
        }
    }
    return res;
}
