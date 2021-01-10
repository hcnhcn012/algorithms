//
//  main.cpp
//  GridTravellerSimple_bt
//
//  Created by ChengnanHu on 1/10/21.
//

#include <iostream>

using namespace std;

/* grid traveller moves from the top-left
 * to the bottom-right of one grid matrix
 */
int grid_traveller(int rows, int cols);

int main(int argc, const char * argv[]) {
    int ways = grid_traveller(3,3); //6
    std::cout << ways << endl;
    return 0;
}

int grid_traveller(int rows, int cols)
{
    if (rows == 0 || cols == 0)
    {
        return 0;
    }
    
    if (rows == 1 && cols == 1)
    {
        return 1;
    }
    
    int right_ways = grid_traveller(rows, cols - 1);
    int bottom_ways = grid_traveller(rows - 1, cols);
    return right_ways + bottom_ways;
}
