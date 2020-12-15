//
//  main.cpp
//  binary_search
//
//  Created by ChengnanHu on 11/21/20.
//

#include <iostream>
#include <vector>

using namespace std;

void BSearch(vector<int> &v, int num, int left, int right);

int main(int argc, const char * argv[])
{
    vector<int> v = {1,2,2,3,5,7};
    BSearch(v, -9, 0, 5);
    return 0;
}

void BSearch(vector<int> &v, int num, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (num < v[mid])
            return BSearch(v, num, left, mid - 1);
        else if (num > v[mid])
            return BSearch(v, num, mid + 1, right);
        else
            cout << "Find " << num << " at index " << mid << endl;
        
        return;
    }
    cout << "Not found" << endl;
}
