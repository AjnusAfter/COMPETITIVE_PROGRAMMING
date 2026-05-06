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

    ll T;
    cin >> T;

    while (T--)
    {
        ll X;
        cin >> X;

        ll msb = 1;
        while ((msb << 1) <= X)
        {
            msb <<= 1;
        }

        ll A = X ^ msb;
        ll B = msb;

        cout << A << " " << B << ln;

        /*ll l = 0;
        forn(r, 0, X)
        {
            if ((l ^ r) == X)
            {
                cout << l << " " << r << ln;
            }

            l++;
        }
            */
    }

    return 0;
}