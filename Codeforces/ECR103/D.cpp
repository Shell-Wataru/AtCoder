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
ll BASE_NUM = 998244353;

int dfs(string &directions, vector<ll> &journey_ends,ll i){
  if (i == 0 && directions[i] == 'L'){
    journey_ends[i] = 0;
  }else if(i == directions.size() - 1 && directions[i] == 'R'){
    journey_ends[i] = directions.size();
  }else if (i != 0 && directions[i] == 'L' && directions[i-1] == 'R'){
    journey_ends[i] = i;
  }else if(i != directions.size() - 1 && directions[i] == 'R' && directions[i+1] == 'L'){
    journey_ends[i] = i+1;
  }else if(journey_ends[i] == -1){
    if (directions[i] == 'L'){
      journey_ends[i] = dfs(directions,journey_ends,i-1);
    }else{
      journey_ends[i] = dfs(directions,journey_ends,i+1);
    }
  }
  return journey_ends[i];
}

int solve()
{
  ll n;
  scanf("%lld",&n);
  string s;
  cin >> s;
  string odd_changed = s;
  string even_changed = s;
  for(int i = 0;i < n;i+= 2){
    if (even_changed[i] == 'L'){
      even_changed[i] = 'R';
    }else{
      even_changed[i] = 'L';
    }
  }
  for(int i = 1;i < n;i+= 2){
    if (odd_changed[i] == 'L'){
      odd_changed[i] = 'R';
    }else{
      odd_changed[i] = 'L';
    }
  }
  vector<ll> even_jouney_ends(n,-1);
  vector<ll> odd_jouney_ends(n,-1);
  ll l_start = -1;
  for(int i = 0;i<n;i++){
    dfs(odd_changed,odd_jouney_ends,i);
    dfs(even_changed,even_jouney_ends,i);
  }
  for(ll i = 0;i<=n;i++){
    if (i!= 0){
      cout << " ";
    }
    if (i % 2 == 0){
      ll right,left;
      if (i < n){
        right = max(odd_jouney_ends[i],i);
      }else{
        right = i;
      }
      if (i > 0){
        left = min(even_jouney_ends[i-1],i);
      }else{
        left = i;
      }
      cout << right - left + 1;
    }else{
      ll right,left;
      if (i < n){
        right = max(even_jouney_ends[i],i);
      }else{
        right = i;
      }
      if (i > 0){
        left = min(odd_jouney_ends[i-1],i);
      }else{
        left = i;
      }
      cout << right - left + 1;
    }
  }
  cout << "\n";
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}