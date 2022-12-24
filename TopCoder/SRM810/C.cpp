#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
// 全体が1
template< typename Monoid >
struct SegmentTree {
  using T = typename Monoid::T;

  int sz;
  vector< T > seg;
  const T id = Monoid::id();

  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, id);
  }

  void set(int k, const T &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T query(int a, int b) {
    T L = id, R = id;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = Monoid::op(L, seg[a++]);
      if(b & 1) R = Monoid::op(seg[--b], R);
    }
    return Monoid::op(L, R);
  }

  T operator[](const int &k) const {
    return seg[k + sz];
  }

  int find_subtree(int a, T &x, T &M, bool type) {
    while(a < sz) {
      T nxt = type ? seg[2 * a + type] : seg[2 * a + type];
      if(Monoid::check(nxt,x)) a = 2 * a + type;
      else M = nxt,a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  // 条件を満たす[a,b]で最もbが前方にあるもの
  int find_first(int a, T x) {
    T L = id;
    if(a <= 0) {
      if(Monoid::check(seg[1],x)) return find_subtree(1, x, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        T nxt = Monoid::op(L, seg[a]);
        if(Monoid::check(seg[a],x)) return find_subtree(a, x, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  // 条件を満たす[a,b)で最もaが後方にあるもの
  int find_last(int b, T x) {
    T R = id;
    if(b >= sz) {
      if(Monoid::check(seg[1],x)) return find_subtree(1, x, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        T nxt = Monoid::op(seg[--b], R);
        if(Monoid::check(nxt,x)) return find_subtree(b, x, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monoid_max_with_index
{
  using T = pair<ll,ll>;
  static T op(T &l, T &r) {
    if (l.first >= r.first){
      return l;
    }else{
      return r;
    }
  }
  static const T id(){
    return {INT_MIN,-1};
  }
};

class ItsWhomYouKnow {
	public:
    long long state = 0;
    pair<ll,ll> new_patient(int C,int P){
        state = (state * 1103515245 + 12345) % (1ll<<31);
        ll clan = (state / 10) % C;
        state = (state * 1103515245 + 12345) % (1ll<<31);
        ll power = state % P;
        return {clan, power};
    }

	long long simulate(int N, int C, int P, vector <int> initialClans, vector <int> initialPowers, int seed){
        state = seed;
        vector<ll> clan_maximum_power(C,-1);
        vector<queue<ll>> clan_waitings(C);
        SegmentTree<monoid_max_with_index> seg(C);
        // cout << "!!" << endl;
        ll L = initialClans.size();
        for(int i = 0;i < L;i++){
            ll c= initialClans[i];
            ll p= initialPowers[i];
            clan_maximum_power[c] =  max(clan_maximum_power[c],p);
            clan_waitings[c].push(i);
        }
        for(int i = 0;i < C;i++){
            if (clan_waitings[i].size() > 0){
                seg.set(i,{clan_maximum_power[i],i});
            }
        }
        // cout << "!!" << endl;
        seg.build();
        ll  answer = 0;
        for(int i = 0;i < N;i++){
            // cout << i << endl;
            for(int j = 0;j < 2;j++){
                auto p = new_patient(C,P);
                // cout << p.first << "," << p.second << endl;
                clan_maximum_power[p.first] = max(clan_maximum_power[p.first],p.second);
                clan_waitings[p.first].push(L+2*i+j);
                seg.update(p.first,{clan_maximum_power[p.first],p.first});
            }
            auto remove = seg.query(0,C);
            ll id = clan_waitings[remove.second].front();
            // cout << clan_waitings[remove.second].size() << endl;
            clan_waitings[remove.second].pop();
            if (clan_waitings[remove.second].size() == 0){
                seg.update(remove.second,monoid_max_with_index::id());
            }
            // cout << "id" << id << endl;
            answer += id*(i+1);
            state = (state+id) % (1ll<<31);
            // cout << state << endl;
        }
        // cout << "!" << endl;
        return answer;
	}
};

int main(){
    ItsWhomYouKnow m;
    // m.simulate(5,10,1000,{},{},47);
    cout << m.simulate(5,10,1000,{},{},47) << endl;
    return 0;
}