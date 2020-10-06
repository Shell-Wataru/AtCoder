#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

const ll INF = numeric_limits<ll>::max();
struct LazySegmentTree
{
private:
    ll n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v)
    {
        ll sz = (ll)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
        lazyFlag.resize(2 * n - 1, false);

        for (ll i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (ll i = n - 2; i >= 0; i--)
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void lazyEvaluate(ll k, ll l, ll r)
    {
        if (lazyFlag[k])
        {
            node[k] = lazy[k] + node[k];
            if (r - l > 1)
            {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = 0;
        }
    }

    void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] = lazy[k] + x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else
        {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return INF;
        if (a <= l && r <= b)
            return node[k];
        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    int find_rightest_sub(int a, int b,ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (node[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn -1
            return - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != - 1) {  // 右の部分木を見て -1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
};


int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n+1,0);
    vector<ll> B(n+1,0);
    vector<ll> C(n+1,0);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i+1]);
        A[i+1] *= -1;
    }
    for (size_t i = 1; i <= n; i++)
    {
        if (A[i] < A[i-1]){
            B[i] = B[i-1] + A[i] - A[i-1];
            C[i] = C[i-1];
        }else{
            B[i] = B[i-1];
            C[i] = C[i-1] + A[i] - A[i-1];
        }
    }
    // for (size_t i = 0; i <= n; i++)
    // {
    //     cout << - B[i] << ",";
    // }
    // cout << endl;
    // for (size_t i = 0; i <= n; i++)
    // {
    //     cout << - C[i] << ",";
    // }
    // cout << endl;

    LazySegmentTree lst_a(A);
    LazySegmentTree lst_b(B);
    LazySegmentTree lst_c(C);
    // cout << - lst_c.find(1,n+1) << endl;
    // cout << - lst_b.find(1,n+1) << endl;
    cout << (- lst_c.find(1,n+1) - lst_b.find(1,n+1) + 1)/2 << endl;
    ll q;
    scanf("%lld",&q);
    for(int i = 0;i < q;i++){
        ll l,r,x;
        cin >> l >> r >> x;
        lst_a.update(l,r+1,- x);
        ll new_diff_l = lst_a.find(l,l+1) - lst_a.find(l-1,l);
        ll old_b_diff_l = lst_b.find(l,l+1) - lst_b.find(l-1,l);
        ll old_c_diff_l = lst_c.find(l,l+1) - lst_c.find(l-1,l);

        if (new_diff_l < 0){
            lst_b.update(l,n+1,new_diff_l - old_b_diff_l);
            lst_c.update(l,n+1,-old_c_diff_l);
        }else{
            lst_b.update(l,n+1,- old_b_diff_l);
            lst_c.update(l,n+1,new_diff_l-old_c_diff_l);
        }
        if (r != n){
            ll new_diff_r = lst_a.find(r+1,r+2) - lst_a.find(r,r+1);
            ll old_b_diff_r = lst_b.find(r+1,r+2) - lst_b.find(r,r+1);
            ll old_c_diff_r = lst_c.find(r+1,r+2) - lst_c.find(r,r+1);

            if (new_diff_r < 0){
                lst_b.update(r+1,n+1,new_diff_r - old_b_diff_r);
                lst_c.update(r+1,n+1,-old_c_diff_r);
            }else{
                lst_b.update(r+1,n+1,- old_b_diff_r);
                lst_c.update(r+1,n+1,new_diff_r-old_c_diff_r);
            }
        }

        cout << "!!!" << endl;
        cout << - lst_b.find(1,n+1) << endl;
        cout << - lst_c.find(1,n+1) << endl;
        cout << (- lst_b.find(1,n+1) - lst_c.find(1,n+1) + 1) << endl;
        cout << (- lst_b.find(1,n+1) - lst_c.find(1,n+1) + 1)/2 << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
