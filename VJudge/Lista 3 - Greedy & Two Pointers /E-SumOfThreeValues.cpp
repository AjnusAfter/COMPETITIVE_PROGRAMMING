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

    ll n, x;
    cin >> n >> x;

    vector<p64> a(n); // valor | posição original
    forn(i, 0, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    forn(i, 0, n)
    {
        ll lp = i + 1;
        ll rp = n - 1;

        while (lp < rp)
        {
            ll sum = a[i].first + a[lp].first + a[rp].first;

            if (sum == x)
            {
                // "if there are many solutions, you can print ANY ff them (competitive)"
                cout << a[i].second << " " << a[lp].second << " " << a[rp].second << ln;

                /* in order (as the given output, [not-competitive])
                v64 ans = {a[i].second, a[lp].second, a[rp].second};
                sort(ans.begin(), ans.end());
                cout << ans[0] << " " << ans[1] << " " << ans[2] << ln;
                */

                return 0;
            }
            else if (sum < x)
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }
    }

    cout << "IMPOSSIBLE" << ln;

    return 0;
}