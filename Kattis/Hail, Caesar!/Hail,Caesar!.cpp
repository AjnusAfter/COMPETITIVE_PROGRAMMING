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

    const string target = "Hail, Caesar!";
    const ll L = 32, R = 95; 
    // printable ASCII: [32, 126]

    vector<string> a(4);
    forn(i, 0, 4) getline(cin, a[i]);

    // Find encryption shift from 1st character
    ll sh = (a[0][0] - target[0] + R) % R;

    // Decrypt
    for (string &s : a)
    {
        for (char &c : s)
        {
            c = char(L + (c - L - sh + R) % R);
        }

        cout << s << ln;
    }

    return 0;
}