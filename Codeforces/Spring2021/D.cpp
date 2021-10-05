#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  vector<ll> current;
  for (size_t i = 0; i < n; i++)
  {
    if (a[i] == 1){
      current.push_back(a[i]);
    }else{
      while(current.back()+1 != a[i]){
        current.pop_back();
      }
      current.back()++;
    }
    for(int j = 0;j < current.size();j++){
      if (j != 0){
        cout << ".";
      }
      cout << current[j];
    }
    cout << "\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
