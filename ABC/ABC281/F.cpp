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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

ll dfs(ll k,vector<ll> &A){
  if (k < 0 || A.empty()){
    return 0;
  }
  vector<ll> ones;
  vector<ll> zeros;
  for(auto a:A){
    if (a & 1ll<<k){
      ones.push_back(a);
    }else{
      zeros.push_back(a);
    }
  }
  if (ones.size() == 0){
    return dfs(k-1,zeros);
  }else if(zeros.size() == 0){
    return dfs(k-1,ones);
  }else{
    ll mask = (1ll<<(k+1))-1;
    return min( (1ll<<k | dfs(k-1,ones)) & mask, (1ll<<k |dfs(k-1,zeros)) & mask);
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
  cout << dfs(30,A) << endl;
  return 0;
}
