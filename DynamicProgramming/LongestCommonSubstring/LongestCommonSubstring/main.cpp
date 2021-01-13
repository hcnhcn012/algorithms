//
//  main.cpp
//  LongestCommonSubstring
//
//  Created by ChengnanHu on 1/13/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  //use function max

using namespace std;

int longest_common_substring(string &s1, string &s2, string &subseq);

int main(int argc, const char * argv[])
{
    string s1 = "mitcmu";
    string s2 = "mtacnu";
    string lcs = "";
    int lcs_len = longest_common_substring(s1, s2, lcs);
    cout << "The loggest substring is: " << lcs << endl;
    cout << "Length: " << lcs_len << endl;
    return 0;
}

int longest_common_substring(string &s1, string &s2, string &subseq)
{
    /* initializing lcs matrix */
    vector<vector<int>> lcs_matrix = \
            vector<vector<int>>(s1.length(), vector<int>(s2.length(), -1));
    
    /* fill-in first row */
    bool flag_row = false;
    for (int j=0; j<s2.length(); j++)
    {
        if (s1[0] == s2[j])
        {
            /* push to subseq at first time */
            if (!flag_row)
                subseq.push_back(s1[0]);
            flag_row = true;
        }
        lcs_matrix[0][j] = int(flag_row);
    }
    
    /* fill-in first col*/
    bool flag_col = false;
    for (int i=0; i<s1.length(); i++)
    {
        if (s1[i] == s2[0])
        {
            /* push to subseq at first time */
            if (!flag_row)
                subseq.push_back(s2[0]);
            
            flag_col = true;
        }
        lcs_matrix[i][0] = int(flag_col);
    }
    
    /* fill-in the rest */
    for (int k=1; k<s1.size(); k++)
    {
        for (int l=1; l<s2.size(); l++)
        {
            if (s1[k] == s2[l])
            {
                subseq.push_back(s1[k]);
                lcs_matrix[k][l] = lcs_matrix[k-1][l-1] + 1;
            }
            else
            {
                lcs_matrix[k][l] = max(lcs_matrix[k-1][l], lcs_matrix[k][l-1]);
            }
        }
    }
    
    /* return the value of last cell */
    return lcs_matrix[s1.size()-1][s2.size()-1];
}
