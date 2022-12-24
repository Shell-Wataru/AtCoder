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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  reverse(a.begin(),a.end());
  ll zeros = 0;
  while(!a.empty() && a.back() == 0){
    a.pop_back();
    zeros++;
  }
  if (a.size() == 0){
    cout << 0 << endl;
    return 0;
  }
  for(int i = 0;i < n-1;i++){
    vector<ll> new_a;
    if (zeros > 0){
      new_a.push_back(a.back());
      zeros--;
    }
    for(int j = 0;j < a.size()-1;j++){
      new_a.push_back(a[j] - a[j+1]);
    }
    sort(new_a.rbegin(),new_a.rend());
    while(!new_a.empty() && new_a.back() == 0){
      zeros++;
      new_a.pop_back();
    }
    swap(a,new_a);
    if (a.size() <= 1){
      break;
    }
  }
  if (a.size() == 0){
    cout << 0 << "\n";
  }else{
    cout << a.back() << "\n";
  }

  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}