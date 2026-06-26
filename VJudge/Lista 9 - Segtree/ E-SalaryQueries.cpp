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

    v64 p(n + 1);
    forn(i, 1, n + 1) cin >> p[i];

    vector<pair<char, p64>> queries;
    v64 vals;

    forn(i, 1, n + 1) vals.push_back(p[i]);

    forn(i, 0, q)
    {
        char type;
        ll a, b;
        cin >> type >> a >> b;
        queries.push_back({type, {a, b}});
        if (type == '!')
            vals.push_back(b);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    ll sz = vals.size();
    v64 bit(sz + 1, 0);

    auto get_pos = [&](ll x)
    {
        return (ll)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    forn(i, 1, n + 1) add(get_pos(p[i]), 1, bit);

    for (auto qu : queries)
    {
        char type = qu.first;
        ll a = qu.second.first;
        ll b = qu.second.second;

        if (type == '!')
        {
            ll k = a, x = b;
            add(get_pos(p[k]), -1, bit);
            p[k] = x;
            add(get_pos(p[k]), 1, bit);
        }
        else
        {
            ll l = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            ll r = upper_bound(vals.begin(), vals.end(), b) - vals.begin();

            cout << sum(r, bit) - sum(l, bit) << ln;
        }
    }

    return 0;
}