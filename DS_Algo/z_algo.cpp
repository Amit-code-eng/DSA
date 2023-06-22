#include <bits/stdc++.h>
using namespace std;

vector<int> z_algo(string &pat, string &mat)
{

    string s = pat + '$' + mat + '#';

    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {

        z[i] = max(0, min(r - i + 1, z[i - l])); // if(i<=r){z[i]=min(r-i+1,z[i-l])}
        while (s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i - 1 + z[i] > r)
        {

            l = i;
            r = i - 1 + z[i];
        }
    }

    return z;
}

int main()
{

    return 0;
}