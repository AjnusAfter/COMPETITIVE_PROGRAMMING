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

p64 bfs(ll src, vector<v64> &adj, ll n)
{
    v64 dist(n + 1, -1);
    queue<ll> q;

    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    ll node = src, mx = 0;
    forn(i, 1, n + 1)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
            node = i;
        }
    }

    return {node, mx};
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

    p64 first = bfs(1, adj, n);
    p64 second = bfs(first.first, adj, n);

    cout << second.second << ln;

    return 0;
}