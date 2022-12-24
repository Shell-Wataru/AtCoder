#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  cin >> n >> k;
  map<ll,ll> data;
  vector<vector<ll>> arrays;
  vector<ll> answers(n,-2);
  for(int i = 0;i < n;i++){
    ll p;
    cin >> p;
    p--;
    auto iter = data.lower_bound(p);
    if (iter == data.end()){
        arrays.push_back({p});
        data[p] = arrays.size()-1;
    }else{
        data[p] = iter->second;
        arrays[iter->second].push_back(p);
        data.erase(iter->first);
    }
    if (arrays[data[p]].size() == k){
        for(auto index:arrays[data[p]]){
            answers[index] = i;
        }
        data.erase(p);
    }
  }
  for(int i = 0;i < n;i++){
    cout << answers[i] + 1<< "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
//   ll t;
//   cin >> t;
//   for (int i = 1; i <= t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}