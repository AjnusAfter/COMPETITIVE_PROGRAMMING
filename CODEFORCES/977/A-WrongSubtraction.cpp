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

    ll n, k;
    cin >> n >> k;

    forn(i, 0, k)
    {
        n % 10 == 0 ? n /= 10 : n--;
    }

    cout << n << ln;

    return 0;
}