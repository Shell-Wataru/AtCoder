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

double max_mean(vector<ll> &A,double l, double r){
  if (abs(l-r) < 1e-5){
    return (l+r)/2;
  }
  // cout << l << "~" << r << endl;
  double center = (l+r)/2;
  ll N = A.size();
  vector<double> DP(N+2,numeric_limits<double>::lowest());
  DP[0] = 0;
  DP[1] = 0;
  for(int i = 0;i < N;i++){
    DP[i+2] = max(DP[i+2], DP[i+1]+ A[i] - center);
    DP[i+2] = max(DP[i+2], DP[i]+ A[i] - center);
  }
  if (max(DP[N+1],DP[N]) >= 0){
    return max_mean(A,center,r);
  }else{
    return max_mean(A,l,center);
  }
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
  cout << fixed << setprecision(12) << max_mean(A,0,1e15) << endl;
  cout << fixed << setprecision(12)<< max_median(A,0,1e15) << endl;
  return 0;
}
