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

void add(ll idx, ll val, v64 &bit)
{
    ll n = bit.size() - 1;
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll sum(ll idx, v64 &bit)
{
    ll res = 0;
    while (idx > 0)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

int main()
{
    _;

    ll n, q;
    cin >> n >> q;

    v64 a(n + 1);
    forn(i, 1, n + 1) cin >> a[i];

    v64 bit(n + 2, 0);

    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll l, r, u;
            cin >> l >> r >> u;
            add(l, u, bit);
            if (r + 1 <= n)
                add(r + 1, -u, bit);
        }
        else
        {
            ll k;
            cin >> k;
            cout << a[k] + sum(k, bit) << ln;
        }
    }

    return 0;
}