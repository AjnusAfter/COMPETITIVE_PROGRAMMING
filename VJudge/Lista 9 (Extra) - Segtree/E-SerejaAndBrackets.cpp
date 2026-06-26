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

struct Node
{
    ll open, close, full;
};

Node merge(Node a, Node b)
{
    ll match = min(a.open, b.close);

    Node res;
    res.full = a.full + b.full + match;
    res.open = a.open + b.open - match;
    res.close = a.close + b.close - match;

    return res;
}

void build(ll node, ll l, ll r, vector<Node> &seg, string &s)
{
    if (l == r)
    {
        if (s[l - 1] == '(')
            seg[node] = {1, 0, 0};
        else
            seg[node] = {0, 1, 0};
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid, seg, s);
    build(node * 2 + 1, mid + 1, r, seg, s);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

Node query(ll node, ll l, ll r, ll ql, ll qr, vector<Node> &seg)
{
    if (qr < l || r < ql)
        return {0, 0, 0};
    if (ql <= l && r <= qr)
        return seg[node];

    ll mid = (l + r) / 2;
    return merge(
        query(node * 2, l, mid, ql, qr, seg),
        query(node * 2 + 1, mid + 1, r, ql, qr, seg));
}

int main()
{
    _;

    string s;
    cin >> s;

    ll n = s.size();
    ll m;
    cin >> m;

    vector<Node> seg(4 * n + 5);
    build(1, 1, n, seg, s);

    while (m--)
    {
        ll l, r;
        cin >> l >> r;

        Node ans = query(1, 1, n, l, r, seg);
        cout << 2 * ans.full << ln;
    }

    return 0;
}