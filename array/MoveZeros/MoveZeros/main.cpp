//
//  main.cpp
//  MoveZeros
//
//  Created by ChengnanHu on 10/28/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums);

int main(int argc, const char * argv[])
{
    vector<int> v = {1, 0, 1, 0, 2, 3};
    moveZeroes(v);
    for (int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}

void moveZeroes(vector<int>& nums)
{
    if (nums.size() == 0)
        return;
    int iw;
    // find first zero number, or move the end of the vector
    for (iw=0; iw<nums.size(); iw++)
    {
        if (nums[iw] == 0)
            break;
    }
    if (iw != nums.size())
    {
        int ir;
        ir = iw + 1;
        for (; ir<nums.size(); ir++)
        {
            // if num is 0, swap numbers indexed by iw and ir
            if (nums[ir] != 0)
            {
                int temp = nums[iw];
                nums[iw] = nums[ir];
                nums[ir] = temp;
                iw++;
            }
        }
    }
}
