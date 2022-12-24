#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> A(n);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  for(int i = 0;i < n;i++){
    cin >> A[i];
    q.push({A[i],i});
  }
  ll removed = 0;
  while(!q.empty()  && (q.top().first <= removed || k >= q.size())){
    if (q.top().first <= removed){
        q.pop();
    }else{
        ll remove = min((ll) (k/q.size()),q.top().first-removed);
        k -= remove*q.size();
        removed+= remove;
    }
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
        cout << " ";
    }
    if (A[i] <= removed){
        cout << 0;
    }else if (k > 0){
        cout << A[i]-removed-1;
        k--;
    }else{
        cout << A[i]-removed;
    }

  }
  cout << "\n";
  return 0;
}

int main()
{
  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}