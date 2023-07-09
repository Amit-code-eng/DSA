#include <bits/stdc++.h>
using namespace std;

class HLD
{

public:
    vector<vector<int>> g;
    vector<int> val, lt, hv, sz, head, dep, p, pos, bit;
    int n, idx = 1;
    HLD(vector<int> &val, vector<int> &p)
    {

        g.resize(p.size());

        for (int i = 2; i < p.size(); i++)
        {

            g[p[i]].push_back(i);
        }

        this->n = p.size();
        this->val = val;
        this->p = p;

        lt.assign(n, 0);
        sz.assign(n, 0);
        dep.assign(n, 0);
        hv.assign(n, 0);
        head.assign(n, 0);
        pos.assign(n, 0);

        dfs(1);

        dfsHLD(1, 1);

        bit.assign(n, 0);
        for (int i = 1; i < n; i++)
        {

            upd(pos[i], val[i]);
        }
    }

    void dfs(int nd)
    {

        for (int &c : g[nd])
        {

            dep[c] = dep[nd] + 1;
            dfs(c);

            if (sz[c] > sz[hv[nd]])
            {
                hv[nd] = c;
            }
            sz[nd] += sz[c];
        }

        sz[nd]++;
    }

    void dfsHLD(int nd, int chn)
    {
        head[nd] = chn;
        lt[idx] = nd;
        pos[nd] = idx++;

        if (hv[nd] != 0)
        {

            dfsHLD(hv[nd], chn);
        }

        for (int &c : g[nd])
        {

            if (c != hv[nd])
            {

                dfsHLD(c, c);
            }
        }
    }

    void up(int i, int v)
    {

        int delta = v - val[i];

        int x = pos[i];

        val[i] = v;

        upd(x, delta);
    }

    int qry(int a, int b)
    {

        int s = 0;
        while (head[a] != head[b])
        {

            if (dep[head[a]] < dep[head[b]])
                swap(a, b);

            s += sum(pos[a]) - sum(pos[head[a]] - 1);
            a = p[head[a]];
        }

        if (dep[a] < dep[b])
            swap(a, b);

        s += sum(pos[a]) - sum(pos[b] - 1);

        return s;
    }

    void upd(int x, int v)
    {

        while (x < n)
        {

            bit[x] += v;
            x += (x & -x);
        }
    }
    int sum(int x)
    {

        int s = 0;

        while (x > 0)
        {

            s += bit[x];
            x -= (x & -x);
        }

        return s;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> val(n + 1);
    for (int i = 1; i < n + 1; i++)
        cin >> val[i];

    vector<int> p(n + 1);

    for (int i = 2; i < n + 1; i++)
    {
        cin >> p[i];
    }

    HLD res(val, p);
    int q;
    cin >> q;

    while (q--)
    {

        int x, a, b;
        cin >> x >> a >> b;

        if (x == 1)
        {

            res.up(a, b);
        }
        else
        {

            cout << res.qry(a, b) << endl;
        }
    }

    return 0;
}
