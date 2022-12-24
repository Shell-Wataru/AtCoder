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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    size_t size() const
    {
        return xs.size();
    }
    const T &operator[](int k) const
    {
        return xs[k];
    }
};

int main()
{
  ll N,X;
  cin >> N >> X;
  vector<ll> Y(N);
  vector<ll> Z(N);
  unordered_map<ll,pair<char,ll>> mapping;
  Compress<ll> C;
  C.add(0);
  C.add(X);
  mapping[0] = {'S',0};
  mapping[X] = {'G',0};
  for(int i = 0;i < N;i++){
    cin >> Y[i];
    C.add(Y[i]);
    mapping[Y[i]] = {'Y',i};
  }
  for(int i = 0;i < N;i++){
    cin >> Z[i];
    C.add(Z[i]);
    mapping[Z[i]] = {'Z',i};
  }

  C.build();
  vector<vector<vector<ll>>> DP(C.size(),vector<vector<ll>>(C.size(),vector<ll>(2,numeric_limits<ll>::max())));
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
  q.push({0,C.get(0),C.get(0),0});
  q.push({0,C.get(0),C.get(0),1});
  while(!q.empty()){
    auto v = q.top();
    q.pop();
    ll d = v[0];
    ll l = v[1];
    ll r = v[2];
    ll in_l = v[3];
    if (d < DP[l][r][in_l]){
      DP[l][r][in_l] = d;
      if (in_l && mapping[C[l]].first == 'G'){
        break;
      }
      if (!in_l && mapping[C[r]].first == 'G'){
        break;
      }
      if (r+1 < C.size() && mapping[C[r+1]].first == 'Y'){
        if (C[l] <= Z[ mapping[C[r+1]].second] && Z[ mapping[C[r+1]].second] <= C[r]){
          if (in_l){
            q.push({d+ abs(C[l]-C[r+1]),l,r+1,0});
          }else{
            q.push({d+ abs(C[r]-C[r+1]),l,r+1,0});
          }
        }
      }else if (r+1 < C.size() && mapping[C[r+1]].first != 'Y'){
        if (in_l){
          q.push({d+ abs(C[l]-C[r+1]),l,r+1,0});
        }else{
          q.push({d+ abs(C[r]-C[r+1]),l,r+1,0});
        }
      }
      if (l -1 >= 0 && mapping[C[l-1]].first == 'Y'){
        if (C[l] <= Z[ mapping[C[l-1]].second] && Z[ mapping[C[l-1]].second] <= C[r]){
          if (in_l){
            q.push({d+ abs(C[l]-C[l-1]),l-1,r,1});
          }else{
            q.push({d+ abs(C[r]-C[l-1]),l-1,r,1});
          }
        }
      }else if (l -1 >= 0 && mapping[C[l-1]].first != 'Y'){
        if (in_l){
            q.push({d+ abs(C[l]-C[l-1]),l-1,r,1});
          }else{
            q.push({d+ abs(C[r]-C[l-1]),l-1,r,1});
          }
      }
    }
  }
  ll ans = numeric_limits<ll>::max();
  // cout << C.get(0) << endl;
  // cout << C.get(X) << endl;
  for(int i = 0;i < C.size();i++){

    ans = min(ans,DP[i][C.get(X)][0]);
    ans = min(ans,DP[i][C.get(X)][1]);
    ans = min(ans,DP[C.get(X)][i][0]);
    ans = min(ans,DP[C.get(X)][i][1]);
  }
  if (ans == numeric_limits<ll>::max()){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
  return 0;
}
