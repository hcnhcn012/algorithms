//
//  main.cpp
//  LongestCommonSubstring_bt
//
//  Created by ChengnanHu on 1/12/21.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void longest_common_substring(string &s1, string &s2, \
                              int i, int j, int dist, string common_substring);

int max_similarity = INT_MIN;
string longest_substring;

int main(int argc, const char * argv[])
{
    string s1 = "mmmitcmu";
    string s2 = "mtacnu";
    string cs = "";
    longest_common_substring(s1, s2, 0, 0, 0, cs);
    cout << "The loggest substring is: " << longest_substring << endl;
    cout << "Length: " << max_similarity << endl;
    return 0;
}

void longest_common_substring(string &s1, string &s2, \
                              int i, int j, int similarity, string common_substring)
{
    /* searching will be at an end
     * when i or j get the last position
     */
    if (i == s1.length() || j == s2.length())
    {
        /* if get a smaller dist
         * then update the min_dist
         * and then copy the substring
         */
        if (similarity > max_similarity)
        {
            max_similarity = similarity;
            longest_substring = string(common_substring);
        }
        return;
    }
    
    /* if charactor is the same
     * then push it to common substring
     */
    if (s1[i] == s2[j])
    {
        common_substring.push_back(s1[i]);
        longest_common_substring(s1, s2, i+1, j+1, similarity+1, string(common_substring));
    }
    /* or move i/j to next pos
     */
    else
    {
        longest_common_substring(s1, s2, i+1, j, similarity, string(common_substring));
        longest_common_substring(s1, s2, i, j+1, similarity, string(common_substring));
    }
    return;
}
