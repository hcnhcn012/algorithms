//
//  main.cpp
//  GreateElement
//
//  Created by ChengnanHu on 10/27/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> replaceElements(vector<int>& arr);

int main(int argc, const char * argv[])
{
    vector<int> v = {17,18,5,4,6,1};
    vector<int> va = replaceElements(v);
    for (int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}

vector<int> replaceElements(vector<int>& arr)
{
    int i, j;
    for (i=0; i<arr.size(); i++)
    {
        if (i == arr.size()-1)
        {
            arr[i] = -1;
            break;
        }
        int max = 0;
        for (j=i+1; j<arr.size(); j++)
            // find max on the right of i
            arr[j] > max ? max = arr[j] : max = max;
        arr[i] = max;
    }
    return arr;
}
