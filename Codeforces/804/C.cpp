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
  scanf("%lld", &n);
  vector<ll> a;
  ll zero_count = 0;
  for(int i = 0;i < n;i++){
    ll _a;
    scanf("%lld",&_a);
    if (_a == 0){
      zero_count++;
    }else{
      a.push_back(_a);
    }
  }
  sort(a.begin(),a.end());
  if (a.size() == 0 || a.size() == 1){
    cout << "YES\n";
  }else if (a.size() == 2){
    if (a[0] + a[1] == 0){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }else if (a.size() == 3){
    if (zero_count > 0){
      cout << "NO\n";
    }else if (binary_search(a.begin(),a.end(),a[0]+a[1]+a[2])){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }else if (a.size() == 4){
    if (zero_count > 0){
      cout << "NO\n";
    }else if (a[0]+a[3] == 0 && a[1]+a[2] == 0){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }else{
    cout << "NO\n";
  }
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
