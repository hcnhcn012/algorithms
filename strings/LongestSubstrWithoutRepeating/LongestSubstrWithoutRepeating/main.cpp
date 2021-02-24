//
//  main.cpp
//  LongestSubstrWithoutRepeating
//
//  Created by ChengnanHu on 2/24/21.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int lengthOfLongestSubstring(string s);

int main(int argc, const char * argv[])
{
    string s = "pwwkw";
    cout << lengthOfLongestSubstring(s) << endl;
}

int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uset;
        int max_wdsz = 0;

        int i=0, j=0;
        for (; j<s.length(); j++)
        {
            if (uset.find(s[j]) == uset.end())
            {
                uset.insert(s[j]);
            }

            else
            {
                int k = i;
                while(s[k] != s[j])
                {
                    uset.erase(s[k]);
                    k++;
                }
                i = k + 1;
            }

            max_wdsz = max(j-i+1, max_wdsz);
        }

        return max_wdsz;
    }
