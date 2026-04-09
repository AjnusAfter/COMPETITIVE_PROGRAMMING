#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define fornm(i, s, e) for (ll i = (s); i < (e); ++i)
#define ln "\n"

int main()
{
    _;

    ll N, M;
    cin >> N >> M;

    // AI-assisted
    map<p64, ll> freq;

    forn(i, 0, M)
    {
        ll a, b;
        cin >> a >> b;
        freq[{a, b}]++;
    }

    ll W;
    cin >> W;

    v64 walk(W + 1);
    forn(i, 0, W + 1) cin >> walk[i];

    forn(i, 0, W)
    {
        p64 e = {walk[i], walk[i + 1]};

        if (freq[e] == 0)
        {
            cout << i + 1 << ln;
            return 0;
        }

        freq[e]--;
    }

    if (W < M)
    {
        cout << "too short" << ln;
    }
    else
    {
        cout << "correct" << ln;
    }

    return 0;
}