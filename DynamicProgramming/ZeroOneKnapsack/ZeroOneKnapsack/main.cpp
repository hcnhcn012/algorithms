//
//  main.cpp
//  ZeroOneKnapsack
//
//  Created by ChengnanHu on 1/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int> &items);

int main(int argc, const char * argv[])
{
    vector<int> stuff = {2,2,4,6,3};
    const int capacity = 9;
    int max_weight = knapsack(capacity, stuff);
    cout << "Max weight: " << max_weight;
    cout << endl;
    return 0;
}

int knapsack(int capacity, vector<int> &items)
{
    /* init states matrix */
    /* matrix row: item's weight */
    /* matrix column: current bag contains weight */
    vector<vector<bool>> states = \
                vector<vector<bool>>(items.size(), vector<bool>(capacity+1, false));
    states[0][0] = 1;
    states[0][1] = 1;
    for (int i=1; i<items.size(); i++)
    {
        /* copy formal states */
        for (int j=0; j<=capacity; j++)
        {
            states[i][j] = states[i-1][j];
        }
        
        /* pack when free space is enough */
        for (int j=0; j<=capacity; j++)
        {
            if (states[i][j] == true && j+items[i] <= capacity)
                states[i][j+items[i]] = true;
        }
    }
    
    /* get max value */
    int j = capacity;
    int last_item_idx = int(items.size()) - 1;
    for (; j>=0; j--)
    {
        if (states[last_item_idx][j] == 1)
            break;
    }
    return j;
}
