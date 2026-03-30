#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    string S;
    ll K;
    cin >> S >> K;

    int N = S.size();
    ll lp = 0;
    ll dots = 0;
    ll ans = 0;

    forn(rp, 0, N)
    {
        if (S[rp] == '.')
        {
            dots++;
        }

        while (dots > K)
        {
            if (S[lp] == '.')
            {
                dots--;
            }

            lp++;
        }

        ans = max(ans, rp - lp + 1);
    }

    cout << ans << ln;

    return 0;
}