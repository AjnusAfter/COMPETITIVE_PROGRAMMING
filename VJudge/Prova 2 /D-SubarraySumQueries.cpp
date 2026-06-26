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
    ll sum, pref, suff, ans;
};

const ll MAXN = 2e5 + 5;
Node st[4 * MAXN];
v64 a(MAXN);

Node merge(Node l, Node r)
{
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}

Node make_node(ll val)
{
    return {val, max(0LL, val), max(0LL, val), max(0LL, val)};
}

void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        st[p] = make_node(a[l]);
        return;
    }

    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    st[p] = merge(st[2 * p], st[2 * p + 1]);
}

void update(ll p, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        st[p] = make_node(val);
        return;
    }

    ll mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * p, l, mid, idx, val);
    else
        update(2 * p + 1, mid + 1, r, idx, val);

    st[p] = merge(st[2 * p], st[2 * p + 1]);
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    forn(i, 1, n + 1) cin >> a[i];

    build(1, 1, n);

    while (m--)
    {
        ll k, x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << st[1].ans << ln;
    }

    return 0;
}