#include <bits/stdc++.h>
using namespace std;

class dsu_
{

public:
    int n;
    vector<int> p, r;

    dsu_(int n)
    {

        this->n = n;

        p.resize(n + 1);
        r.resize(n + 1);

        for (int i = 0; i < n; i++)
        {

            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int x)
    {

        return p[x] == x ? x : x = find(p[x]);
    }

    bool union_(int a, int b)
    {

        a = find(a);
        b = find(b);
        if (a == b)
            return 0;

        if (r[a] > r[b])
        {
            p[b] = a;
        }
        else if (r[b] > r[a])
        {

            p[a] = b;
        }
        else
        {

            p[a] = b;
            r[b]++;
        }

        return 1;
    }
};

int main()
{

    return 0;
}