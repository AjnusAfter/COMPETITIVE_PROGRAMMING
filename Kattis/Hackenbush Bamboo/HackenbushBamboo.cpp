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

    ll n;
    cin >> n;

    ll grundy = 0;

    // v64 h(n);
    forn(i, 0, n)
    {
        ll h;
        cin >> h;

        grundy ^= h;
    }

    cout << "*" << grundy << ln;

    return 0;
}
