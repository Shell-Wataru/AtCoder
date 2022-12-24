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

vector<ll> total_xors(1ll<<17);

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> child_counts(n,0);
  for(int i = 0;i < n-1;i++){
    ll p;
    scanf("%lld",&p);
    p--;
    child_counts[p]++;
  }
  child_counts.push_back(1);
  sort(child_counts.rbegin(),child_counts.rend());
  ll has_child_count = 0;
  for(int i = 0;i < n;i++){
    if (child_counts[i] != 0){
      // cout << i << ":" << child_counts[i] << endl;
      has_child_count++;
    }
  }
  // cout << has_child_count << endl;
  priority_queue<ll> remains;
  for(int i = 0;i < has_child_count;i++){
    remains.push(max(child_counts[i] - (has_child_count - i),0ll));
  }
  ll extension = 0;
  while(remains.top() > extension){
    ll m = remains.top();
    remains.pop();
    remains.push(m-1);
    extension++;
  }
  cout << has_child_count + extension << "\n";
  return 0;
}

int main()
{
  for(int i = 1;i < 1ll<<17;i++ ){
    total_xors[i] = i ^ total_xors[i-1];
  }
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
