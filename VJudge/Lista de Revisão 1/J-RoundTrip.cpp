#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

void dfs(ll u,
         vector<v64> &g,
         v64 &vis,
         v64 &par,
         ll &st,
         ll &en,
         bool &found)
{
    vis[u] = 1;

    for (ll v : g[u])
    {
        if (v == par[u])
            continue;

        if (vis[v])
        {
            st = v;
            en = u;
            found = true;
            return;
        }

        par[v] = u;

        dfs(v, g, vis, par, st, en, found);

        if (found)
            return;
    }
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    vector<v64> g(n + 1);

    forn(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 vis(n + 1, 0);
    v64 par(n + 1, -1);

    ll start = -1, end = -1;
    bool found = false;

    forn(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i, g, vis, par, start, end, found);

            if (found)
                break;
        }
    }

    if (!found)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    v64 path;

    path.push_back(start);

    for (ll v = end; v != start; v = par[v])
        path.push_back(v);

    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << path.size() << ln;

    for (ll x : path)
        cout << x << ' ';

    return 0;
}