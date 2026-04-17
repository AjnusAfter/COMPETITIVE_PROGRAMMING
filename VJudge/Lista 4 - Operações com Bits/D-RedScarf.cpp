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

    if (n % 2 != 0)
    {
        cout << "n deve ser PAR" << ln;
        return 0;
    }

    v64 a(n);
    v64 v(n);
    forn(i, 0, n)
    {
        cin >> a[i];
    }

    ll sum = 0;
    forn(i, 0, n)
    {
        sum ^= a[i];
    }

    forn(i, 0, n)
    {
        v[i] = sum ^ a[i];
        cout << v[i] << " ";
    }

    cout << ln;

    return 0;
}