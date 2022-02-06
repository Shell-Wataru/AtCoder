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
  ll x1,p1;
  ll x2,p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  if (p1 > p2){
    p1 -= p2;
    p2 = 0;
    for(int i = 0;i < p1;i++){
      if (x1 > x2){
        cout << ">" << endl;
        return 0;
      }
      x1 *= 10;
    }
    if (x1 > x2){
      cout << ">" << endl;
    }else if (x1 == x2){
      cout << "=" << endl;
    }else{
      cout << "<" << endl;
    }
  }else{
    p2 -= p1;
    p1 = 0;
    for(int i = 0;i < p2;i++){
      if (x1 < x2){
        cout << "<" << endl;
        return 0;
      }
      x2 *= 10;
    }
    if (x1 > x2){
      cout << ">" << endl;
    }else if (x1 == x2){
      cout << "=" << endl;
    }else{
      cout << "<" << endl;
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
  cout << flush;
  return 0;
}