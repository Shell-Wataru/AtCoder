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
  ll n;
  scanf("%lld", &n);
  vector<ll> p(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&p[i]);
    p[i]--;
  }
  ll count = 0;
  ll maximum = -1;
  stack<ll> s;
  for(int i = 0;i < n;i++){
    if (p[i] > maximum){
      count++;
      s.push(p[i]);
      maximum = p[i];
    }else{
      while(!s.empty() && s.top() > p[i]){
        s.pop();
        count--;
      }
      s.push(maximum);
      count++;
    }
  }
  // cout << s.size() << endl;
  cout << count << "\n";
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
