//
//  main.cpp
//  GridShortestPath_bt
//
//  Created by ChengnanHu on 1/11/21.
//

#include <iostream>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

using namespace std;

void grid_shortest_path(int m, int n, int path, int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS]);
void grid_shortest_path_memo(int m, int n, int path, \
                            int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS],
                             int (&sp_matrix)[MATRIX_ROWS][MATRIX_COLS]);

int shortest_path = INT_MAX;
int count_ways = 0;

int main(int argc, const char * argv[])
{
    int path_matrix[MATRIX_ROWS][MATRIX_COLS] = {
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
    
    //grid_shortest_path(MATRIX_ROWS, MATRIX_COLS, 0, path_matrix);
    grid_shortest_path_memo(MATRIX_ROWS, MATRIX_COLS, 0, path_matrix, sp_matrix);
    cout << "Searched " << count_ways << " paths." << endl;
    cout << "Shortest path is: " << shortest_path << '.' << endl;
    return 0;
}

/* ordinary solution */
//void grid_shortest_path(int m, int n, int path, int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS])
//{
//    /* nearly moving out of the path matrix */
//    if (m == 0 || n == 0)
//        return;
//
//    /* finally get the destnation */
//    if (m == 1 && n == 1)
//    {
//        count_ways++;
//        int total_path = path + path_matrix[MATRIX_ROWS-1][MATRIX_COLS-1];
//        if (total_path < shortest_path)
//            shortest_path = total_path;
//        return;
//    }
//    /* move botton */
//    grid_shortest_path(m-1, n, path+path_matrix[MATRIX_ROWS-m][MATRIX_COLS-n], path_matrix);
//    /* move right */
//    grid_shortest_path(m, n-1, path+path_matrix[MATRIX_ROWS-m][MATRIX_COLS-n], path_matrix);
//}

/* solution with notes(here is sp_matrix) */
void grid_shortest_path_memo(int m, int n, int path, \
                            int (&path_matrix)[MATRIX_ROWS][MATRIX_COLS],
                            int (&sp_matrix)[MATRIX_ROWS][MATRIX_COLS])
{
    /* nearly moving out of the path matrix */
    if (m == 0 || n == 0)
        return;
    
    /* finally get the destnation */
    if (m == 1 && n == 1)
    {
        count_ways++;
        /* add last path */
        int total_path = path + path_matrix[MATRIX_ROWS-1][MATRIX_COLS-1];
        if (total_path < shortest_path)
        {
            shortest_path = total_path;
            sp_matrix[MATRIX_ROWS-m][MATRIX_COLS-n] = shortest_path;
        }
        return;
    }
    
    /* if current path is larger than pervious travellings
     * then stop search
     * else continue searching
     */
    int p = path + path_matrix[MATRIX_ROWS-m][MATRIX_COLS-n];
    if (sp_matrix[MATRIX_ROWS-m][MATRIX_COLS-n] != -1)
    {
        if (p > sp_matrix[MATRIX_ROWS-m][MATRIX_COLS-n])
            return;
        else
            sp_matrix[MATRIX_ROWS-m][MATRIX_COLS-n] = p;
    }
    
    else
        sp_matrix[MATRIX_ROWS-m][MATRIX_COLS-n] = p;
    /* move botton */
    grid_shortest_path_memo(m-1, n, p, path_matrix, sp_matrix);
    /* move right */
    grid_shortest_path_memo(m, n-1, p, path_matrix, sp_matrix);
}
