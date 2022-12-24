#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

char query1(ll i){
  cout << "? 1 " << i+1 << endl;
  char ret;
  cin >> ret;
  return ret;
}

ll query2(ll l,ll r){
  cout << "? 2 " << l+1 << " " << r+1 << endl;
  ll ret;
  cin >> ret;
  return ret;
}

ll nth_char(string &ans,ll current,ll l, ll r){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  unordered_set<char> ss;
  ll from;
  for(int i = current -1;i>=0;i--){
    ss.insert(ans[i]);
    if (ss.size() == center){
      from = i;
      break;
    }
  }
  ll distincts = query2(from,current);
  if (distincts == center){
    return nth_char(ans,current,l,center);
  }else{
    return nth_char(ans,current,center,r);
  }
}

int solve()
{
  ll n, x;
  scanf("%lld", &n);
  string ans(n,'?');
  for(int i = 0;i < n;i++){
    unordered_set<char> ss1;
    for(int j = 0;j < i;j++){
      ss1.insert(ans[j]);
    }
    ll ret = nth_char(ans,i,0,ss1.size()+1);
    if (ret == ss1.size()+1){
      char c = query1(i);
      ans[i] = c;
    }else{
      unordered_set<char> ss2;
      for(int j = i-1;j >=0;j--){
        ss2.insert(ans[j]);
        if (ss2.size() == ret){
          ans[i] = ans[j];
          break;
        }
      }
    }
  }
  cout << "! " << ans << endl;
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}