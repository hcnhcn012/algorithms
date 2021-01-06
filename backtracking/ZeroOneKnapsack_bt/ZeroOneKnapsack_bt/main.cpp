//
//  main.cpp
//  ZeroOneKnapsack_bt
// zero-one knapsack problem backtracking solution
//
//  Created by ChengnanHu on 1/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

void knapsack(const int capacity, vector<int> &stuff, \
              vector<int> &result, int n, int current_weight);

int max_weight = INT_MIN;

int main(int argc, const char * argv[])
{
    vector<int> stuff = {2,2,4,6,3};
    vector<int> result = vector<int>(stuff.size(), 0);
    const int capacity = 9;
    knapsack(capacity, stuff, result, 0, 0);
    cout << "Max weight: " << max_weight;
    cout << endl;
}

void knapsack(const int capacity, vector<int> &stuff, \
              vector<int> &result, int n, int current_weight)
{
    /* if bag is full or every stuff has been viewed, exit
     */
    if (current_weight == capacity || n == stuff.size())
    {
        /* check what the bag has at current time
         * update the max_weight
         */
        current_weight > max_weight ? max_weight = current_weight : max_weight = max_weight;
        return; 
    }
    
    /* view the next stuff
     * deciding whether loading or skipping the stuff
     */
    int weight = stuff[n];
    /* loading after checking if the can load this stuff*/
    if (current_weight+weight <= capacity)
    {
        knapsack(capacity, stuff, result, n+1, current_weight+weight);
    }
    
    /* skipping */
    knapsack(capacity, stuff, result, n+1, current_weight);
}
