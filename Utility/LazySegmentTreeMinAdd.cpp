// 参考http://tsutaj.hatenablog.com/entry/2017/03/30/224339
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

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

int main(){
  vector<ll> a{1,2,3,4,5,6,7,8};
  LazySegmentTree lst(a);
//   cout << lst.find(0,4) << endl;
  lst.update(0,2,6);
  for(int i = 0;i < a.size();i++){
      cout << lst.find(i,i+1) << endl;
  }

  lst.update(3,7,100);
//   for(int i = 0;i < a.size();i++){
//       cout << lst.find(i,i+1) << endl;
//   }
  ll rightest =  lst.find_rightest_sub(0,a.size(),1000);
  cout << rightest << " " << lst.find(rightest,rightest + 1) << endl;
//   cout << lst.find(0,4) << endl;
}