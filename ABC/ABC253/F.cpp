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

// 区間加算　一点取得
//zero indexed and vector
template< typename T>
class DualBIT
{
public:
    vector<T> data;
    DualBIT(long long n) : data(n) {}
    // [0,index)に足す
    void add(int index, T v)
    {
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            data[i] += v;;
        }
    }

    // indexを取得
    long long get(int index)
    {
        T retValue = 0;
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};


int solve()
{
    ll N, M , Q;
    cin >> N >> M >> Q;
    DualBIT<ll> bit(M);
    vector<vector<vector<ll>>> waitings(N);
    vector<vector<ll>> queries;
    vector<pair<ll,ll>> answers;
    for(int i = 0;i < Q;i++){
      ll t;
      cin >>  t;
      if ( t== 1){
        ll l,r,x;
        cin >> l >> r >> x;
        queries.push_back({t,l,r,x});
      }else if (t == 2){
        ll j, x;
        cin >> j >> x;
        queries.push_back({t,j,x});
      }else{
        ll j ,k;
        cin >> j >> k;
        queries.push_back({t,j,k});
      }
    }
    for(int i = Q-1;i >= 0;i--){
      ll t = queries[i][0];
      if (t == 1){
        ll l = queries[i][1];
        ll r = queries[i][2];
        ll x = queries[i][3];
        l--;
        bit.add(r,x);
        bit.add(l,-x);
      }else if (t == 2){
        ll j = queries[i][1];
        ll x = queries[i][2];
        j--;
        while(!waitings[j].empty()){
          ll k = waitings[j].back()[2];
          answers.push_back({waitings[j].back()[0],x + bit.get(k) - waitings[j].back()[3]});
          waitings[j].pop_back();
        }
      }else{
        ll j = queries[i][1];
        ll k = queries[i][2];
        j--;
        k--;
        waitings[j].push_back({i,j,k,bit.get(k)});
      }
    }
    for(int i = 0;i < N;i++){
      while(!waitings[i].empty()){
          ll k = waitings[i].back()[2];
          answers.push_back({waitings[i].back()[0],0 + bit.get(k) - waitings[i].back()[3]});
          waitings[i].pop_back();
        }
    }
    sort(answers.begin(),answers.end());
    for(auto p:answers){
      cout << p.second << endl;
    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
