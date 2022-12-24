#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

// void print(priority_queue<pair<ll,ll>> &q_smaller,priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> &q_bigger){
//   cout << "smaller:";
//   for(auto p:q_smaller){
//     cout << p.first << ","
//   }
//   cout << endl;
//   cout << "bigger:";
//   for(auto p:q_bigger){
//     cout << p.first << ","
//   }
//   cout << endl;
// }
int main()
{
  ll N,M,K;
  cin >> N >> M >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  priority_queue<pair<ll,ll>> q_smaller;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q_bigger;
  ll total = 0;
  for(int i = 0;i < M;i++){
    q_smaller.push({A[i],i});
    total += A[i];
    if (q_smaller.size() > K){
      auto p = q_smaller.top();
      q_smaller.pop();
      q_bigger.push(p);
      total -= p.first;
    }
  }
  // cout << "size:" << q_smaller.size() << endl;
  // print(q_smaller,q_bigger);
  cout << total;
  ll others = 0;
  ll other_total = 0;
  for(int i = M;i< N;i++){
    pair<ll,ll> removed = {A[i-M],i-M};
    if (removed <= q_smaller.top()){
      // cout << "removed!!" << endl;
      others++;
      other_total += A[i-M];
    }

    q_bigger.push({A[i],i});
    // cout << "size:" << q_smaller.size() << endl;
    while(!q_bigger.empty() && (q_bigger.top() < q_smaller.top() || q_smaller.size() < K+others) ){
      auto p = q_bigger.top();
      q_bigger.pop();
      if (p.second < i-M){
        continue;
      }
      // cout << "added:"  << p.first << endl;
      q_smaller.push(p);
      total += p.first;
    }

    while(q_smaller.size() > K+others){
      // cout << "!" << endl;
      auto p = q_smaller.top();
      q_smaller.pop();
      if (p.second < i-M){
        others--;
        other_total -= p.first;
        total -= p.first;
      }else{
        q_bigger.push(p);
        total -= p.first;
      }
    }
    cout << " " << total - other_total;
    // cout << endl;
  }
  cout << endl;
  return 0;
}