#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define fornme(i, s, e) for (ll i = (s); i <= (e); i++)
#define ln "\n"

vector<v64> adj;
v64 dp;
vector<bool> vis;

ll dfs(ll v)
{
    if (vis[v])
        return dp[v];

    vis[v] = true;

    for (ll u : adj[v])
    {
        dp[v] = max(dp[v], 1 + dfs(u));
    }

    return dp[v];
}

int main()
{
    _;

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    dp.assign(N + 1, 0);
    vis.assign(N + 1, false);

    forn(i, 0, M)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    ll ans = 0;

    fornme(i, 1, N)
    {
        ans = max(ans, dfs(i));
    }

    cout << ans << ln;

    return 0;
}