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

    ll k, n, w;
    cin >> k >> n >> w;

    ll total_cost = 0;
    forn(i, 1, w + 1)
    {
        total_cost += i * k;
    }

    ll borrow = max(0LL, total_cost - n);
    
    cout << borrow << ln;

    return 0;
}
