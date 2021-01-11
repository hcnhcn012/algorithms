//
//  main.cpp
//  GridShortestPath
//
//  Created by ChengnanHu on 1/11/21.
//

#include <iostream>
#include <algorithm> // using min() func

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

using namespace std;

int ps(int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS], \
       int (&sp_matrix)[MATRIX_COLS][MATRIX_ROWS]);

int main(int argc, const char * argv[])
{
    int path_matrix[MATRIX_ROWS][MATRIX_COLS] =
    {
        {1,3,5,9},
        {2,1,3,4},
        {5,2,6,7},
        {6,8,4,3}
    };
    
    int sp_matrix[MATRIX_ROWS][MATRIX_COLS] = {
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1}
    };
    
    int shortest_path = ps(path_matrix, sp_matrix);
    cout << "The shortest path is: " << shortest_path << endl;

    return 0;
}

int ps(int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS], \
       int (&sp_matrix)[MATRIX_COLS][MATRIX_ROWS])
{
    sp_matrix[0][0] = path_matrix[0][0];
    
    /* fill-in sp_matrix */
    for (int i=1; i<MATRIX_ROWS; i++)
    {
        sp_matrix[i][0] = sp_matrix[i-1][0] + path_matrix[i][0];
    }
    
    for (int j=1; j<MATRIX_COLS; j++)
    {
        sp_matrix[0][j] = sp_matrix[0][j-1] + path_matrix[0][j];
    }
    
    for (int i=1; i<MATRIX_ROWS; i++)
    {
        for (int j=1; j<MATRIX_COLS; j++)
        {
            sp_matrix[i][j] = min(sp_matrix[i-1][j], sp_matrix[i][j-1]) + path_matrix[i][j];
        }
    }
    return sp_matrix[MATRIX_ROWS-1][MATRIX_COLS-1];
}
