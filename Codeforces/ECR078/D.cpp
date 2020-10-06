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
ll BASE_NUM =    998244353;
int BIG_VALUE = 2147483647;


int solve(){
   return 0;
}
int main()
{
  ll t;
  cin >> t;
  vector<pair<ll,ll>> LRs;
  for(int i = 0;i<t;i++){
      ll l,r;
      cin >> l >> r;
      LRs.push_back({l,r});
  }
  sort(LRs.begin(),LRs.end());
  return 0;
}