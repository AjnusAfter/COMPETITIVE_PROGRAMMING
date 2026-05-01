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

    ll A, B, X;
    cin >> A >> B >> X;

    ll l = 0, r = 1e9 + 1;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;

        if (A * mid + B * to_string(mid).size() <= X)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << ln;

    /*
    // 10 x 9 + 7 × 1 = 97
    A *
                N +
            B *d(N) <=
        X;
    A *N <= X - B *d(N);
    N <= (X - B * d(N)) / A;

    d(N) < d(X)
    */

    return 0;
}