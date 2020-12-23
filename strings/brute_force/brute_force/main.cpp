//
//  main.cpp
//  brute_force
//
//  Created by ChengnanHu on 12/19/20.
//

#include <iostream>
#include <string>

using namespace std;

/* brute force strcmp implementation */
bool bf_substring(string &s1, string &s2);

int main(int argc, const char * argv[])
{
    string s1 = "aaaabcdd";
    string s2 = "abcd";
    std::cout << bf_substring(s1, s2) << std::endl;
    return 0;
}

/* brute force strcmp implementation
 * using sliding-window
 */
bool bf_substring(string &s1, string &s2)
{
    string *sl, *ss;
    if(s1.length() > s2.length())
    {
        sl = &s1;
        ss = &s2;
    }
    else
    {
        sl = &s2;
        ss = &s1;
    }
    int n = int(sl->length());
    int m = int(ss->length());
    int start = 0;
    int end = m - 1;
    bool all_same = false;
    while (end < n)
    {
        string swindow = sl->substr(start, end);
        int i=0;
        for (; i<m; i++)
        {
            if (swindow[i] != (*ss)[i])
                break;
        }
        if (i == m)
        {
            all_same = true;
            break;
        }
        start++;
        end++;
    }
    return all_same;
}
