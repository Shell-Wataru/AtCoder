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
  string S;
  cin >> S;
  vector<ll> candidates = {-1,1};
  bool can_make = false;
  for(auto a:candidates){
    for(auto b:candidates){
      for(auto c:candidates){
        bool made = true;
        ll total = 0;
        for(auto s:S){
          if (s == 'A'){
            total += a;
          }else if (s == 'B'){
            total += b;
          }else{
            total += c;
          }
          if (total < 0){
            made = false;
            break;
          }
        }

        if (total == 0 && made){
          can_make = true;
        }
      }
    }
  }
  if (can_make){
    cout << "YES" << "\n";
  }else
  {
    cout << "NO" << "\n";
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
  cout << flush;
  return 0;
}