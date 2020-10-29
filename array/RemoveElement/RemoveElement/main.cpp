//
//  main.cpp
//  RemoveElement
//
//  Created by ChengnanHu on 10/20/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int removeElement(vector<int>& nums, int val);

int main(int argc, const char * argv[])
{
    vector<int> v = {0,1,2,2,3,0,4,2};
    int len = removeElement(v, 2);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << "\nAfter removing, len is " << len << endl;
    return 0;
}

int removeElement(vector<int>& nums, int val)
{
    if (nums.size() == 0)
        return 0;
    int *p1, *p2;
    int len = 0;
    p1 = &nums[0];
    p2 = &nums[nums.size()-1];
    // 交换头部开始的val值和尾部开始的非val值
    while (p1 != p2)
    {
        if (*p1 == val)
        {
            if (*p2 != val)
            {
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
            else
            {
                p2--;
                continue;
            }
        }
        else
            p1++;
    }
    // remove操作后计数
    for (; len<nums.size(); len++)
    {
        if (nums[len] == val)
            break;
    }
    return len;
}
