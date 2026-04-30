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

    string s;
    cin >> s;

    string ans;

    for (char c : s)
    {
        ans.push_back(c);

        ll n = ans.size();

        if (n >= 3 && ans[n - 3] == 'A' && ans[n - 2] == 'B' && ans[n - 1] == 'C')
        {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
    }

    cout << ans << ln;

    return 0;
}