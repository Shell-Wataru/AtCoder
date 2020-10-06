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
  string S;
  cin >> S;
  if (n % 2 == 0){
    bool even_found = false;
    for(int i = 0;i < n;i++){
      if (i % 2 == 1 && (S[i] - '0') % 2 == 0){
        even_found = true;
      }
    }
    if (even_found){
      cout << 2 << endl;
    }else{
      cout << 1 << endl;
    }
  }else{
    bool odd_found = false;
    for(int i = 0;i < n;i++){
      if (i % 2 == 0 && (S[i] - '0') % 2 == 1){
        odd_found = true;
      }
    }
    if (odd_found){
      cout << 1 << endl;
    }else{
      cout << 2 << endl;
    }
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