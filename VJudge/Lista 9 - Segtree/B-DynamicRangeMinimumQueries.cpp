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

ll n, q;
v64 a, seg;

void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        seg[node] = a[l];
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

void update(ll node, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        seg[node] = val;
        return;
    }

    ll mid = (l + r) / 2;

    if (idx <= mid)
        update(node * 2, l, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, r, idx, val);

    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll ql, ll qr)
{
    if (qr < l || r < ql)
        return LLONG_MAX;
    if (ql <= l && r <= qr)
        return seg[node];

    ll mid = (l + r) / 2;

    return min(
        query(node * 2, l, mid, ql, qr),
        query(node * 2 + 1, mid + 1, r, ql, qr));
}

int main()
{
    _;

    cin >> n >> q;

    a.assign(n + 1, 0);
    seg.assign(4 * n + 5, 0);

    forn(i, 1, n + 1) cin >> a[i];

    build(1, 1, n);

    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            a[x] = y;
            update(1, 1, n, x, y);
        }
        else
        {
            cout << query(1, 1, n, x, y) << ln;
        }
    }

    return 0;
}