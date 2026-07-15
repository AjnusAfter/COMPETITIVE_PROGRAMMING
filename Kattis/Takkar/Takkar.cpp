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
    cin >> a >> b;

    // a > b ? cout << "MAGA!" : cout << "FAKE NEWS!";
    if (a > b)
        cout << "MAGA!" << ln;
    else if (a < b)
        cout << "FAKE NEWS!" << ln;
    else
        cout << "WORLD WAR 3!" << ln;

    return 0;
}