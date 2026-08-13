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

    ll tot_sum = 0;

    ll i = 1;
    while (i <= n)
    {
        ll q = n / i;
        ll last = n / q;
        tot_sum += q * (last - i + 1);
        
        i = last + 1;
    }

    cout << tot_sum << ln;

    return 0;
}