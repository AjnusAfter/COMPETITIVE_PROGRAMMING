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


ll C(ll n, ll k)
{
    k = min(k, n - k);

    __int128 ans = 1;

    forn(i, 1, k + 1)
        ans = ans * (n - k + i) / i;

    return (ll)ans;
}

ll multinomial(const vector<ll> &v)
{
    ll rem = accumulate(v.begin(), v.end(), 0LL);

    __int128 ans = 1;

    for (ll x : v)
    {
        ans *= C(rem, x);
        rem -= x;
    }

    return (ll)ans;
}

void gen(ll idx, ll dims, ll rem, ll last, vector<ll> &v, set<ll> &ans)
{
    if (idx == dims - 1)
    {
        if (rem < last)
            return;

        v[idx] = rem;

        ans.insert(multinomial(v));
        return;
    }

    forn(x, last, rem + 1)
    {
        v[idx] = x;
        gen(idx + 1, dims, rem - x, x, v, ans);
    }
}

int main()
{
    _;

    ll D, H;
    cin >> D >> H;

    vector<ll> v(D, 0);
    set<ll> ans;

    gen(0, D, H - 1, 0, v, ans);

    for (ll x : ans)
        cout << x << ln;

    return 0;
}