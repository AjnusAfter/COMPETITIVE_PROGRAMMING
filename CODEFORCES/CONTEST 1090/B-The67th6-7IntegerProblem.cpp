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

    ll t;
    cin >> t;

    while (t--)
    {
        ll sum = 0;
        v64 v(7);

        forn(i, 0, 7)
        {
            cin >> v[i];
            sum += v[i];
        }

        ll maior = v[0];

        forn(i, 0, 7)
        {
            if (v[i] > maior)
            {
                maior = v[i];
            }
        }

        // cout << "maior = " << maior << ln;

        cout << 2 * maior - sum << ln;
    }

    return 0;
}