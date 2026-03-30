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

    ll n;
    cin >> n;

    while (n--)
    {
        string word;
        cin >> word;

        if (word.length() > 10)
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << ln;
        else
            cout << word << ln;
    }

    return 0;
}
