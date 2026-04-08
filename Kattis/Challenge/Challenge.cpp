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

    ll a, b;
    double ans1, ans2;
    cin >> a;

    b = 100.0 - a;

    ans1 = 100.0 / a;
    ans2 = 100.0 / b;

    cout << fixed << setprecision(10) << ans1 << "\n";
    cout << fixed << setprecision(10) << ans2 << "\n";

    return 0;
}
