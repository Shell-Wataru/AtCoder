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



int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  auto compare = [](pair<ll,ll> &a, pair<ll,ll> &b) {
    if (a.second - a.first < b.second - b.first){
      return true;
    }else if (a.second - a.first > b.second - b.first){
      return false;
    }else{
      return a.first > b.first;
    }

  };

  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, decltype(compare)> q(compare);
  q.push({0,n});
  for (int i = 0; i < n; i++)
  {
    auto p = q.top();
    q.pop();
    // cout << p.first << " " << p.second << endl;
    ll center = (p.first + p.second - 1) / 2;
    A[center] = i + 1;
    q.push({p.first,center});
    q.push({center+1,p.second});
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}