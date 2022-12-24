#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  string S;
  cin >> S;
  vector<vector<ll>> indices(26);
  ll n = S.size();
  for(int i = 0;i < n;i++){
    indices[S[i]-'a'].push_back(i);
  }
  if (S[0] <= S[n-1]){
    ll cost = S[n-1] - S[0];
    vector<ll> tiles;
    for(int i = S[0]-'a';i <= S[n-1]-'a';i++){
      for(auto t:indices[i]){
        tiles.push_back(t);
      }
    }
    cout << cost << " " << tiles.size() << "\n";
    for(auto t:tiles){
      cout << t+1 << " ";
    }
    cout << "\n";
  }else{
    ll cost = S[0] - S[n-1];
    vector<ll> tiles;
    for(int i = S[0]-'a';i >= S[n-1]-'a';i--){
      for(auto t:indices[i]){
        tiles.push_back(t);
      }
    }
    cout << cost << " " << tiles.size() << "\n";
    for(auto t:tiles){
      cout << t+1 << " ";
    }
    cout << "\n";
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
