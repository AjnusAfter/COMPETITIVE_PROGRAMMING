#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie()
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll dfs_sub(ll u, vector<v64> &g, v64 &sub)
{
    sub[u] = 0;

    for (ll v : g[u])
    {
        if (!sub[v])
        {
            sub[u] += dfs_sub(v, g, sub) + 1;
        }
    }
    return sub[u];
}

int main()
{
    _;

    ll n;
    cin >> n; // The employees are numbered 1,2,...,n, and
              // employee 1 is the general director of the company

    vector<v64> g;
    v64 sub;

    g.assign(n, v64());
    sub.assign(n, 0);

    forn(i, 1, n)
    {
        ll chefe;
        cin >> chefe;
        chefe--;

        g[chefe].push_back(i);
    }

    dfs_sub(0, g, sub);

    forn(i, 0, n)
    {
        cout << sub[i] << " ";
    }

    cout << ln;

    return 0;
}