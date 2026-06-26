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
    ll mx1, cnt1, mx2, cnt2;
};

Node make_node(ll x)
{
    return {x, 1, 0, 0};
}

Node merge(Node a, Node b)
{
    map<ll, ll> mp;

    if (a.cnt1)
        mp[a.mx1] += a.cnt1;
    if (a.cnt2)
        mp[a.mx2] += a.cnt2;
    if (b.cnt1)
        mp[b.mx1] += b.cnt1;
    if (b.cnt2)
        mp[b.mx2] += b.cnt2;

    vector<p64> v;
    for (auto [val, cnt] : mp)
        v.push_back({val, cnt});
    sort(v.rbegin(), v.rend());

    Node res = {0, 0, 0, 0};
    if (!v.empty())
    {
        res.mx1 = v[0].first;
        res.cnt1 = v[0].second;
    }
    if ((ll)v.size() >= 2)
    {
        res.mx2 = v[1].first;
        res.cnt2 = v[1].second;
    }
    return res;
}

void build(ll node, ll l, ll r, vector<Node> &seg, v64 &a)
{
    if (l == r)
    {
        seg[node] = make_node(a[l]);
        return;
    }

    ll mid = (l + r) / 2;
    build(node * 2, l, mid, seg, a);
    build(node * 2 + 1, mid + 1, r, seg, a);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

void update(ll node, ll l, ll r, ll idx, ll val, vector<Node> &seg)
{
    if (l == r)
    {
        seg[node] = make_node(val);
        return;
    }

    ll mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, val, seg);
    else
        update(node * 2 + 1, mid + 1, r, idx, val, seg);

    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

Node query(ll node, ll l, ll r, ll ql, ll qr, vector<Node> &seg)
{
    if (qr < l || r < ql)
        return {0, 0, 0, 0};
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

    ll n, q;
    cin >> n >> q;

    v64 a(n + 1);
    forn(i, 1, n + 1) cin >> a[i];

    vector<Node> seg(4 * n + 5);
    build(1, 1, n, seg, a);

    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            update(1, 1, n, x, y, seg);
        }
        else
        {
            Node ans = query(1, 1, n, x, y, seg);
            cout << ans.cnt2 << ln;
        }
    }

    return 0;
}