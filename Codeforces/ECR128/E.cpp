#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<string> G(2);
  cin >> G[0];
  cin >> G[1];
  vector<ll> DPforward1(n+1,numeric_limits<ll>::max());
  vector<ll> DPforward2(n+1,numeric_limits<ll>::max());
  vector<bool> forward_founds(n+1,false);
  vector<ll> DPbackward1(n+1,numeric_limits<ll>::max());
  vector<ll> DPbackward2(n+1,numeric_limits<ll>::max());
  vector<bool> backward_founds(n+1,false);

  DPforward1[0] = 0;
  DPforward2[0] = 0;
  DPbackward1[n] = 0;
  DPbackward2[n] = 0;
  bool forward_found = false;
  bool backward_found = false;
  for(int i = 0;i < n;i++){
    if (forward_found){
      if(G[1][i] == '*') {
        DPforward1[i+1] = min(DPforward1[i+1],DPforward1[i] + 2);
        DPforward1[i+1] = min(DPforward1[i+1],DPforward2[i] + 2);
      }else{
        DPforward1[i+1] = min(DPforward1[i+1],DPforward1[i] + 1);
        DPforward1[i+1] = min(DPforward1[i+1],DPforward2[i] + 2);
      }
      if(G[0][i] == '*') {
        DPforward2[i+1] = min(DPforward2[i+1],DPforward2[i] + 2);
        DPforward2[i+1] = min(DPforward2[i+1],DPforward1[i] + 2);
      }else{
        DPforward2[i+1] = min(DPforward2[i+1],DPforward2[i] + 1);
        DPforward2[i+1] = min(DPforward2[i+1],DPforward1[i] + 2);
      }
    }else{
      if(G[1][i] == '*') {
        forward_found = true;
        DPforward1[i+1] = 1;
      }else{
        DPforward1[i+1] = 0;
      }
      if(G[0][i] == '*') {
        forward_found = true;
        DPforward2[i+1] = 1;
      }else{
        DPforward2[i+1] = 0;
      }
    }
    forward_founds[i+1] = forward_found;
  }

for(int i = n-1;i >= 0;i--){
    if (backward_found){
      if(G[1][i] == '*') {
        DPbackward1[i] = min(DPbackward1[i],DPbackward1[i+1] + 2);
        DPbackward1[i] = min(DPbackward1[i],DPbackward2[i+1] + 2);
      }else{
        DPbackward1[i] = min(DPbackward1[i],DPbackward1[i+1] + 1);
        DPbackward1[i] = min(DPbackward1[i],DPbackward2[i+1] + 2);
      }
      if(G[0][i] == '*') {
        DPbackward2[i] = min(DPbackward2[i],DPbackward2[i+1] + 2);
        DPbackward2[i] = min(DPbackward2[i],DPbackward1[i+1] + 2);
      }else{
        DPbackward2[i] = min(DPbackward2[i],DPbackward2[i+1] + 1);
        DPbackward2[i] = min(DPbackward2[i],DPbackward1[i+1] + 2);
      }
    }else{
      if(G[1][i] == '*') {
        backward_found = true;
        DPbackward1[i] = 1;
      }else{
        DPbackward1[i] = 0;
      }
      if(G[0][i] == '*') {
        backward_found = true;
        DPbackward2[i] = 1;
      }else{
        DPbackward2[i] = 0;
      }
    }
    backward_founds[i] = backward_found;
  }
  // for(int i = 0; i < n;i++){
  //   cout << DPforward1[i+1];
  // }
  // cout << endl;
  // for(int i = 0; i < n;i++){
  //   cout << DPforward2[i+1];
  // }
  // cout << endl;
  // for(int i = 0; i < n;i++){
  //   cout << DPbackward1[i];
  // }

  // cout << endl;
  // for(int i = 0; i < n;i++){
  //   cout << DPbackward2[i];
  // }
  // cout << endl;
  // cout << 2 * true + 3<< endl;
  // cout << 2 * false << endl;
  ll ans = numeric_limits<ll>::max();
  for(int i = 0; i < n;i++){
    cout << i << ":" << endl;
    cout << DPforward1[i] + DPbackward1[i+1] + forward_founds[i] +  backward_founds[i+1] + 1 << endl;
    cout << DPforward1[i] + DPbackward2[i+1] + max(0ll + forward_founds[i] + 2*backward_founds[i+1],1ll) << endl;
    cout << DPforward2[i] + DPbackward1[i+1] + max(0ll + 2*forward_founds[i] + backward_founds[i+1],1ll) << endl;;
    cout << DPforward2[i] + DPbackward2[i+1] + max(0ll + 2*forward_founds[i] + 2*backward_founds[i+1],1ll) << endl;
    cout <<  DPforward1[i] + DPbackward1[i+1] + max(0ll + 2*forward_founds[i] + 2*backward_founds[i+1],1ll) << endl;
    cout <<  DPforward1[i] + DPbackward2[i+1] + max(0ll + 2*forward_founds[i] + backward_founds[i+1],1ll) << endl;
    cout <<  DPforward2[i] + DPbackward1[i+1] + max(0ll + forward_founds[i] + 2*backward_founds[i+1],1ll) << endl;
    cout <<  DPforward2[i] + DPbackward2[i+1] + forward_founds[i] + backward_founds[i+1] + 1 << endl;
    if(G[1][i] == '*') {
      ans = min(ans, DPforward1[i] + DPbackward1[i+1] + forward_founds[i] +  backward_founds[i+1] + 1);
      ans = min(ans, DPforward1[i] + DPbackward2[i+1] + max(0ll + forward_founds[i] + 2*backward_founds[i+1],1ll));
      ans = min(ans, DPforward2[i] + DPbackward1[i+1] + max(0ll + 2*forward_founds[i] + backward_founds[i+1],1ll));
      ans = min(ans, DPforward2[i] + DPbackward2[i+1] + max(0ll + 2*forward_founds[i] + 2*backward_founds[i+1],1ll));
    }else{
      ans = min(ans, DPforward1[i] + forward_founds[i] + DPbackward1[i+1] + backward_founds[i+1]);
      ans = min(ans, DPforward1[i] + forward_founds[i] + DPbackward2[i+1] + 2*backward_founds[i+1]);
      ans = min(ans, DPforward2[i] + 2*forward_founds[i] + DPbackward1[i+1] + backward_founds[i+1]);
      ans = min(ans, DPforward2[i] + 2*forward_founds[i] + DPbackward2[i+1] + 2*backward_founds[i+1]);
    }
    if(G[0][i] == '*') {
      ans = min(ans, DPforward1[i] + DPbackward1[i+1] + max(0ll + 2*forward_founds[i] + 2*backward_founds[i+1],1ll));
      ans = min(ans, DPforward1[i] + DPbackward2[i+1] + max(0ll + 2*forward_founds[i] + backward_founds[i+1],1ll));
      ans = min(ans, DPforward2[i] + DPbackward1[i+1] + max(0ll + forward_founds[i] + 2*backward_founds[i+1],1ll));
      ans = min(ans, DPforward2[i] + DPbackward2[i+1] + forward_founds[i] + backward_founds[i+1] + 1);
    }else{
      ans = min(ans, DPforward1[i] + 2*forward_founds[i] + DPbackward1[i+1] + 2*backward_founds[i+1]);
      ans = min(ans, DPforward1[i] + 2*forward_founds[i] + DPbackward2[i+1] + backward_founds[i+1]);
      ans = min(ans, DPforward2[i] + forward_founds[i] + DPbackward1[i+1] + 2*backward_founds[i+1]);
      ans = min(ans, DPforward2[i] + forward_founds[i] + DPbackward2[i+1] + backward_founds[i+1]);
    }
    // cout << ans << endl;
  }
  cout << ans << "\n";
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