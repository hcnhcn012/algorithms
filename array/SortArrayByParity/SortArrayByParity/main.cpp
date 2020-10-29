//
//  main.cpp
//  SortArrayByParity
//
//  Created by ChengnanHu on 10/28/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A);
int even_or_odd(int num);

int main(int argc, const char * argv[]) {
    vector<int> v = {1,0,0,1,3};
    vector<int> vres = sortArrayByParity(v);
    for (int i=0; i<vres.size(); i++)
        cout << vres[i] << ' ';
    cout << endl;
    return 0;
}

vector<int> sortArrayByParity(vector<int>& A)
{
    int iw;
    for (iw=0; iw<A.size(); iw++)
    {
        // if even
        if (even_or_odd(A[iw]) == 1)
            break;
    }
    if (iw != A.size())
    {
        int ir = iw + 1;
        for (; ir<A.size(); ir++)
        {
            if (even_or_odd(A[ir]) == 0)
            {
                swap(A[iw], A[ir]);
                iw++;
            }
        }
    }
    return A;
}

int even_or_odd(int num)
{
    return num % 2;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
