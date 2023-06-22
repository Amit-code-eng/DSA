#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string &pat, string &mat)
{

    string s = pat + '$' + mat;
    vector<int> lps(s.size());

    int i = 1, len = 0;

    while (i < s.size())
    {

        if (s[i] == s[len])
        {

            len++;
            lps[i] = len;
            i++;
        }

        else
        {

            if (len > 0)
                len = lps[len - 1];
            else
                i++;
        }
    }

    return lps;
}

int main()
{

    return 0;
}