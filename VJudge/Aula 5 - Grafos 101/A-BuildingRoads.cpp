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

vector<v64> g;
vector<ll> vis;

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

    ll n, m; // The cities are numbered 1,2,…, n
    cin >> n >> m;

    g.assign(n + 1, v64());
    vis.assign(n + 1, 0);

    forn(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 rep;
    forn(i, 1, n + 1)
    {
        if (!vis[i])
        {
            rep.push_back(i);
            dfs(i, g, vis);
        }
    }

    cout << rep.size() - 1 << ln;

    forn(i, 1, rep.size())
    {
        cout << rep[i - 1] << " " << rep[i] << ln;
    }

    return 0;
}