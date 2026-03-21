#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    ll n;
    ll previous = 0;
    ll current;
    ll moves = 0;

    cin >> n;

    forn(i, 0, n)
    {
        cin >> current;

        if (current < previous)
        {
            moves += (previous - current);
            current = previous;
        }

        previous = current;
    }

    cout << moves << "\n";

    return 0;
}