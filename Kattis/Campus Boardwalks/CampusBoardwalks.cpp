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

struct DSU
{
    v64 p, sz;

    DSU(ll n)
    {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        forn(i, 1, n + 1) p[i] = i;
    }

    ll find(ll x)
    {
        if (p[x] == x)
        {
            return x;
        }

        return p[x] = find(p[x]);
    }

    bool unite(ll a, ll b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            return false;
        }

        if (sz[a] < sz[b])
        {
            swap(a, b);
        }

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

struct Edge
{
    ll u, v, w;

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

int main()
{
    _;

    ll n, m, k;
    cin >> n >> m >> k;

    DSU dsu(n);

    forn(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        
        dsu.unite(a, b);
    }

    vector<Edge> edges(k);
    forn(i, 0, k)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    ll ans = 0;
    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            ans += e.w;
        }
    }

    ll root = dsu.find(1);
    forn(i, 2, n + 1)
    {
        if (dsu.find(i) != root)
        {
            cout << "more boardwalks needed!" << ln;
            return 0;
        }
    }

    cout << ans << ln;

    return 0;
}