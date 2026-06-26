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

void dfs1(ll u, ll p, vector<v64> &adj, v64 &sub, v64 &dp)
{
    sub[u] = 1;

    for (ll v : adj[u])
    {
        if (v == p)
            continue;

        dfs1(v, u, adj, sub, dp);
        sub[u] += sub[v];
        dp[u] += dp[v] + sub[v];
    }
}

void dfs2(ll u, ll p, vector<v64> &adj, v64 &sub, v64 &ans, ll n)
{
    for (ll v : adj[u])
    {
        if (v == p)
            continue;

        ans[v] = ans[u] + n - 2 * sub[v];
        dfs2(v, u, adj, sub, ans, n);
    }
}

int main()
{
    _;

    ll n;
    cin >> n;

    vector<v64> adj(n + 1);

    forn(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v64 sub(n + 1, 0), dp(n + 1, 0), ans(n + 1, 0);

    dfs1(1, 0, adj, sub, dp);

    ans[1] = dp[1];
    dfs2(1, 0, adj, sub, ans, n);

    forn(i, 1, n + 1) cout << ans[i] << " ";
    cout << ln;

    return 0;
}