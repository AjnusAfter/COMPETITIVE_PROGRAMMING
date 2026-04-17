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

int main()
{
    _;

    _;

    ll N;
    cin >> N;

    v64 a(N);
    forn(i, 0, N)
    {
        cin >> a[i];
    }

    v64 pref(N + 1, 0);
    forn(i, 1, N + 1)
    {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }

    ll ans = 0;

    forn(bit, 0, 31)
    {
        ll count_1 = 0;

        forn(i, 0, N + 1)
        {
            if ((pref[i] >> bit) & 1LL)
            {
                count_1++;
            }
        }

        ll count_0 = (N + 1) - count_1;
        ans += count_0 * count_1 * (1LL << bit);
    }

    ll sum_A = 0;
    forn(i, 0, N)
    {
        sum_A += a[i];
    }

    ans -= sum_A;

    cout << ans << ln;

    return 0;
}