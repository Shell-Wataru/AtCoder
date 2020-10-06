#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> S(n+1,0);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
    if (i % 2 == 0){
      S[i+1] = S[i] + A[i];
    }else{
      S[i+1] = S[i] - A[i];
    }
  }
  if (S[n] == 0){
    cout << n << endl;
    for(int i = 0; i < n;i++){
      if (i != 0){
        cout << " ";
      }
      cout << A[i];
    }
    cout << endl;
  }else{
    ll remove_index = -1;
    for(int i = 0;i < n;i++){
      ll total = S[i] - (S[n] - S[i+1]);
      if (total == 0){
        remove_index = i;
        break;
      }
    }

    cout << n - 1<< endl;
    vector<ll> ans;
    for(int i = 0; i < n;i++){
      if (i == remove_index){
        continue;
      }
      ans.push_back(A[i]);
    }
    for(int i = 0; i < n-1;i++){
      if (i != 0){
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}