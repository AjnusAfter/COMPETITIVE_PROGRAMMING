#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    int N, X;
    
    cin >> N >> X;

    forn(i, 0, N) 
    {
        int A;
        cin >> A;

        if (A < X)
        {
            X = A;
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}