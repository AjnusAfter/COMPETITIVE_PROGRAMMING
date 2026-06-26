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

    ll LOG = 0;
    while ((1LL << LOG) <= n)
        LOG++;

    vector<v64> up(n + 1, v64(LOG, 0));
    vector<v64> adj(n + 1);
    v64 depth(n + 1, 0);

    forn(i, 2, n + 1)
    {
        ll p;
        cin >> p;
        up[i][0] = p;
        adj[p].push_back(i);
    }

    queue<ll> qu;
    qu.push(1);
    depth[1] = 0;

    while (!qu.empty())
    {
        ll u = qu.front();
        qu.pop();

        forn(j, 1, LOG)
        {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (ll v : adj[u])
        {
            depth[v] = depth[u] + 1;
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
        cout << lca(a, b) << ln;
    }

    return 0;
}