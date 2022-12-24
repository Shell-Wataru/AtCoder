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
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll min_diff = numeric_limits<ll>::max();
  ll min_index = -1;
  for (size_t i = 0; i < n-1; i++)
  {
    if (a[i+1] - a[i] < min_diff){
      min_diff = a[i+1] - a[i];
      min_index = i;
    }
  }
  vector<ll> smaller;
  vector<ll> bigger;
  bigger.push_back(a[min_index]);
  for (size_t i = 0; i < n; i++)
  {
    if (i != min_index && i != min_index + 1 ){
      if (i < min_index){
        smaller.push_back(a[i]);
      }else{
        bigger.push_back(a[i]);
      }
    }
  }
  smaller.push_back(a[min_index+1]);
  for(int i = 0;i < bigger.size();i++){
    if (i != 0){
      cout << " ";
    }
    cout << bigger[i];
  }

  for(int i = 0;i < smaller.size();i++){
    cout << " ";
    cout << smaller[i];
  }
  cout << "\n";
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
