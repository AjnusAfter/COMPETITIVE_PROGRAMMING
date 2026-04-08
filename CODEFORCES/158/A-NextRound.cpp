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

    v64 a(n);

    forn(i, 0, n)
    {
        cin >> a[i];
    }

    ll cutoff = a[k - 1];
    ll count = 0;

    forn(i, 0, n)
    {
        if (a[i] >= cutoff && a[i] > 0)
        {
            count++;
        }
    }

    cout << count << ln;

    return 0;
}