//
//  main.cpp
//  coins_change
//
//  Created by ChengnanHu on 1/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define CHANGE 9

using namespace std;

int coins_change(int change, vector<int> &coins);

int main(int argc, const char * argv[])
{
    /* coins vector should be sorted */
    vector<int> coins = {1,3,5};
    int result = coins_change(CHANGE, coins); //3
    cout << "Min coins is: " << result << endl;
    return 0;
}

int coins_change(int change, vector<int> &coins)
{
    /* init results vector */
    int results[CHANGE][CHANGE+1];
    for (int i=0; i<CHANGE; i++)
    {
        for (int j=0; j<=CHANGE; j++)
        {
            results[i][j] = -1;
        }
    }
    /* fill-in results vector using greedy-method */
    for (int k=0; k<coins.size(); k++)
    {
        results[0][coins[k]] = 1;
    }
    
    for (int l=1; l<CHANGE; l++)
    {
        for (int m=1; m<=CHANGE; m++)
        {
            if (results[l-1][m] != -1)
            {
                for (int n=0; n<coins.size(); n++)
                {
                    results[l][m+coins[n]] = 1;
                }
            }
        }
        if(results[l][CHANGE] != -1)
            return l+1;
    }
    return -1;
}
