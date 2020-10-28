//
//  main.cpp
//  CheckIfExist
//
//  Created by ChengnanHu on 10/23/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkIfExist(vector<int>& arr);

int main(int argc, const char * argv[])
{
    vector<int> arr = {1,0,5};
    bool res = checkIfExist(arr);
    cout << res << endl;
    return 0;
}

bool checkIfExist(vector<int>& arr)
{
    if (arr.size() != 0)
    {
        int zero_flag = 0;
        sort(arr.begin(), arr.end());
        vector<float> arr2(arr.size());
        int i=0;
        for (; i<arr2.size(); i++)
        {
            arr2[i] = float(arr[i]) / 2;
        }
        int j=0, k=0;
        for (; j<arr.size() && k<arr2.size();)
        {
            if (arr[j] < arr2[k])
                j++;
            else if (arr[j] > arr2[k])
                k++;
            else if (arr[j] == arr2[k] && arr[j] != 0)
                return true;
            else
            {
                if (arr[j] == arr2[k] && arr[j] == 0)
                    zero_flag++;
                j++;
                k++;
            }
        }
        if (zero_flag > 1)
            return true;
    }
    return false;
}
