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

// Disjoint Set Union (Union-Find)
// Supports find with path compression and union by size to maintain dynamic connectivity of disjoint sets.
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

int main()
{
    _;

    ll n, m;

    while (cin >> n >> m && (n || m))
    {
        // if (n == 0 && m == 0)
        //     break;

        vector<pair<ll, p64>> edges(m);

        forn(i, 0, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            edges[i] = {w, {u, v}};
        }

        sort(edges.begin(), edges.end());

        dsu d(n);

        ll cost = 0;

        vector<p64> ans;

        for (pair<ll, p64> e : edges)
        {
            ll w = e.first, u = e.second.first, v = e.second.second;

            if (d.uni(u, v))
            {
                cost += w;

                if (u > v)
                    swap(u, v);

                ans.push_back({u, v});
            }
        }

        if (ans.size() != n - 1)
        {
            cout << "Impossible" << ln;
            continue;
        }

        sort(ans.begin(), ans.end());

        cout << cost << ln;

        for (auto [u, v] : ans)
        {
            cout << u << " " << v << ln;
        }
    }

    return 0;
}