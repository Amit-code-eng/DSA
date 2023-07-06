#include <bits/stdc++.h>
using namespace std;

class fenwik
{

    // 1 based indexing
public:
    vector<int> bit;
    int n;
    fenwik(int n)
    {

        this->n = n;
        bit.assign(n, 0);
    }

    fenwik(vector<int> &v)
    {

        this->n = v.size();
        bit.resize(n);
        vector<int> pref(n);

        for (int i = 1; i < n; i++)
        {

            pref[i] = v[i] + pref[i - 1];
        }
        for (int i = 1; i < n; i++)
        {

            bit[i] = pref[i] - pref[i - (i & -i)];
        }
    }

    void up(int i, int val)
    {

        while (i < n)
        {

            bit[i] += val;
            i += (i & -i);
        }
    }

    int get(int i)
    {

        int sum = 0;

        while (i > 0)
        {

            sum += bit[i];
            i -= (i & -i);
        }

        return sum;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int qr;
    cin >> qr;
    fenwik fen(v);
    
    while (qr--)
    {

        int l, r;
        char c;
        cin >> c >> l >> r;

        if (c == 'q')
        {

            cout << fen.get(r) - fen.get(l - 1) << endl;
        }
        else
        {

            fen.up(l, r);
        }
    }

    return 0;
}