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

const ll INF = (ll)1e18;

v64 dijkstra(ll n, vector<vector<p64>> &g, ll src)
{
    v64 dist(n, INF);
    priority_queue<p64, vector<p64>, greater<p64>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : g[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    vector<vector<p64>> g(n);
    forn(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        a--, b--;

        g[a].push_back({b, c});
        // g[b].push_back(a);
    }

    v64 dist = dijkstra(n, g, 0);

    forn(i, 0, n)
    {
        cout << dist[i] << " ";
    }

    cout << ln;

    return 0;
}