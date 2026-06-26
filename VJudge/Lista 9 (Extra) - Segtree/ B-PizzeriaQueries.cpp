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

void build(ll node, ll l, ll r, v64 &seg1, v64 &seg2, v64 &p)
{
    if (l == r)
    {
        seg1[node] = p[l] - l;
        seg2[node] = p[l] + l;
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid, seg1, seg2, p);
    build(node * 2 + 1, mid + 1, r, seg1, seg2, p);

    seg1[node] = min(seg1[node * 2], seg1[node * 2 + 1]);
    seg2[node] = min(seg2[node * 2], seg2[node * 2 + 1]);
}

void update(ll node, ll l, ll r, ll idx, ll val, v64 &seg1, v64 &seg2, v64 &p)
{
    if (l == r)
    {
        p[idx] = val;
        seg1[node] = p[idx] - idx;
        seg2[node] = p[idx] + idx;
        return;
    }

    ll mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, val, seg1, seg2, p);
    else
        update(node * 2 + 1, mid + 1, r, idx, val, seg1, seg2, p);

    seg1[node] = min(seg1[node * 2], seg1[node * 2 + 1]);
    seg2[node] = min(seg2[node * 2], seg2[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll ql, ll qr, v64 &seg)
{
    if (qr < l || r < ql)
        return (ll)4e18;
    if (ql <= l && r <= qr)
        return seg[node];

    ll mid = (l + r) / 2;
    return min(
        query(node * 2, l, mid, ql, qr, seg),
        query(node * 2 + 1, mid + 1, r, ql, qr, seg));
}

int main()
{
    _;

    ll n, q;
    cin >> n >> q;

    v64 p(n + 1);
    forn(i, 1, n + 1) cin >> p[i];

    v64 seg1(4 * n + 5), seg2(4 * n + 5);
    build(1, 1, n, seg1, seg2, p);

    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll k, x;
            cin >> k >> x;
            update(1, 1, n, k, x, seg1, seg2, p);
        }
        else
        {
            ll k;
            cin >> k;

            ll left = query(1, 1, n, 1, k, seg1) + k;
            ll right = query(1, 1, n, k, n, seg2) - k;

            cout << min(left, right) << ln;
        }
    }

    return 0;
}