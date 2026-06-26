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

ll n, m;
v64 h, seg;

void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        seg[node] = h[l];
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
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

    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll x)
{
    if (seg[node] < x)
        return 0;
    if (l == r)
        return l;

    ll mid = (l + r) / 2;

    if (seg[node * 2] >= x)
        return query(node * 2, l, mid, x);
    return query(node * 2 + 1, mid + 1, r, x);
}

int main()
{
    _;
            
    cin >> n >> m;

    h.assign(n + 1, 0);
    seg.assign(4 * n + 5, 0);

    forn(i, 1, n + 1) cin >> h[i];

    build(1, 1, n);

    forn(i, 0, m)
    {
        ll x;
        cin >> x;

        ll pos = query(1, 1, n, x);
        cout << pos << " ";

        if (pos != 0)
        {
            h[pos] -= x;
            update(1, 1, n, pos, h[pos]);
        }
    }

    return 0;
}