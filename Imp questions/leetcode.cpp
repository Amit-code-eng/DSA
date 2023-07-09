#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(string &s, int i, vector<int> &dp)
    {

        if (i == s.size())
            return 0;
        if (s[i] == '0')
            return 1e9 + 7;

        if (dp[i] != -1)
            return dp[i];

        int mn = 1e9 + 7, x = 0;

        for (int j = i; j < s.size(); j++)
        {

            x = (x << 1) | (s[j] - '0');

            int y = int(pow(x, 1.0 / 5));

            if (x == pow(y, 5))
            {
                mn = min(mn, 1 + f(s, j + 1, dp));
            }
        }
    }
    int minimumBeautifulSubstrings(string s)
    {

        vector<int> dp(16, -1);

        return f(s, 0, dp);
    }
};

int main()
{

    return 0;
}