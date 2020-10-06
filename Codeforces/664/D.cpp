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
int BASE_NUM = 998244353;

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<string> G(n);
  for(int i = 0;i < n;i++){
    cin >> G[i];
  }
  if (n >= 4 && m >= 4){
    cout << -1 << endl;
  }else if (n == 1 || m == 1){
    cout << 0 << endl;
  }else if (n == 2 || m == 2){
    ll pattern1_ope = 0;
    ll pattern2_ope = 0;
    for (int i = 0; i < max(n,m);i++){
      ll pattern;
      if (n == 2){
        if (G[0][i] == G[1][i]){
          pattern = 1;
        }else{
          pattern = 2;
        }
      }else{
        if (G[i][0] == G[i][1]){
          pattern = 1;
        }else{
          pattern = 2;
        }
      }
      if (pattern == 1){
        ll temp = pattern1_ope;
        pattern1_ope = pattern2_ope;
        pattern2_ope = temp + 1;
      }else{
        ll temp = pattern1_ope;
        pattern1_ope = pattern2_ope + 1;
        pattern2_ope = temp;
      }
    }
    cout << min(pattern1_ope, pattern2_ope ) << endl;
  }else{
    vector<pair<ll,ll>> trans_candidates = {
      {0,2},
      {0,5},
      {2,0},
      {2,7},
      {5,0},
      {5,7},
      {7,2},
      {7,5},
      {3,6},
      {6,3},
      {3,1},
      {1,3},
      {6,4},
      {4,6},
      {1,4},
      {4,1},
    };
    vector<vector<ll>> opes(2,vector<ll>(8,0));
    for (int i = 0; i < max(n,m);i++){
      for(int j = 0;j < 8;j++){
        opes[(i+1) % 2][j] = BASE_NUM;
      }
      ll pattern = 0;
      for(int j = 0;j < min(n,m);j++){
        if (n < m){
          if (G[j][i] == '1'){
            pattern += 1<<j;
          }
        }else{
          if (G[i][j] == '1'){
            pattern += 1<<j;
          }
        }
      }
      // cout << pattern << endl;
      for(auto &p:trans_candidates){
        ll changes = __builtin_popcountll(p.second ^ pattern);
        // cout << changes << ",";
        opes[(i+1)%2][p.second] = min(opes[(i+1)%2][p.second],opes[i%2][p.first] + changes);
      }
      // cout << endl;
    }
    cout << *min_element(opes[max(n,m)%2].begin(),opes[max(n,m)%2].end()) << endl;
  }


  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}