//
//  main.cpp
//  ThirdMax
//
//  Created by ChengnanHu on 10/28/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int thirdMax(vector<int>& nums);

int main(int argc, const char * argv[]) {
    vector<int> v = {1,2,-2147483648};
    int third_max = thirdMax(v);
    cout << third_max << endl;
    return 0;
}

int thirdMax(vector<int>& nums)
{
    long first_max = LONG_MIN;
    long second_max = LONG_MIN;
    long third_max = LONG_MIN;
    for (int i=0; i<nums.size(); i++)
    {
        if (nums[i] == first_max || nums[i] == second_max || nums[i] == third_max)
            continue;
        if (nums[i] > first_max)
        {
            third_max = second_max;
            second_max = first_max;
            first_max = nums[i];
            continue;
        }
        else if (nums[i] > second_max)
        {
            third_max = second_max;
            second_max = nums[i];
            continue;
        }
        else if (nums[i] > third_max)
        {
            third_max = nums[i];
        }
    }
    if (third_max == LONG_MIN)
        return int(first_max);
    return int(third_max);
}
