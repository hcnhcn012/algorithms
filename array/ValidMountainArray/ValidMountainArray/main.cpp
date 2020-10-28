//
//  main.cpp
//  ValidMountainArray
//
//  Created by ChengnanHu on 10/23/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool validMountainArray(vector<int>& A);


int main(int argc, const char * argv[]) {
    vector<int> v = {1,7,9,5,4,1,2};
    bool res = validMountainArray(v);
    std::cout << res << endl;
    return 0;
}

bool validMountainArray(vector<int>& A)
{
    int N = A.size();
    int i = 0;

    // walk up
    while (i+1 < N && A[i] < A[i+1])
        i++;

    // peak can't be first or last
    if (i == 0 || i == N-1)
        return false;

    // walk down
    while (i+1 < N && A[i] > A[i+1])
        i++;

    return i == N-1;
}
