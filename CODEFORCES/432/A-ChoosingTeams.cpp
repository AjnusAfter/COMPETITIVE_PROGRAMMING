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

    ll n, k;
    cin >> n >> k;

    //v64 y(n);
    //forn(i, 0, n) cin >> y[i];

    ll cnt = 0;

    forn(i, 0, n)
    {
        ll y;
        cin >> y;

        if (y + k <= 5)
            cnt++;
    }

    cout << cnt / 3 << ln;

    return 0;
}