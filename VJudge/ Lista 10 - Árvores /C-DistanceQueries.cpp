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

int main()
{
    _;
        
    ll n, q;
    cin >> n >> q;

    vector<v64> adj(n + 1);

    forn(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll LOG = 0;
    
    while ((1LL << LOG) <= n)
        LOG++;

    vector<v64> up(n + 1, v64(LOG, 0));
    v64 depth(n + 1, 0);

    queue<ll> qu;
    qu.push(1);
    up[1][0] = 0;
    depth[1] = 0;

    v64 parent(n + 1, -1);
    parent[1] = 0;

    while (!qu.empty())
    {
        ll u = qu.front();
        qu.pop();

        for (ll v : adj[u])
        {
            if (v == parent[u])
                continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            up[v][0] = u;

            forn(j, 1, LOG)
            {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }

            qu.push(v);
        }
    }

    auto lca = [&](ll a, ll b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        ll diff = depth[a] - depth[b];
        forn(j, 0, LOG)
        {
            if (diff & (1LL << j))
                a = up[a][j];
        }

        if (a == b)
            return a;

        for (ll j = LOG - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    };

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        ll c = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[c] << ln;
    }

    return 0;
}