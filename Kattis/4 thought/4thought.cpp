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

ll calc(ll a, char op, ll b)
{
    if (op == '+')
    {
        return a + b;
    }

    if (op == '-')
    {
        return a - b;
    }

    if (op == '*')
    {
        return a * b;
    }

    return a / b;
}

int main()
{
    _;

    ll m, n;
    cin >> m;

    vector<char> ops = {'+', '-', '*', '/'};
    map<ll, string> ans;

    for (char op1 : ops)
    {
        for (char op2 : ops)
        {
            for (char op3 : ops)
            {
                vector<ll> values = {4};
                vector<char> lowOps = {op1, op2, op3};
                vector<char> addSub;

                forn(i, 0, 3)
                {
                    if (lowOps[i] == '*' || lowOps[i] == '/')
                    {
                        values.back() = calc(values.back(), lowOps[i], 4);
                    }
                    else
                    {
                        addSub.push_back(lowOps[i]);
                        values.push_back(4);
                    }
                }

                ll result = values[0];
                forn(i, 0, addSub.size())
                {
                    result = calc(result, addSub[i], values[i + 1]);
                }

                string expr = "4 ";
                expr += op1;
                expr += " 4 ";
                expr += op2;
                expr += " 4 ";
                expr += op3;
                expr += " 4 = ";
                expr += to_string(result);

                ans[result] = expr;
            }
        }
    }

    while (m--)
    {
        cin >> n;
        cout << (ans.count(n) ? ans[n] : "no solution") << ln;
    }

    return 0;
}