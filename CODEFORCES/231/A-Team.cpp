#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                     \
    ios ::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    ll n;
    cin >> n;

    ll will_solve = 0;

    forn(i, 0, n)
    {
        v64 v(3);
        ll sum = 0;

        forn(j, 0, 3)
        {
            cin >> v[j];
            sum += v[j];
        }

        if (sum >= 2)
        {
            will_solve++;
        }
    }

    cout << will_solve << ln;

    return 0;
}
