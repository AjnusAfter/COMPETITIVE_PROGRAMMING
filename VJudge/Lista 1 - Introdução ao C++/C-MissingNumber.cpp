#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    int n;
    map<int, int> mp;

    cin >> n;

    forn (i, 1, n+1)
    {
        mp[i] = 0;
    }

    forn (i, 1, n)
    {
        int A;
        cin >> A;
        
        if (mp[A] == 0)
        {
            mp.erase(A);
        }
    }

    if (mp.size() == 1)
    {
        cout << mp.begin()->first << endl;
    }

    return 0;
}