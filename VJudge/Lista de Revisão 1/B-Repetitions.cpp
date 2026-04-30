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

    // ll a_count = 0, c_count = 0, g_count = 0, t_count = 0;
    /*string a_pilha, c_pilha, g_pilha, t_pilha;

    forn(i, 0, s.size())
    {
        if ((s[i] == 'A' && a_pilha.size() == 0) || (s[i] == 'A' && s[i - 1] == 'A'))
            a_pilha.push_back(s[i]);
        else if ((s[i] == 'C' && c_pilha.size() == 0) || (s[i] == 'C' && s[i - 1] == 'C'))
            c_pilha.push_back(s[i]);
        else if ((s[i] == 'G' && g_pilha.size() == 0) || (s[i] == 'G' && s[i - 1] == 'G'))
            g_pilha.push_back(s[i]);
        else if ((s[i] == 'T' && t_pilha.size() == 0) || (s[i] == 'T' && s[i - 1] == 'T'))
            t_pilha.push_back(s[i]);
    }

    cout << max({a_pilha.size(), c_pilha.size(), g_pilha.size(), t_pilha.size()}) << ln;
    */

    ll best = 1, current = 1;

    forn(i, 1, s.size())
    {
        if (s[i] == s[i - 1])
            current++;
        else
        {
            current = 1;
        }

        best = max(best, current);
    }

    cout << best << ln;

    return 0;
}