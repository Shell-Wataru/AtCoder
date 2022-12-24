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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int solve()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N;i++){
    cin >> B[i];
  }
  vector<ll> a_count(N+1);
  vector<ll> b_count(N+1);
  vector<ll> a_sum(N+1);
  vector<ll> b_sum(N+1);
  vector<ll> a_product(N+1);
  vector<ll> b_product(N+1);
  a_count[0] = 0;
  b_count[0] = 0;
  a_sum[0] = 0;
  b_sum[0] = 0;
  a_product[0] = 1;
  b_product[0] = 1;
  unordered_set<ll> sa;
  unordered_set<ll> sb;
  for(int i = 0;i < N;i++){
    if (sa.find(A[i]) == sa.end()){
      a_count[i+1] = a_count[i]+1;
      a_sum[i+1] = a_sum[i]+A[i];
      a_product[i+1] = a_product[i]*A[i];
      sa.insert(A[i]);
    }else{
      a_count[i+1] = a_count[i];
      a_sum[i+1] = a_sum[i];
      a_product[i+1] = a_product[i];
    }
    if (sb.find(B[i]) == sb.end()){
      b_count[i+1] = b_count[i]+1;
      b_sum[i+1] = b_sum[i]+B[i];
      b_product[i+1] = b_product[i]*B[i];
      sb.insert(B[i]);
    }else{
      b_count[i+1] = b_count[i];
      b_sum[i+1] = b_sum[i];
      b_product[i+1] = b_product[i];
    }
  }
  ll Q;
  cin >> Q;
  while(Q--){
    ll x,y;
    cin >> x >> y;
    if (a_count[x] == b_count[y] && a_sum[x] == b_sum[y] && a_product[x] == b_product[y]){
      cout << "Yes" << "\n";
    }else{
      cout << "No" << "\n";
    }
  }
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
