//
//  main.cpp
//  coins_change_bt
//
//  Created by ChengnanHu on 1/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_coins = INT_MAX;

void coins_change(int change, vector<int> &coins, int ncoins);

int main(int argc, const char * argv[])
{
    vector<int> coins = {1,3,5};
    coins_change(9, coins, 0); //3
    cout << "Min coins is: " << min_coins << endl;
    return 0;
}

void coins_change(int change, vector<int> &coins, int ncoins)
{
    /* if change is less than 0, stop recursing */
    if (change < 0)
        return;
    
    /* find a solution */
    if (change == 0)
    {
        if (ncoins < min_coins)
        {
            min_coins = ncoins;
        }
        return;
    }
    
    for (int coin : coins)
    {
        coins_change(change-coin, coins, ncoins+1);
    }
    return;
}
