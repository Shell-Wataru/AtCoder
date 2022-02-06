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


int last_max_point(ll l,ll r,vector<ll> &use_total, ll K){
  if (l+1 == r){
    return l;
  }
  ll center = (l+r)/2;
  if (use_total[center] > K){
    return last_max_point(l,center,use_total,K);
  }else{
    return last_max_point(center,r,use_total,K);
  }
}
int main()
{
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.rbegin(),A.rend());
  A.push_back(0);
  vector<ll> point_total(N+1,0);
  vector<ll> use_total(N+1,0);
  for(int i = 1;i < N+1;i++){
    point_total[i] = point_total[i-1] + i * (A[i-1] + A[i] + 1)* (A[i-1] - A[i])/2;
    // cout << point_total[i] << ",";
  }
  // cout << endl;
  for(int i = 1;i < N+1;i++){
    use_total[i] = use_total[i-1] + i * (A[i-1] - A[i]);
  }
  // cout << use_total.back() << endl;
  if(K >= use_total.back()){
    cout << point_total.back() << endl;
  }else{
    ll same_index = last_max_point(0,N,use_total,K);
    ll remainK =  K - use_total[same_index];
    ll point = point_total[same_index];
    ll all = remainK/(same_index+1);
    ll amari = remainK % (same_index+1);
    // cout << point << endl;
    // cout << all << endl;
    // cout << amari << endl;
    // cout << remainK << endl;
    point += (same_index+1) * (A[same_index] + A[same_index] - all + 1)* all/2;
    point += (A[same_index] - all) * amari;
    cout << point << endl;
  }
  return 0;
}
