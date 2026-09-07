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

    ll saldo = 0, menor = 0;

    forn(i, 0, n)
    {
        char c;
        ll x;
        cin >> c >> x;

        if (c == 'T')
            saldo -= x;
        else
            saldo += x;

        menor = min(menor, saldo);
    }

    cout << -menor << ln;

    return 0;
}