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
    v = {8,4,5,0,0,0,0,7};
    
    duplicateZeros(v);
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}

void duplicateZeros(vector<int> &arr)
{
    int i = 0;
    int sh = 0;
    for (i=0; i<arr.size(); ++i)
        sh += arr[i] == 0;
    
    for (int j=arr.size()-1; j>=0; j--)
    {
        if (arr[j] != 0 && j+sh < arr.size())
            arr[j+sh] = arr[j];

        else if (arr[j] == 0)
        {
            if (j+sh < arr.size())
                arr[j+sh] = arr[j];
            
            if (j+sh-1 < arr.size())
                arr[j+--sh] = arr[j];
            
            else
                sh--;
        }
    }
}
