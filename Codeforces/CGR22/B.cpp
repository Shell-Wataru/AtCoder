#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

vector<ll> xor_sum(1000000,0);
int solve()
{
  ll n;
  cin >> n;
  deque<ll> q;
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    q.push_back(a);
  }
  while(!q.empty() && q.back() == 0){
    q.pop_back();
  }
  while(!q.empty() && q.front() == 0){
    q.pop_front();
  }
  if (q.size() == 0){
    cout << "0\n";
  }else{
    for(auto a:q){
      if (a == 0){
        cout << "2\n";
        return 0;
      }
    }
    cout << "1\n";

  }
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}