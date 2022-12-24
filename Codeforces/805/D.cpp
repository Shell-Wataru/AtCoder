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
  ll p;
  string w;
  cin >> w;
  scanf("%lld",&p);
  vector<ll> counts(26);
  vector<ll> removed_counts(26);
  ll current = 0;
  for(auto c:w){
    counts[c-'a']++;
    current += c-'a' +1;
  }

  for(int i = 25;i >= 0;i--){
    ll d = current-p;
    if (d <= 0){
        continue;
    }
    ll removes = min((d+i)/(i+1),counts[i]);
    removed_counts[i] = removes;
    current -= (i+1)*removes;
  }
  for(auto c:w){
    if (removed_counts[c-'a'] > 0){
        removed_counts[c-'a']--;
    }else{
        cout << c;
    }
  }
  cout << "\n";
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
