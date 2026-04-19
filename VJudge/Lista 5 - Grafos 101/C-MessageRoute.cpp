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

// Disjoint Set Union (Union-Find)
//
// Supports find with path compression and union by size to maintain dynamic connectivity of disjoint sets.
//
// complexity: O(alpha(N)) amortized per op, O(N)

struct dsu
{
    v64 id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    bool uni(ll a, ll b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (len[a] < len[b])
            swap(a, b);
        len[a] += len[b], id[b] = a;
        return true;
    }
};

void dfs(ll u, vector<v64> &g, v64 &vis)
{
    vis[u] = 1;
    for (ll v : g[u])
        if (!vis[v])
            dfs(v, g, vis);
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

    v64 parent(n, -1);
    v64 dist(n, -1);

    queue<ll> q;
    q.push(0);                        // 0-based
    dist[0] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (ll v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n - 1] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    v64 path;
    for (ll cur = n - 1; cur != -1; cur = parent[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (ll x : path)
    {
        cout << x + 1 << ' ';         // 0-based
    }

    cout << '\n';

    return 0;
}