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

    // bool is_lucky,is_near_lucky;
    ll lucky_number_count = 0 /*, seven_count*/;

    forn(i, 0, s.size())
    {
        if (s[i] == '4' || s[i] == '7')
            lucky_number_count++;
    }

    lucky_number_count == 4 || lucky_number_count == 7 ? cout << "YES" << ln : cout << "NO" << ln;

    return 0;
}