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
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<pair<pair<ll,ll>,vector<ll>>> a(n,{{0,0},vector<ll>(m)});
  ll total = 0;
  for(int i = 0;i < n;i++){
    a[i].first.second = i;
    for(int j = 0;j < m;j++){
        scanf("%lld",&a[i].second[j]);
        if (a[i].second[j] == 1){
            a[i].first.first++;
            total++;
        }
    }
  }
  if (total % n !=0){
    cout << -1 << endl;
    return 0;
  }
  sort(a.begin(),a.end());
  ll l = 0;
  ll check_index = 0;
  ll r = n-1;
  ll target = total/n;
  vector<vector<ll>> answers;
  while(l < r){
    if (a[l].first.first == target){
        l++;
        check_index = 0;
    }else if (a[r].first.first == target){
        r--;
        check_index = 0;
    }else{
        if (a[l].second[check_index] == 0 && a[r].second[check_index] == 1){
            a[l].second[check_index] = 1;
            a[r].second[check_index] = 0;
            a[l].first.first++;
            a[r].first.first--;
            answers.push_back({a[l].first.second,a[r].first.second,check_index});
            check_index++;
        }else{
            check_index++;
        }
    }
  }
  cout << answers.size() << "\n";
  for(int i = 0;i < answers.size();i++){
    cout << answers[i][0]+1 << " " << answers[i][1]+1 << " " << answers[i][2]+1 << "\n";
  }
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
