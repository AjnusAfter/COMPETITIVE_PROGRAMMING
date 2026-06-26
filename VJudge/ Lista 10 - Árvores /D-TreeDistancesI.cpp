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

v64 bfs(ll src, vector<v64> &adj, ll n)
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

    return dist;
}

ll farthest_node(v64 &dist, ll n)
{
    ll node = 1;
    forn(i, 1, n + 1)
    {
        if (dist[i] > dist[node])
            node = i;
    }
    return node;
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

    v64 d1 = bfs(1, adj, n);
    ll A = farthest_node(d1, n);

    v64 distA = bfs(A, adj, n);
    ll B = farthest_node(distA, n);

    v64 distB = bfs(B, adj, n);

    forn(i, 1, n + 1)
    {
        cout << max(distA[i], distB[i]) << " ";
    }

    cout << ln;

    return 0;
}