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

    ll N, K;
    cin >> N >> K;

    v64 A(N);
    forn(i, 0, N)
    {
        cin >> A[i];
    }

    ll lp = 0;
    ll current_sum = 0;
    ll contiguous_subsequences = 0;

    forn(rp, 0, N)
    {
        current_sum += A[rp];

        while (current_sum >= K)
        {
            current_sum -= A[lp];
            lp++;
        }

        contiguous_subsequences += lp;
    }

    cout << contiguous_subsequences << ln;

    return 0;
}