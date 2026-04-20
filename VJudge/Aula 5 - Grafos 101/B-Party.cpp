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

vector<v64> g;
ll min_groups = 0;

void dfs(ll u, ll dist)
{
    min_groups = max(min_groups, dist);

    for (ll v : g[u])
    {
        dfs(v, dist + 1);
    }
}

int main()
{
    _;

    ll n;
    cin >> n;

    g.resize(n);
    v64 top_managers;
    forn(u, 0, n)
    {
        ll manager;
        cin >> manager;

        if (manager == -1)
        {
            top_managers.push_back(u);
        }
        else
        {
            manager--;
            g[manager].push_back(u);
        }
    }

    for (ll u : top_managers)
    {
        dfs(u, 1);
    }

    cout << min_groups << ln;

    return 0;
}