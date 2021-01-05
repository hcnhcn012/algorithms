//
//  main.cpp
//  eight_queen
//
//  Created by ChengnanHu on 1/3/21.
//

#include <iostream>
#include <vector>

#define NQUEENS 8

using namespace std;
void eight_queen(vector<int> &result, int row);
bool check(vector<int> &result, int row, int column);

int main(int argc, const char * argv[])
{
    /* vector elements all initialized to -1 */
    vector<int> result = vector<int> (NQUEENS, -1);
    /* start at the first row */
    eight_queen(result, 0);
    return 0;
}

void eight_queen(vector<int> &result, int row)
{
    /* recursion exit */
    if (row == result.size())
    {
        /* print solution */
        for (int i=0; i<result.size(); i++)
        {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int column=0; column<result.size(); column++)
    {
        /* validation check
         * if ok, move to next row, or check the
         * next column
         */
        if (check(result, row, column))
        {
            result[row] = column;
            /* recursion start */
            eight_queen(result, row + 1);
        }
    }
}

bool check(vector<int> &result, int row, int column)
{
    bool check_result = true;
    int left_col = column - 1;
    int right_col = column + 1;
    int upper = row - 1;
    
    while (upper >= 0)
    {
        /* if there is a queen at the up side of current pos
         * return false
         */
        if (result[upper] == column)
            check_result = false;
        
        /* if there is a queen at the upper-left side of current pos
         * return false
         */
        if (result[upper] == left_col && left_col >= 0)
            check_result = false;
        
        /* if there is a queen at the upper-right side of current pos
         * return false
         */
        if (result[upper] == right_col && right_col <= result.size()-1)
            check_result = false;
        
        if (check_result == false)
            break;
        
        upper--;
        right_col++;
        left_col--;
    }
    return check_result;
}



