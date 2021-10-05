#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  string a,b;
  cin >> b;
  char last = '-';
  for(int i = 0;i < n;i++){
    if (b[i] == '0'){
      if (last == '1'){
        last = '0';
        a += '0';
      }else{
        last = '1';
        a += '1';
      }
    }else{
      if (last == '2'){
        last = '1';
        a += '0';
      }else{
        last = '2';
        a += '1';
      }
    }
  }
  cout << a << endl;
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