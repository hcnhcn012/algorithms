//
//  main.cpp
//  GridTraveller
//
//  Created by ChengnanHu on 1/10/21.
//

#include <iostream>

#define MAX_ROWS_COLS 256

using namespace std;

long long grid_traveller(int rows, int cols);
long long _grid_traveller(int rows, int cols, long long (&dict)[MAX_ROWS_COLS][MAX_ROWS_COLS]);

int main(int argc, const char * argv[]) {
    long long ways = grid_traveller(3,3); //6
    long long ways_big = grid_traveller(18,18); //2333606220
    cout << ways << endl;
    cout << ways_big << endl;
    return 0;
}

long long grid_traveller(int rows, int cols)
{
    long long dict[MAX_ROWS_COLS][MAX_ROWS_COLS];
    for (int i=0; i<MAX_ROWS_COLS; i++)
    {
        for (int j=0; j<MAX_ROWS_COLS; j++)
        {
            dict[i][j] = -1;
        }
    }
    return _grid_traveller(rows, cols, dict);
}

long long _grid_traveller(int rows, int cols, long long (&dict)[MAX_ROWS_COLS][MAX_ROWS_COLS])
{
    /* if know the answer, just return it
     */
    if (dict[rows][cols] != -1)
        return dict[rows][cols];
    
    if (rows == 0 || cols == 0)
        return 0;
    
    if (rows == 1 && cols == 1)
        return 1;
    
    /* if not, calculate it and
     * save the answer
     */
    dict[rows][cols] = _grid_traveller(rows - 1, cols, dict) + \
                        _grid_traveller(rows, cols - 1 , dict);
    return dict[rows][cols];
}
