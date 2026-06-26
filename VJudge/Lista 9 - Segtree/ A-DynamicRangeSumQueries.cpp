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
v64 bit, a;

void add(ll idx, ll val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll sum(ll idx)
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

    cin >> n >> q;

    bit.assign(n + 1, 0);
    a.assign(n + 1, 0);

    forn(i, 1, n + 1)
    {
        cin >> a[i];
        add(i, a[i]);
    }

    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            ll diff = y - a[x];
            a[x] = y;
            add(x, diff);
        }
        else
        {
            cout << sum(y) - sum(x - 1) << ln;
        }
    }

    return 0;
}