#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  vector<pair<ll,ll>> answers;
  if ( (a[0]+a[n-1]) % 2 == 1){
    for(int i = 1;i < n;i++){
      if ( (a[0]+a[i]) % 2 == 1){
        answers.push_back({0,i});
        a[i] = a[0];
      }
    }
    for(int i = n-2;i >=0;i--){
      if ( (a[n-1]+a[i]) % 2 == 0 && a[n-1] != a[i]){
        answers.push_back({i,n-1});
        a[i] = a[n-1];
      }
    }
  }else{
    for(int i = n-2;i >=0;i--){
      if ( (a[n-1]+a[i]) % 2 == 0 && a[n-1] != a[i]){
        answers.push_back({i,n-1});
        a[i] = a[n-1];
      }
    }
    for(int i = 1;i < n;i++){
      if ( (a[0]+a[i]) % 2 == 1){
        answers.push_back({0,i});
        a[i] = a[0];
      }
    }
  }
  cout << answers.size() << "\n";
  for(auto p:answers){
    cout << p.first +1 << " " << p.second+1 << "\n";
  }
  // for(int i = 0;i < n;i++){
  //   cout << a[i] << ",";
  // }
  // cout << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
