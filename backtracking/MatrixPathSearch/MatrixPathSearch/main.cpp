//
//  main.cpp
//  MatrixPathSearch
//
//  Created by ChengnanHu on 2/18/21.
//

#include <iostream>
#include <vector>

#define ROW 3
#define COL 4

using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool _exist(vector<vector<char>>& board, string &word, int rpos, int cpos, int wpos);
inline bool outOfBound(vector<vector<char>>& board, int row, int col);
inline bool isVisited(vector<vector<char>>& board, int row, int col);

int main(int argc, const char * argv[])
{
    vector<vector<char>> v = vector<vector<char>>(ROW);
    v[0] = {'A', 'B', 'C', 'E'};
    v[1] = {'S', 'F', 'E', 'S'};
    v[2] = {'A', 'D', 'E', 'E'};
    
    cout << exist(v, "ABCESEEEFS") << endl;
}

bool exist(vector<vector<char>>& board, string word)
{
    for (int i=0; i<board.size(); i++)
    {
        for (int j=0; j<board[0].size(); j++)
        {
            /* initialize visited matrix */
            if (_exist(board, word, i, j, 0)) return true;
        }
    }

    return false;
}

bool _exist(vector<vector<char>>& board, string &word, int rpos, int cpos, int wpos)
{
    if (wpos == word.length())
        return true;
    if (outOfBound(board, rpos, cpos) || isVisited(board, rpos, cpos))
        return false;
    if (board[rpos][cpos] != word[wpos])
        return false;

    bool ans = false;

    board[rpos][cpos] = '\0';
    ans = _exist(board, word, rpos+1, cpos, wpos+1)|\
            _exist(board, word, rpos-1, cpos, wpos+1)|\
            _exist(board, word, rpos, cpos-1, wpos+1)|\
            _exist(board, word, rpos, cpos+1, wpos+1);
    
    board[rpos][cpos] = word[wpos];

    return ans;
}

inline bool outOfBound(vector<vector<char>>& board, int row, int col)
{
    if (row < 0 || row > board.size()-1)
        return true;

    if (col < 0 || col > board[0].size()-1)
        return true;

    return false;
}

inline bool isVisited(vector<vector<char>>& board, int row, int col)
{
    if (board[row][col] == '\0')
        return true;

    return false;
}
