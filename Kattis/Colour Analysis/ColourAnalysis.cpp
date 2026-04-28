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

    ll R, G, B;
    cin >> R >> G >> B;

    string colour;
    if (R > G && R > B)
        colour = "raudur";
    else if (G > R && G > B)
        colour = "graenn";
    else if (B > R && B > G)
        colour = "blar";

    else if (R == G && B < G)
        colour = "gulur";
    else if (R == B && G < B)
        colour = "fjolubleikur";
    else if (G == B && R < G)
        colour = "blagraenn";

    else if (B == 0 && R == 0 && G == 0)
        colour = "svartur";
    else if (B == 255 && R == 255 && G == 255)
        colour = "hvitur";
    else if (B == R && R == G && R != 0 & G != 255)
        colour = "grar";

    else
        colour = "othekkt";

    cout << colour << ln;

    return 0;
}