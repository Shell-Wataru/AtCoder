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
int BASE_NUM = 998244353;

ll lte_count(vector<ll> &A,ll from,ll a,ll &first_index,ll &last_index){
  ll count = 0;
  for(int i = from;i < A.size();i++){
    if(last_index + 1 < i && A[i] <= a){
      count++;
      last_index = i;
      if (first_index == -1){
        first_index = i;
      }
    }
  }
  return count;
}

bool is_clear(vector<ll> &A,ll k,ll count,ll first_index,ll last_index){
    if (first_index == 0 && last_index == A.size() - 1){
    if (2 * count - 1>= k ){
      return true;
    }else{
      return false;
    }
  }else if (first_index == 0 || last_index == A.size() - 1){
    if (2 * count >= k ){
      return true;
    }else{
      return false;
    }
  }else{
    if (2 * count + 1 >= k ){
      return true;
    }else{
      return false;
    }
  }
}

ll min_max_value(vector<ll> &A ,ll k,ll l,ll r){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll last_index1 = -2;
  ll first_index1 = -1;
  ll count1 = lte_count(A,0,center,first_index1,last_index1);
  ll last_index2 = -2;
  ll first_index2 = -1;
  ll count2 = lte_count(A,1,center,first_index2,last_index2);
  if (is_clear(A,k,count1,first_index1,last_index1) || is_clear(A,k,count2,first_index2,last_index2)){
    return min_max_value(A,k,l,center);
  }else{
    return min_max_value(A,k,center,r);
  }
}
int solve()
{
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);

  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);

  }

  cout << min_max_value(A,k,0,1e9) << endl;

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
  // cout << flush;
  return 0;
}