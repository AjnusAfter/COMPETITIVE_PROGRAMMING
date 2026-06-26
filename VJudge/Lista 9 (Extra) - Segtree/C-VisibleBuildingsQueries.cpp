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

v64 merge_pref(const v64 &a, const v64 &b)
{
    v64 res = a;
    ll mx = res.empty() ? 0 : res.back();
    for (ll x : b)
    {
        if (x > mx)
        {
            res.push_back(x);
            mx = x;
        }
    }
    return res;
}

void build(ll node, ll l, ll r, vector<v64> &seg, v64 &h)
{
    if (l == r)
    {
        seg[node] = {h[l]};
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid, seg, h);
    build(node * 2 + 1, mid + 1, r, seg, h);
    seg[node] = merge_pref(seg[node * 2], seg[node * 2 + 1]);
}

void collect(ll node, ll l, ll r, ll ql, ll qr, v64 &nodes)
{
    if (qr < l || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        nodes.push_back(node);
        return;
    }

    ll mid = (l + r) / 2;
    collect(node * 2, l, mid, ql, qr, nodes);
    collect(node * 2 + 1, mid + 1, r, ql, qr, nodes);
}

int main()
{
    _;

    ll n, q;
    cin >> n >> q;

    v64 h(n + 1);
    forn(i, 1, n + 1) cin >> h[i];

    vector<v64> seg(4 * n + 5);
    build(1, 1, n, seg, h);

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        v64 nodes;
        collect(1, 1, n, a, b, nodes);

        ll ans = 0;
        ll mx = 0;

        for (ll node : nodes)
        {
            auto it = upper_bound(seg[node].begin(), seg[node].end(), mx);
            ans += seg[node].end() - it;
            if (!seg[node].empty())
                mx = max(mx, seg[node].back());
        }

        cout << ans << ln;
    }

    return 0;
}