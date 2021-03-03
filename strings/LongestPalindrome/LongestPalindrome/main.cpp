//
//  main.cpp
//  LongestPalindrome
//
//  Created by ChengnanHu on 2/24/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s);

int main(int argc, const char * argv[])
{
    string s = "babad";
    string res = longestPalindrome(s);
    cout << res << endl;
    
}

string longestPalindrome(string s)
{
    string res = "";
    if (s.length() == 0)
        return res;

    string rs(s);
    reverse(rs.begin(), rs.end());

    int max_len = 0;
    int max_i = 0;
    int max_j = 0;

    vector<vector<int >> matrix = vector<vector<int >> (rs.length()+1);
    for (int i=0; i<matrix.size(); i++)
    {
        matrix[i] = vector<int> (s.length()+1, 0);
    }

    for (int i=1; i<matrix.size(); i++)
    {
        for (int j=1; j<matrix[0].size(); j++)
        {
            if (rs[i-1] == s[j-1])
                matrix[i][j] = matrix[i-1][j-1]+1;
            else
                matrix[i][j] = 0;

            if (matrix[i][j] > max_len)
            {
                max_len = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    while(max_len >= 1)
    {
        res.push_back(rs[max_i-1]);
        max_i--;
        max_len--;
    }

    return res;
}
