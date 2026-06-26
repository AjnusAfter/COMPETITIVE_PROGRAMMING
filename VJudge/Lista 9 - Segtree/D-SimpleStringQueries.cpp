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

ll val(char c)
{
    return 1LL << (c - 'a');
}

void build(ll node, ll l, ll r, v64 &seg, string &s)
{
    if (l == r)
    {
        seg[node] = val(s[l - 1]);
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid, seg, s);
    build(node * 2 + 1, mid + 1, r, seg, s);
    seg[node] = seg[node * 2] | seg[node * 2 + 1];
}

void update(ll node, ll l, ll r, ll idx, char c, v64 &seg)
{
    if (l == r)
    {
        seg[node] = val(c);
        return;
    }

    ll mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, c, seg);
    else
        update(node * 2 + 1, mid + 1, r, idx, c, seg);

    seg[node] = seg[node * 2] | seg[node * 2 + 1];
}

ll query(ll node, ll l, ll r, ll ql, ll qr, v64 &seg)
{
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return seg[node];

    ll mid = (l + r) / 2;
    return query(node * 2, l, mid, ql, qr, seg) |
           query(node * 2 + 1, mid + 1, r, ql, qr, seg);
}

int main()
{
    _;
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll q;
    cin >> q;

    v64 seg(4 * n + 5, 0);

    build(1, 1, n, seg, s);

    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll idx;
            char c;
            cin >> idx >> c;

            if (s[idx - 1] != c)
            {
                s[idx - 1] = c;
                update(1, 1, n, idx, c, seg);
            }
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll mask = query(1, 1, n, l, r, seg);
            cout << __builtin_popcountll(mask) << ln;
        }
    }

    return 0;
}