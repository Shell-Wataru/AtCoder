#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<ll> a(N,0);
    LazySegmentTree lst(a);
    ll ans = 0;
    vector<vector<ll>> range_data(M,vector<ll>(3));
    for(int i = 0;i < M;i++){
        ll l,r,x;
        cin >> l >> r >> x;
        l--;
        range_data[i][0] = r;
        range_data[i][1] = l;
        range_data[i][2] = x;
    }
    sort(range_data.begin(),range_data.end());
    set<ll> unused;
    for(int i = 0;i < N;i++){
        unused.insert(i);
    }
    for(int i = 0;i < M;i++){
        ll l = range_data[i][1];
        ll r = range_data[i][0];
        ll x = range_data[i][2];
        ll add = max(x - lst.getsum(l,r),0ll);
        auto iter = unused.lower_bound(r);
        vector<ll> removed;
        for(int j = 0;j < add;j++){
            iter--;
            lst.add(*iter,*iter+1,1);
            removed.push_back(*iter);
        }
        for(auto r:removed){
            unused.erase(r);
        }
        // ans += add;
        // cout << r-add << "~" << r << endl;

    }
    // cout << ans << endl;
    for(int i = 0;i < N;i++){
        if (i!= 0){
            cout << " ";
        }
        cout << lst.getsum(i,i+1);
    }
    cout << endl;
    return 0;
}