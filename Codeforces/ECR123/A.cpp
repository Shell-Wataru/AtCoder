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
  cin >>  S;
  ll r = -1;
  ll g = -1;
  ll b = -1;
  for(int i = 0;i < 6;i++){
    if (S[i] == 'r'){
      r = i;
    }else if (S[i] == 'g'){
      g = i;
    }else if (S[i] == 'b'){
      b = i;
    }else if (S[i] == 'R'){
      if (r == -1){
        cout << "NO" << endl;
        return 0;
      }
    }else if (S[i] == 'G'){
      if (g == -1){
        cout << "NO" << endl;
        return 0;
      }
    }else if (S[i] == 'B'){
      if (b == -1){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
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