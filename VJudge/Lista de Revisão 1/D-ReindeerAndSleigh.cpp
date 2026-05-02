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

    ll N, Q;
    cin >> N >> Q;

    v64 R(N) /*, v2(Q)*/;
    forn(i, 0, N) cin >> R[i];
    // forn(i, 0, Q) cin >> v2[i];

    sort(R.begin(), R.end());

    v64 prefix(N + 1, 0);
    forn(i, 0, N) prefix[i + 1] = prefix[i] + R[i];

    while (Q--)
    {
        ll X;
        cin >> X;

        cout << upper_bound(prefix.begin(), prefix.end(), X) - prefix.begin() - 1 << ln;
    }

    return 0;
}