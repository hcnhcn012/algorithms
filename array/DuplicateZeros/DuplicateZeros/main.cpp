//
//  main.cpp
//  DuplicateZeros
//
//  Created by ChengnanHu on 10/19/20.
//

#include <iostream>
#include <vector>
using namespace std;
void duplicateZeros(vector<int>& a);

int main(int argc, const char * argv[])
{
    vector<int> v;
    v = {1,2,0,0,3,0,1};
    duplicateZeros(v);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void duplicateZeros(vector<int> &a)
{
    int i = 0;
    int sh = 0;
    for (i = 0; sh + i < a.size(); ++i)
        sh += a[i] == 0;
    for (i = i - 1; sh > 0; --i)
    {
        if (i + sh < a.size())
            a[i + sh] = a[i];
        if (a[i] == 0)
            a[i + --sh] = a[i];
    }
}
