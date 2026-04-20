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

bool dfs(ll u, ll color, vector<v64> &g, v64 &team)
{
    team[u] = color;

    for (ll v : g[u])
    {
        if (!team[v])
        {
            if (!dfs(v, 3 - color, g, team))
                return false;
        }
        else if (team[v] == team[u])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    vector<v64> g(n);
    forn(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;

        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 team(n, 0);

    forn(i, 0, n)
    {
        if (!team[i])
        {
            if (!dfs(i, 1, g, team))
            {
                cout << "IMPOSSIBLE" << ln;
                return 0;
            }
        }
    }

    forn(i, 0, n)
    {
        cout
            << team[i] << ' ';
    }

    cout << ln;

    return 0;
}