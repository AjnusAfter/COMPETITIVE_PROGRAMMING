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

    v64 p(n);
    forn(i, 0, n) cin >> p[i];

    sort(p.begin(), p.end());

    ll media = p[n / 2];
    ll custo = 0;

    forn(i, 0, n) custo += abs(p[i] - media);

    cout << custo << ln;

    return 0;
}