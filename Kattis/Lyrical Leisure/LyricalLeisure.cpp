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

    string ans = "";

    if (k == 1)
    {
        string pat = "abc";
        
        forn(i, 0, n) ans += pat[i % 3];
    }
    else
    {
        forn(i, 0, k) ans += 'a';
        string pat = "bcd";
        
        forn(i, k, n) ans += pat[(i - k) % 3];
    }

    cout << ans << ln;
    
    return 0;
}