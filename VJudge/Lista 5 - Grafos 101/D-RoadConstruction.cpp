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
v64 vis;

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

void dfs(ll u)
{
    vis[u] = 1;
    for (ll v : g[u])
    {
        if (!vis[v])
        {
            dfs(u);
        }
    }
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    dsu uf(n);

    ll comps = n;
    ll mx = 1;

    forn(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;

        a--, b--; // 0-based

        if (uf.uni(a, b))
        {
            comps--;
            mx = max(mx, uf.len[uf.find(a)]);
        }

        cout << comps << ' ' << mx << ln;
    }

        return 0;
}