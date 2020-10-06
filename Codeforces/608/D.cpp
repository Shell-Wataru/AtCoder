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
ll BASE_NUM = 998244353;

const int INF = INT_MAX;
struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }

    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = node[k] + lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] = lazy[k];
                lazy[k*2+2] = lazy[k];
                lazyFlag[k*2+1] = true;
                lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    void add(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    int find(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

    void show_min() {
      for(int i = 0;i<n;i++) {
        cout << find(i,i+1) << endl;
      }
    }
};

struct Castle{
  ll a,b,c;
};
struct Portal{
  ll u,v;
};
struct Sentaku {
  ll cost,index,castle;

  bool operator<(const Sentaku &another) const
  {
      if (cost != another.cost){
        return cost < another.cost;
      }else if (index != another.index){
        return index < another.index;
      }else {
        return castle < another.castle;
      }
  };
};

int main()
{
  ll n,m,k;
  vector<Castle> castles;
  vector<int> yoyuu;
  vector<Sentaku> sentakushi;
  cin >> n>> m>>k;
  vector<bool> defended(n,false);

  for(int i = 0;i< n ;i++){
    Castle c;
    cin >> c.a >> c.b >> c.c;
    castles.push_back(c);
    sentakushi.push_back({c.c,i,i});
  }

  for(int i = 0;i< m ;i++){
    Portal p;
    cin >> p.u >> p.v;
    sentakushi.push_back({castles[p.v-1].c,p.u-1,p.v-1});
  }
  for(int i = 0;i< n;i++){
    yoyuu.push_back(k - castles[i].a);
    k = k + castles[i].b;
  }
  ll total_cost = 0;
  LazySegmentTree lst(yoyuu);
  if (lst.find(0,n) < 0){
    cout << -1 << endl;
  }else{
    sort(sentakushi.begin(),sentakushi.end());
    reverse(sentakushi.begin(),sentakushi.end());
    for(auto s:sentakushi){
      // cout << s.cost << " " << s.index << " " << s.castle  << endl;
      if (!defended[s.castle] &&
          lst.find(s.index + 1,n) > 0 ){
        defended[s.castle] = true;
        total_cost += s.cost;
        lst.add(s.index + 1,n,-1);
      }
    }
    // lst.show_min();
    cout << total_cost << endl;
  }
  return 0;
}