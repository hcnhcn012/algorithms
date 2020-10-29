//
//  main.cpp
//  HeightChecker
//
//  Created by ChengnanHu on 10/28/20.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int heightChecker(vector<int>& heights);

int main(int argc, const char * argv[])
{
    vector<int> v = {1,2,3,4,5};
    int nmoves = heightChecker(v);
    cout << nmoves << endl;
    return 0;
}

int heightChecker(vector<int>& heights)
{
    int nmoves = 0;
    vector<int> nonsorted_heights(heights);
    sort(heights.begin(), heights.end());
    for (int i=0; i<heights.size(); i++)
    {
        if (heights[i] != nonsorted_heights[i])
            nmoves++;
    }
    return nmoves;
}
