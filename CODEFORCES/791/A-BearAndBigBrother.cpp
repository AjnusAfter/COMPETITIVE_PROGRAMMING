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

    ll a, b;
    cin >> a >> b; // 1 ≤ a ≤ b ≤ 10)

    ll i = 0;
    while (!(a > b))
    {
        a *= 3;
        b *= 2;

        i++;
    }

    cout << i << ln;

    return 0;
}