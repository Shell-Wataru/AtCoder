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

ll BASE_NUM = 1000000007;
int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  for(int i = 0;i < n;i++){
    if (i % 2 == 0){
      if (A[i] < 0){
        A[i] = - A[i];
      }
    }else{
      if (A[i] > 0){
        A[i] = - A[i];
      }
    }
  }
  for(int i = 0;i < n;i++){
    if (i !=0){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
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