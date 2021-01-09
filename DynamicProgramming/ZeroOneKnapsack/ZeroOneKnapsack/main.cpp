//
//  main.cpp
//  ZeroOneKnapsack
//
//  Created by ChengnanHu on 1/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int> &items, vector<bool> &result);

int main(int argc, const char * argv[])
{
    vector<int> stuff = {2,2,4,6,3};
    const int capacity = 9;
    vector<bool> result = vector<bool>(stuff.size(), false);
    int max_weight = knapsack(capacity, stuff, result);
    cout << "Max weight: " << max_weight;
    cout << endl;
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}

int knapsack(int capacity, vector<int> &items, vector<bool> &result)
{
    /* init states matrix */
    /* matrix row: item's weight */
    /* matrix column: current bag contains weight */
    vector<vector<bool>> states = \
                vector<vector<bool>>(items.size(), vector<bool>(capacity+1, false));
    states[0][0] = true;
    states[0][items[0]] = true;
    for (int i=1; i<items.size(); i++)
    {
        /* copy formal states */
        for (int j=0; j<=capacity; j++)
        {
            states[i][j] = states[i-1][j];
        }
        
        /* pack when free space is enough */
        for (int k=0; k<=capacity; k++)
        {
            if (states[i-1][k] == true && k+items[i]<=capacity)
                states[i][k+items[i]] = true;
        }
    }
    
    /* get max value */
    int p = capacity;
    int last_item_idx = int(items.size()) - 1;
    for (; p>=0; p--)
    {
        if (states[last_item_idx][p] == true)
            break;
    }
    
    /* fill-in the results vector */
    int q = p;
    int r = last_item_idx;
    while (r>=0 && q>=0)
    {
        if (q-items[r] >= 0 && states[r-1][q-items[r]] == true)
        {
            result[r] = true;
            q = q - items[r];
        }
        --r;
    }
    
    return p;
}
