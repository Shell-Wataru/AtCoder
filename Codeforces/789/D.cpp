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

vector<ll> counts;
int solve()
{
  ll n;
  scanf("%lld",&n);
  cout << lower_bound(counts.begin(),counts.end(),n) - counts.begin() + 1<< endl;
  return 0;
}

int main()
{
  ll triangles = 0;
  ll add = 0;
  for(int i = 0; i < 1000000;i++){
    if (i % 3 != 0){
      add += 2;
    }
    triangles += add;
    counts.push_back(triangles);
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
