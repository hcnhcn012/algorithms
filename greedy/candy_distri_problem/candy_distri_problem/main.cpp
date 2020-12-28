//
//  main.cpp
//  candy_distri_problem
//
//  Created by ChengnanHu on 12/24/20.
//

#include <iostream>
#include <vector>

using namespace std;

/* greedy algorithm using slow-fast pointer method */
vector<int> candy_distri(vector<int> &candy_size, vector<int> &child_needs);

int main(int argc, const char * argv[])
{
    vector<int> child_needs = {1,1,2,2,2,3,4,6};
    //vector<int> child_needs = {1,3,3,6,6,6,6};
    vector<int> candy_size = {1,2,3,4,5,6};
    vector<int> candys = candy_distri(candy_size, child_needs);
    for (int i=0; i<candys.size(); i++)
    {
        cout << candys[i] << ' ';
    }
    cout << endl;
    return 0;
}

vector<int> candy_distri(vector<int> &candy_size, vector<int> &child_needs)
{
    int p = 0, q = 0;
    vector<int> candys = vector<int>(candy_size.size(), 0);
    int i = 0;
    while (p < child_needs.size() && q < candys.size())
    {
        if (candy_size[q] < child_needs[p])
        {
            for (; i<candy_size.size()&&candy_size[q]<child_needs[p]; q++);
        }
        candys[i] = candy_size[q];
        p++;
        q++;
        i++;
    }
    return candys;
}
