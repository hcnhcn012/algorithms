//
//  main.cpp
//  rabin_karp
//
//  Created by ChengnanHu on 12/21/20.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* only supprort lowercase letters [a-z] */
bool issubstr_rk(string &s1, string &s2);
long hash_tk(string &s);

int main(int argc, const char * argv[])
{
    string s1 = "aaaabcdd";
    string s2 = "cdd";
    cout << issubstr_rk(s1, s2) << endl;
}

bool issubstr_rk(string &s1, string &s2)
{
    string *sl, *ss;
    if (s1.length() > s2.length())
    {
        sl = &s1;
        ss = &s2;
    }
    else
    {
        sl = &s2;
        ss = &s1;
    }
    int n = int(sl->length()), m = int(ss->length());
    int start = 0, end = m - 1;
    long ss_hash = hash_tk(*ss);
    while (end < n)
    {
        string s;
        if (start == end)
            s.push_back((*sl)[start]);
        else
            s = sl->substr(start, end+1);
        
        long s_hash = hash_tk(s);
        if (s_hash == ss_hash)
            return true;
        start++;
        end++;
    }
    return false;
}

long hash_tk(string &s)
{
    long hash = 0;
    for (int i=0; i<s.length(); i++)
    {
        hash += (long(s[i])-97) * long(pow(26, s.length()-i-1));
    }
    return hash;
}
