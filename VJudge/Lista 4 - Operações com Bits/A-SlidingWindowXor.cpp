#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie()
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    ll windows = n - k + 1;
    ll the_xor = 0;
    ll cur = x;

    forn(i, 1, n + 1)
    {
        ll left = max(1LL, i - k + 1);
        ll right = min(i, windows);
        ll cnt = max(0LL, right - left + 1);

        if (cnt % 2 == 1)
        {
            the_xor ^= cur;
        }

        if (i < n)
        {
            cur = (a * cur + b) % c;
        }
    }

    cout << the_xor << '\n';

    return 0;
}