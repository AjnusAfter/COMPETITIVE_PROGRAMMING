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

    ll n;
    cin >> n;

    ll pass_at = 0;
    ll pass_tot = 0;

    forn(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;

        pass_at += b - a;
        pass_tot = max(pass_tot, pass_at);
    }

    cout << pass_tot << ln;

    return 0;
}