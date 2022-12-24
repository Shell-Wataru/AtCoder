#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<string> G(2);
  cin >> G[0];
  cin >> G[1];
  bool in_up = true;
  bool in_down = true;
  bool wrote = false;
  for(int i = 0;i < n;i++){
    // cout << in_up << "," <<  in_down << endl;
    if (G[0][i] == 'B' && G[1][i] == 'B'){
      // cout << "!" << endl;
      bool next_in_up = in_down;
      bool next_in_down = in_up;
      in_up = next_in_up;
      in_down = next_in_down;
      wrote = true;
    }else if (G[0][i] == 'B' && G[1][i] == 'W'){
      in_down = false;
      wrote = true;
    }else if (G[0][i] == 'W' && G[1][i] == 'B'){
      in_up = false;
      wrote = true;
    }else if (G[0][i] == 'W' && G[1][i] == 'W'){
      if (wrote){
        in_up = false;
        in_down = false;
      }
    }
  }
  // cout << in_up << endl;
  // cout << in_down << endl;
  if (in_up || in_down){
    cout << "YES\n";
  }else{
    cout << "NO\n";
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
