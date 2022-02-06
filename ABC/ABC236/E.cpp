#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

double max_mean(vector<ll> &A){
  ll total = 0;
  ll choosed_count = 0;
  priority_queue<pair<ll,ll>,greater<pair<ll,ll>>,vector<pair<ll,ll>>> q;
  vector<bool> choosed(A.size(),true);
}

ll max_median(vector<ll> &A,ll l ,ll r){
  if (l+1 == r){
    return l;
  }
  ll center = (l+r)/2;
  // cout << center << endl;
  vector<bool> covered(A.size(),false);
  covered[0] = true;
  priority_queue<pair<ll,ll>> q;
  for(int i = 0;i < A.size();i++){
    q.push({A[i],i});
  }
  ll covered_count = 0;
  ll gte_count = 0;
  while(!q.empty() && q.top().first >= center){
    gte_count++;
    auto p = q.top();
    q.pop();
    if (!covered[p.second]){
      covered[p.second] = true;
      covered_count++;
    }
    if (p.second + 1 < A.size() && !covered[p.second+1]){
      covered[p.second+1] = true;
      covered_count++;
    }
  }
  ll lt_count = 0;
  for(int i = 1;i < A.size();i++){
    if (!covered[i]){
      lt_count++;
      covered[i] = true;
      if (i+1 < A.size()){
        covered[i+1] = true;
      }
    }
  }
  if(lt_count < gte_count){
    return max_median(A,center,r);
  }else{
    return max_median(A,l,center);
  }
}
int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  cout << "!!" << endl;
  cout << max_median(A,0,numeric_limits<ll>::max()/2) << endl;
  return 0;
}
