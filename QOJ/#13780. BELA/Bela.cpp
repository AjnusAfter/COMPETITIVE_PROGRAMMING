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

ll calculate(pair<char, char> card, char dominant)
{
    char number = (char)card.first;
    char suit = card.second;

    bool is_dominant = (suit == dominant);
    switch (number)
    {
    case 'A':
        return 11;
    case 'K':
        return 4;
    case 'Q':
        return 3;
    case 'J':
        return is_dominant ? 20 : 2;
    case 'T':
        return 10;
    case '9':
        return is_dominant ? 14 : 0;
    case '8':
        return 0;
    case '7':
        return 0;
    default:
        return 0;
    }
}

int main()
{
    _;

    ll N;
    char B;
    cin >> N >> B;

    vector<pair<char, char>> v(4 * N);

    forn(i, 0, 4 * N)
    {
        string s;
        cin >> s;
        v[i] = {s[0], s[1]};
    }

    ll total = 0;
    forn(i, 0, 4 * N)
    {
        total += calculate(v[i], B);
        // cout << "Card: " << v[i].first << v[i].second << ", points: " << calculate(v[i], B) << ln;
    }

    cout << total << ln;

    return 0;
}
